#ifndef INSTRUCTION_H
#define	INSTRUCTION_H

class Instruction
{
  int address;
  char *info;
public:
  Instruction();
  ~Instruction();
  int getAddress() const;
  const char* getInfo() const;
  void setAddress(int addr);
  void setInfo(const char* information);

}; //class Instruction

#endif	// INSTRUCTION_H
