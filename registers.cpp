// Author: Sean Davis
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "registers.h"
using namespace std;

Registers::Registers()
{
  regs[esp] = 1000;
  regs[ebp] = 996;
  regs[eip] = 100;
  regs[eax] = 0;
  regs[edx] = 0;
  regs[flags] = 0xC0;
}  // Registers()


int* Registers::address(char *operand, int memory[], const Labels &labels)
{
  static int value;
 
  char *ptr;
  int regNum, index;

  if(operand == NULL)
    return NULL;

  if(operand[0] == '$') // immediate mode
  {
    value = atoi(&operand[1]);
    return &value;
  } // if immediate mode
  
  if(operand[0] == '.' || operand[0] == '_')  // label
  {
    value = labels.find(operand);
    return &value;
  }  // if operand is a label
  
  if(strchr(operand, ',') && strchr(operand, ',') != strrchr(operand, ','))
    return scaledIndexMode(operand, memory);

  regNum = stringToRegNum(operand);
  ptr = strchr(operand, '(');

  if(ptr) // some form of indirect addressing
  {
    *ptr = '\0';  // terminate operand string at first '('
    index = atoi(operand);  // will return 0 if no number there!
    return  &memory[regs[regNum] + index];
  } // if ptr
  else  // direct addressing
    return &(regs[regNum]);
} // address ()


int Registers::get(Registers::RegName regName) const
{
  if(regName < eax || regName > eip)
    return 0;
  
  return regs[regName];
}  // get()


bool Registers::getSF() const
{
  return regs[flags] & SF;
}  // getSF()


bool Registers::getZF() const
{
  return regs[flags] & ZF;
}  // getZF()


int Registers::operator+= (int change)
{
  regs[esp] += change;
  return regs[esp];
}  // operator+=()


ostream& operator<< (ostream &os, const Registers &registers)
{
  os << " eip: " << right << setw(3) << registers.regs[Registers::eip] 
    << " eax: " << setw(3) << registers.regs[Registers::eax] 
    << " ebp: " << setw(3) << registers.regs[Registers::ebp] 
    << " esp: " << setw(3) << registers.regs[Registers::esp] 
    << " edx: " << setw(3) << registers.regs[Registers::edx] 
    << " flags: " << setw(3) << registers.regs[Registers::flags] << endl;
  
  return os;
}  // operator<<()


int* Registers::scaledIndexMode(char *operand, int memory[]) const
{
  int offset, regNum1, regNum2, size;
  char *ptr = operand, *ptr2;
  
  while(*ptr != '(')
    ptr++;
  
  *ptr = '\0';
  offset = atoi(operand);
  ptr2 = ++ptr;
  
  while(*ptr != ',')
    ptr++;
  
  *ptr = '\0';
  regNum1 = stringToRegNum(ptr2);
  ptr2 = ++ptr;
  
  while(*ptr != ',')
    ptr++;
  
  *ptr = '\0';
  regNum2 = stringToRegNum(ptr2);
  size = atoi(++ptr);
  return &memory[regs[regNum1] + size * regs[regNum2] + offset];
} // scaledIndexMode()


int Registers::stringToRegNum(const char *regString) const
{
  char regNames[4][7] = {"eax", "ebp", "esp", "eip"};
  int regNum;
  
  for(regNum = eax; regNum <= eip; regNum++)
    if(strstr(regString, regNames[regNum]))
      break;
  
  return regNum;
} // stringToRegNum()


void Registers::set(Registers::RegName regName, int value)
{
  if(regName >= eax && regName <= eip)
    regs[regName] = value;
} // set()


void Registers::setFlags(int value)
{
  if(value == 0)
    regs[flags] |= ZF;  // sets ZF flag
  else // value != 0
    regs[flags] &= ~ZF;  // clears ZF flag
  
  if(value < 0)
    regs[flags] |= SF;  // sets SF flag
  else  // value >= 0
    regs[flags] &= ~SF;  // clears SF flag
}  // setFlags()
