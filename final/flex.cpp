#include<iostream>
#include<cstring>
#include<fstream>
#include "flex.h"

using namespace std;

Flex::Flex()
{
  current = 1;
  str_ = new char[current+1];
  strcpy(str_, " ");
}
Flex::Flex(const char * x)
{
  current = strlen(x);
  str_ = new char[current+1];
  strcpy(str_, x);
}
Flex::~Flex()
{
  delete [] str_;
}
ostream& operator<<(ostream& s, const Flex& x)
{
  s << "*";
  s << x.str_;
  s << "*";

  return s;
}
void Flex::cat(const Flex& x)
{
  int newsize = current + strlen(x.str_);
  char* temp = new char[newsize + 1];
  strcpy(temp, str_);
  for(int i=0; i <= x.current; i++)
    temp[current+i] = x.str_[i];
  delete [] str_;
  str_ = temp;
  current = newsize;
}
