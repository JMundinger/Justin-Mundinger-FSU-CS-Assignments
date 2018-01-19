#include<iostream>
#include<iomanip>
#include "bitarray.h"

using namespace std;

BitArray::BitArray(unsigned int n)
{

}
BitArray::BitArray(const BitArray & x)
{

}
BitArray::~BitArray()
{
  delete [] barray;
}

