#ifndef LABELS_H
#define	LABELS_H

#include <iostream>
#include "instruction.h"
using namespace std;

class Labels 
{
  Instruction addresses[100];
  int count;
public:
  Labels();
  int find(const char*) const;
  friend istream& operator>> (istream &is, Labels &labels);
}; // class Labels 

#endif	// LABELS_H

