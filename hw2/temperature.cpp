#include<iostream>
#include<iomanip>
#include<cctype>
#include "temperature.h"

using namespace std;

Temperature::Temperature()
{
  degrees_ = 0;
  scale_ = 'C';
  format_ = 'D';
}
Temperature::Temperature(double d, char s)
{
  s = (toupper(s));
  format_ = 'D';
  if(d < -273.15 && s =='C')
  {
    degrees_ = 0;
    scale_ = 'C';
  }
  else if(d < 0 && s=='K')
  {
    degrees_ = 0;
    scale_ = 'C';
  }
  else if(d < -459.67 && s=='F')
  {
    degrees_ = 0;
    scale_ = 'C';
  }
  else if(s=='C' || s=='K' || s=='F')
  {
    degrees_ = d;
    scale_ = s;
  }
}
void Temperature::Input()
{
char scale;
double deg;
do
{
cout << "Enter a valid temperature and scale (C, F, or K):\n";
cin >> deg >> scale;
}
while(Set(deg, scale)==false);

degrees_ = deg;
scale_ = (toupper(scale));
}

void Temperature::Show()
{
  char x = (toupper(scale_));
  if(format_=='D')
  {
    cout << degrees_ << " ";
    cout << x;
  }
  if(format_=='P')
  {
    int oldprecision = cout.precision();
    cout << fixed << setprecision(1) <<degrees_ <<" "<< x;
    cout.precision(oldprecision);
  }
  if(format_=='L')
  {
    cout.precision();
    if(scale_=='C')
      cout << degrees_ <<" Celsius\n";
    if(scale_=='F')
      cout << degrees_ <<" Fahrenheit\n";
    if(scale_=='K')
      cout << degrees_ <<" Kelvin\n";
  }
}

bool Temperature::Set(double deg, char s)
{
s = (toupper(s));
if(deg < 0 && s=='K')
  return false;
if(deg <-273.15 && s=='C')
  return false;
if(deg <-459.67 && s=='F')
  return false;
if(s!='K'&& s!='C'&& s!='F')
  return false;
else
{
  degrees_ = deg;
  scale_ = s;
  return true;
}
}

double Temperature::GetDegrees()
{
  return degrees_;
}
char Temperature::GetScale()
{
  return scale_;
}

bool Temperature::SetFormat(char f)
{
f = (toupper(f));
if(f =='D')
{
  format_=f;
  return true;
}
else if(f=='P')
{
  format_=f;
  return true;
}
else if(f=='L')
{
  format_=f;
  return true;
}
else
  return false;
}
bool Temperature::Convert(char sc)
{
  scale_ = (toupper(scale_));
  sc = (toupper(sc));
  if(sc=='K')
  {
    if(scale_=='C')
    {
      degrees_= degrees_+273.15;
      scale_ = sc;
      return true;
    }
    if(scale_=='F')
    {
      degrees_= (degrees_-32)*(5.0/9)+273.15;
      scale_ = sc;
      return true;
    }
  }
  if(sc=='C')
  {
    if(scale_=='K')
    {
      degrees_ = degrees_ - 273.15;
      scale_ = sc;
      return true;
    }
    if(scale_=='F')
    {
      degrees_ = (degrees_-32)*(5.0/9);
      scale_ = sc;
      return true;
    }
  }
  if(sc=='F')
  {
    if(scale_=='K')
    {
      degrees_ = (degrees_-273.15)*(9.0/5)+32;
      scale_ =sc;
      return true;
    }
    if(scale_=='C')
    {
      degrees_ = (degrees_ * (9.0/5) + 32);
      scale_ = sc;
      return true;
    }
  }
  else
    return false;
}
int Temperature::Compare(const Temperature& d)
{
  double x = d.degrees_;
  degrees_ = Convert(d.scale_);
  if(degrees_ < x)
    return -1;
  if(degrees_ > x)
    return 1;
  if(degrees_ == x)
    return 0;
}

//extra credit
void Temperature::Increment(int deg, char sc)
{
  char s = scale_;
  Convert(sc);
  degrees_ = degrees_ + deg;
  Convert(s);
}
