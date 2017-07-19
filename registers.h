#ifndef REGISTERS_H
#define	REGISTERS_H

#include <iostream>
#include "labels.h"
using namespace std;


class Registers
{
  int regs[6];
  int stringToRegNum(const char *regString) const;
  static const int ZF = 0x40;
  static const int SF = 0x80;
public:
  typedef enum {eax, ebp, esp, eip, edx, flags} RegName;
  Registers();
  int* address(char *ptr, int memory[], const Labels &labels);
  int get(Registers::RegName regName) const;
  bool getSF() const;
  bool getZF() const;

  int operator+= (int change);
  friend ostream& operator<< (ostream &os, const Registers &registers);
  int* scaledIndexMode(char *operand, int memory[]) const;
  void set(Registers::RegName regName, int value);
  void setFlags(int value);
}; // class Registers

#endif	// REGISTERS_H
