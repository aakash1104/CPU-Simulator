#ifndef DECODER_H
#define	DECODER_H
// Author: Sean Davis

#include "instruction.h"
#include "registers.h"
#include "labels.h"

class Decoder
{
  char opcode[20];
  int *operand1;
  int *operand2;
  void addl(Registers *registers);
  void andl(Registers *registers);
  void call(Registers *registers, int memory[1001]) const;
  void cmpl(Registers *registers) const;
  void incl(Registers *registers);
  void jg(Registers *registers) const;
  void jle(Registers *registers) const;
  void jmp(Registers *registers) const;  
  void leal(const Instruction *instruction, const Registers *registers);
  void leave(Registers *registers, const int memory[1001]) const;
  void movl();
  void pushl(Registers *registers, int memory[1001]) const;
  void ret(Registers *registers, const int memory[1001]) const;
  void sall(Registers *registers);
  void subl(Registers *registers);
public:
  void execute(const Instruction *instruction, Registers *registers, 
               int memory[1001]);
  void parse(const Instruction *instruction, Registers *registers, 
             int memory[1001], const Labels &labels);
}; // class Decoder;



#endif	// DECODER_H 

