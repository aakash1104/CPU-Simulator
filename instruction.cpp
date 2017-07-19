// Author: Sean Davis
#include "instruction.h"
#include <iostream>
#include <cstring>



Instruction::Instruction() : info(NULL)
{
}  // Instruction()


Instruction::~Instruction()
{
  if(info)
    delete [] info;
}  // ~Instruction
  

int Instruction::getAddress() const
{
  return address;
} // get()


const char* Instruction::getInfo() const
{
  return info;
} // get()


void Instruction::setAddress(int addr)
{
  address = addr;
} // setAddress()
  

void Instruction::setInfo(const char* information)
{
  info = new char[strlen(information) + 1];
  strcpy(info, information);
} // setInfo()
