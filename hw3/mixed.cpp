#include<iostream>
#include<iomanip>
#include "mixed.h"
using namespace std;

istream& operator>> (istream& s, Mixed& m)
{
  char divsign;
  s >> m.whole_ >> m.numerator_  >> divsign >> m.denominator_;
  m.Set(m.whole_, m.numerator_, m.denominator_);
  return s;
}
ostream& operator<< (ostream& s, const Mixed& m)
{
  if(m.whole_==0)
  {
    if(m.numerator_==0)
      s << m.whole_;
    else
      s << m.numerator_ <<"/"<< m.denominator_;
  }
  if(m.whole_!=0 && m.numerator_!=0)
    s << m.whole_ <<" "<< m.numerator_ <<"/"<< m.denominator_;
  if(m.whole_!=0 && m.numerator_==0)
    s << m.whole_;
return s;
}
bool operator<(const Mixed& x, const Mixed& y)
{
  if(x.whole_ < y.whole_)
    return true;
  if(x.whole_ == y.whole_ && 
(x.numerator_/x.denominator_)<(y.numerator_/y.denominator_))
    return true;
  else
    return false;
}
bool operator>(const Mixed& x, const Mixed& y)
{
  if(x.whole_ > y.whole_)
    return true;
  if(x.whole_ ==y.whole_ &&(x.numerator_/x.denominator_) 
>(y.numerator_/y.denominator_))
    return true;
  else
    return false;
}
bool operator<=(const Mixed& x, const Mixed& y)
{
  if(x.whole_ <= y.whole_)
    return true;
  
if(x.whole_==y.whole_&& 
(x.numerator_/x.denominator_)<=(y.numerator_/y.denominator_))
  return true;
else
  return false;
}
bool operator>=(const Mixed& x, const Mixed& y)
{
  if(x.whole_ >= y.whole_)
    return true;
  if(x.whole_==y.whole_&& 
(x.numerator_/x.denominator_)>=(y.numerator_/y.denominator_))
  return true;
else
  return false;
}
bool operator==(const Mixed& x, const Mixed& y)
{
  if(x.whole_==y.whole_ && x.numerator_==y.numerator_ && 
x.denominator_==y.denominator_)
  return true;
  else
  return false;
}
bool operator!=(const Mixed& x, const Mixed& y)
{
  if(x.whole_!=y.whole_ || x.numerator_!=y.numerator_)
  return true;
  else
    return false;
}
Mixed operator+(const Mixed& x, const Mixed& y)
{
  Mixed result;
  result.whole_=x.whole_ + y.whole_;
  result.denominator_=x.denominator_ * y.denominator_;
  result.numerator_ = (x.numerator_ * y.denominator_)+ (y.numerator_ 
* x.denominator_);
  result.Simplify();
  return result;
}
Mixed operator-(const Mixed& x, const Mixed& y)
{
  Mixed result, m1, m2;
  m1 = x;
  m2 = y;
  m1.ToFraction();
  m2.ToFraction();
  result.denominator_=m1.denominator_*m2.denominator_;
  result.numerator_ = (m1.numerator_ * m2.denominator_)- (m2.numerator_ 
* m1.denominator_);
  result.Simplify();
  return result;
}
Mixed operator*(const Mixed& x, const Mixed& y)
{
  Mixed result, m1, m2;
  m1 = x;
  m2 = y;
  m1.ToFraction();
  m2.ToFraction();
  result.denominator_=m1.denominator_ * m2.denominator_;
  result.numerator_= m1.numerator_ * m2.numerator_;
  result.Simplify();
  return result;
}
Mixed operator/(const Mixed& x, const Mixed& y)
{
  Mixed result, m1, m2;
  if(y.whole_==0  && y.numerator_==0)
  {
    result.whole_=0;
    result.numerator_=0;
    result.denominator_=1;
    return result;
  }
  else
  {
    m1 = x;
    m2 = y;
    m1.ToFraction();
    m2.ToFraction();
    result.numerator_=m1.numerator_ * m2.denominator_;
    result.denominator_=m1.denominator_ * m2.numerator_;
    result.Simplify();
    return result;
  }
}
Mixed::Mixed(int i, int n, int d)
{
  if(d == 0)
  {
    whole_ = 0;
    numerator_=0;
    denominator_=1;
  }
  if(i > 0)
  {
    whole_ = i;
    if(n > 0 && d > 0)
    {
      numerator_ = n;
      denominator_ = d;
    }
    if(n < 0 && d > 0)
    {
      whole_ = -i;
      numerator_ = -n;
      denominator_ = d;
    }
    if(n > 0 && d < 0)
    {
      whole_ = -i;
      numerator_ = n;
      denominator_ = -d;
    }
    if(n < 0 && d < 0)
    {
      numerator_ = -n;
      denominator_ = -d;
    }
  }
  if(i == 0)
  {
    whole_ = i;
    if(d > 0)
    {
      numerator_ = n;
      denominator_ = d;
    }
    if(d < 0)
    {
      numerator_ = -n;
      denominator_ = -d;
    }
  }
  if(i < 0)
  {
    whole_ = i;
    if(n > 0 && d > 0)
    {
      numerator_ = n;
      denominator_ = d;
    }
    if(n < 0 && d > 0)
    {
      whole_ = 0;
      numerator_=0;
      denominator_=1;
    }
    if(n > 0 && d < 0)
    {  whole_ = 0;
       numerator_=0;
       denominator_=1;}
    if(n < 0 && d < 0)
    {
      numerator_ = -n;
      denominator_ = -d;
    }
  }
}
Mixed::Mixed(int i)
{
  whole_ = i;
  numerator_=0;
  denominator_=1;
}
Mixed& Mixed::operator++()
{
  whole_ = whole_ + 1;
  return *this;
}
Mixed Mixed::operator++(int)
{
  Mixed temp = *this;
  whole_ = whole_ + 1;
  return temp;
}
Mixed& Mixed::operator--()
{
  whole_ = whole_ - 1;
  return *this;
}
Mixed Mixed::operator--(int)
{
  Mixed temp = *this;
  whole_ = whole_ - 1;
  return temp;
}
bool Mixed::Set(int i, int n, int d)
{
  if(i > 0 || i < 0)
  {
    if(n < 0 || d < 0)
    {
      whole_= 0;
      numerator_=0;
      denominator_=1;
      return false;
    }
  }
  if(i == 0)
  {
    if(d < 0)
    {
      whole_ = 0;
      numerator_=0;
      denominator_=1;
      return false;
    }
  }
  if(d==0)
  {
    whole_ = 0;
    numerator_=0;
    denominator_=1;
    return false;
  }
  else
  {
    whole_=i;
    numerator_=n;
    denominator_=d;
    return true;
  }
}
double Mixed::Evaluate()
{
  double result, n, d;
  n = numerator_;
  d = denominator_;
  if(whole_>=0)
  result = whole_ + (n / d);
  else
  result = whole_ - (n/d);
  return result;
}
void Mixed::ToFraction()
{
  if(whole_>0)
  {
    numerator_ = numerator_ + (whole_ * denominator_);
    whole_ = 0;
  }
  if(whole_<0)
  {
    numerator_ = (whole_ * denominator_)- numerator_;
    whole_ = 0;
  }
  ImproperSimplify();
}
void Mixed::Simplify()
{
  ImproperSimplify();
  if(numerator_ >= denominator_ || -numerator_ >= denominator_)
  {
    whole_+= numerator_ / denominator_;
    numerator_ = numerator_ % denominator_;
  }
  if(numerator_< 0)
  {
    numerator_=-numerator_;
  }
  ImproperSimplify();
}
void Mixed::ImproperSimplify()
{
  if(numerator_ > 0)
  {
    for(int i = numerator_; i >=1; i--)
    {
      if(numerator_ % i==0 && denominator_ % i==0)
      {
        numerator_= numerator_ / i;
        denominator_= denominator_ / i;
      }
    }}
  if(numerator_ < 0)
  {
    for(int i = numerator_; i <=-1; i++)
    {
      if(numerator_ % i==0 && denominator_ % i==0)
      {
        numerator_= -numerator_ / i;
        denominator_= denominator_ /-i;
      }
    }
  }
}
