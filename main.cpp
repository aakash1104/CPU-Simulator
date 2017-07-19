// Author: Sean Davis
#include <fstream>
#include <iomanip>
#include "registers.h"
#include "decoder.h"
#include "reader.h"
#include "instruction.h"
#include "labels.h"
using namespace std;


int main(int argc, char* argv[])
{
  Reader reader;
  Decoder decoder;
  Registers registers;
  Instruction instruction;
  Labels labels;
  int memory [1001];
  memory[1000] = 0;
  ifstream inf(argv[1]);
  inf >> reader;
  inf.clear();
  inf.seekg(0);
  inf >> labels;
  registers.set(Registers::eip, labels.find("main"));
  
  while(registers.get(Registers::eip) != 0)
  {
    reader.fetch(&instruction, &registers);
    decoder.parse(&instruction, &registers, memory, labels);
    decoder.execute(&instruction, &registers, memory);
    cout << left << setw(20) << instruction.getInfo() << registers;
  } // while eip not zero
  
 

  return 0;
}  // main()

