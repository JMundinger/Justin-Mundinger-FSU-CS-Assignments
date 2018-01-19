#include <iostream>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <cstring>
#include "myint.h"

using namespace std;

int C2I(char c)
// converts character into integer (returns -1 for error)
{
   if (c < '0' || c > '9')	return -1;	// error
   return (c - '0');				// success
}

char I2C(int x)
// converts single digit integer into character (returns '\0' for error)
{
   if (x < 0 || x > 9)		return '\0';	// error
   return (static_cast<char>(x) + '0'); 	// success
}

// Add in operator overload and member function definitions 

MyInt::MyInt(int n)
{
  if(n <= 0)
  {
    size_ = 1;
    maxsize_ = 5;
    digits_ = new unsigned int[maxsize_];
    digits_[0] = 0;
  }
  else
  {
    size_ = log10(n) + 1;
    maxsize_ = size_ + 5;
    digits_ = new unsigned int[maxsize_];
    int temp = size_ - 1;
    int j = 10;
    for(int i=0; i < size_; i++)
    {
      int p = pow(10, temp);
      digits_[i] = n / p;
      n %= p;
      temp--;
    }
  }
}
MyInt::~MyInt()
{
  delete [] digits_;
}
MyInt::MyInt(const char * c)
{
  for(int i = 0; i < strlen(c); i++)
  {
    if(IsNumber(c[i])==true)
    {
      size_ = strlen(c);
      maxsize_ = size_ + 5;
      digits_ = new unsigned int[maxsize_];
      for(int j =0; j < size_; j++)
        digits_[j] = C2I(c[j]);
    }
    else
    {
      size_ = 1;
      maxsize_ = 5;
      digits_ = new unsigned int[maxsize_];
      digits_[0] = 0;
      break;
    }
  }
}
MyInt::MyInt(const MyInt& m)
{
  maxsize_ = m.maxsize_;
  size_ = m.size_;
  digits_ = new unsigned int[maxsize_];
  for(int i=0; i<size_; i++)
    digits_[i] = m.digits_[i];
}
MyInt& MyInt::operator= (const MyInt & m)
{
  if(this != &m)
  {
    delete [] digits_;
    maxsize_ = m.maxsize_;
    size_ = m.size_;
    digits_ = new unsigned int[maxsize_];
    for(int i=0; i < size_; i++)
      digits_[i] = m.digits_[i];
  }
  return *this;
}
bool MyInt::IsNumber(char x)
{
  if(x=='0'||x=='1'||x=='2'||x=='3'||x=='4'||x=='5'||x=='6'||x=='7'||x=='8'||x=='9')
    return true;
  else
    return false;
}
int MyInt::GetSize()
{
  return size_;
}
void MyInt::Set(const char * x, MyInt y)
{
  for(int i=0; i < y.size_; i++)
    y.digits_[i] = 0;

  for(int i=0; i < strlen(x); i++)
  {
    if(y.IsNumber(x[i])==true)
    {
      y.digits_[i] = C2I(x[i]);
      y.size_++;
      if(y.size_==y.maxsize_)
        y.Grow();
    }
  }
}
void MyInt::Grow()
{
  maxsize_ = size_ + 5;
  unsigned int* newdigits = new unsigned int[maxsize_];
  for(int i=0; i < size_; i++)
    newdigits[i] = digits_[i];
  delete digits_;
  digits_ = newdigits;
}
istream& operator>> (istream & s, MyInt & x)
{
  x.size_=0;
  x.maxsize_=5;
  int i=0;
  
  while(s.peek() != '\n')
  {
    if(x.IsNumber(s.peek())==true)
    {
      x.digits_[i] = C2I(s.get());
      x.size_++;
      if(x.size_==x.maxsize_)
        x.Grow();
      i++;
    }
    else 
     break;
  }
  //x.Set(input, x);
  return s;
}
ostream& operator<< (ostream & s, const MyInt & x)
{
  for(int i = 0; i < x.size_; i++)
    s << x.digits_[i];
  return s;
}
bool operator>(const MyInt & x, const MyInt & y)
{
  if(x.size_ > y.size_)
    return true;
  if(x.size_ == y.size_)
  {
    for(int i=0; i < x.size_; i++)
    {
      if(x.digits_[i] > y.digits_[i])
        return true;
    }
  }
  else
    return false;
}
bool operator<(const MyInt & x, const MyInt & y)
{
   if(x.size_ < y.size_)
    return true;
  if(x.size_ == y.size_)
  {
    for(int i=0; i < x.size_; i++)
    {
      if(x.digits_[i] < y.digits_[i])
        return true;
    }
  }
  else
    return false;
}
bool operator>=(const MyInt & x, const MyInt & y)
{
 if(x.size_ > y.size_)
    return true;
  if(x.size_ == y.size_)
  {
    for(int i=0; i < x.size_; i++)
    {
      if(x.digits_[i] >= y.digits_[i])
        return true;
    }
  }
  else
    return false;
}
bool operator<=(const MyInt & x, const MyInt & y)
{
  if(x.size_ < y.size_)
    return true;
  if(x.size_ == y.size_)
  {
    for(int i=0; i < x.size_; i++)
    {
      if(x.digits_[i] <= y.digits_[i])
        return true;
    }
  }
  else
    return false;
}
bool operator!=(const MyInt & x, const MyInt & y)
{
  if(x.size_ != y.size_)
    return true;
  if(x.size_ == y.size_)
  {
    for(int i=0; i < x.size_; i++)
    {
      if(x.digits_[i] != y.digits_[i])
        return true;
    }
  }
  else
    return false;
}
bool operator==(const MyInt & x, const MyInt & y)
{
  if(x.size_ == y.size_)
  {
    for(int i=0; i < x.size_; i++)
    {
      if(x.digits_[i] == y.digits_[i])
        return true;
    }
  }
  else
    return false;
}
void MyInt::Reverse()
{
 int s;
  for(int i = 0; i < size_/2; ++i)
  {
    s = digits_[size_-i-1];
    digits_[size_-i-1] = digits_[i];
    digits_[i] = s;
  }
}
MyInt& MyInt::operator++()
{
  digits_[size_-1] += 1;
  return *this;
}
MyInt MyInt::operator++(int)
{
  MyInt temp = *this;
  digits_[size_-1] += 1;
  return temp;
}
MyInt operator+ (const MyInt & x, const MyInt & y)
{
  MyInt z;

  int size1 = x.size_ - 1;
  int size2 = y.size_ - 1;
  int i = 0;
  int carry = 0, temp;
  while(size1 >= 0 || size2 >= 0)
  {
    int a = x.digits_[size1];
    int b = y.digits_[size2];
    if(size1 < 0)
    a = 0;
    if(size2 < 0)
    b = 0;
    temp = a + b + carry;
    carry = 0;
    if(temp > 9)
    {
      temp %= 10;
      z.digits_[i] = temp;
      carry++;
    }
    else
    {
      z.digits_[i] = temp;
    }
    i++;
    z.size_ = i;
    if(z.digits_[z.size_-1] > 9)
    {
      z.size_++;
      z.digits_[z.size_-1] = 1;
    }
    size1--;
    size2--;
    if(z.size_ == z.maxsize_)
      z.Grow();
  }
  z.Reverse();
  return z;
}
MyInt operator* (const MyInt & x, const MyInt & y)
{
  MyInt z;                          //this function only works with certain 
  int pnum = 0, largest = 0;        //numbers for some reason as of now
  int carry = 0, max;
  if(x.size_ < y.size_)
  {
    pnum = x.size_;
    largest = y.size_;
    max = y.maxsize_;
  }
  else if(y.size_ <= x.size_)
  {
    pnum = y.size_;
    largest = x.size_;
    max = x.maxsize_;
  }
  MyInt * p = new MyInt[pnum];
  int temp = largest + 1;
  for(int i=0; i<pnum; i++)
  {
    p[i].size_= temp;
    temp++;
  }
  int m = largest -1;
  int s = pnum -1;
  int d;
  for(int i=0; i < pnum; i++)
  {
    for(int j=0; j < p[i].size_; j++)
    {
      if(j < i)
        d = 0;
      else
      {
        if(x.size_ >= y.size_)
        d = x.digits_[m] * y.digits_[s]  + carry;
        else if(y.size_ > x.size_)
        d = x.digits_[s] * y.digits_[m] + carry;
      }
      carry = 0;

      if(d > 9)
      {
        carry = d / 10;
        d %= (carry * 10);
        p[i].digits_[j] = d;
       if(m==0)
       {
        p[i].digits_[j+1] = carry;
        p[i].size_++;
       }
      }
      else
        p[i].digits_[j] = d;
      if(j >= i)
        m--;
      if(p[i].size_==p[i].maxsize_)
      p[i].Grow();
    }
    s--;
    p[i].Reverse();
    m = largest - 1;
  }
  for(int i=0; i < pnum; i++)
  {
    z = z + p[i];
    if(z.size_==z.maxsize_)
      z.Grow();
  }
delete [] p;

  return z;

}




