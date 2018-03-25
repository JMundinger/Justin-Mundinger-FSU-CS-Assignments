#include<iostream>
#include<iomanip>
#include<cctype>
#include "temperature.h"

using namespace std;

Temperature::Temperature() //default constructor initializes instance variables
{
  degrees_ = 0;
  scale_ = 'C';
  format_ = 'D';
}
Temperature::Temperature(double d, char s) //constructor initializes instance variables, if outside conditions sets variables to default
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
void Temperature::Input() //sets user input to instance variables
{
char scale;
double deg;
do
{
cout << "Enter a valid temperature and scale (C, F, or K):\n";
cin >> deg >> scale;
}
while(Set(deg, scale)==false); //while Set function returns false, when valid values are entered, while loop exits

degrees_ = deg;
scale_ = (toupper(scale));
}

void Temperature::Show() //prints the temperature data depending on the format
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

bool Temperature::Set(double deg, char s) //if parameters are outside scale ranges, function returns false, else sets parameters to variables
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

double Temperature::GetDegrees() //returns instance variable degrees
{
  return degrees_;
}
char Temperature::GetScale() //returns the scale of the Temperature object
{
  return scale_;
}

bool Temperature::SetFormat(char f) //sets the format of the temp, which determines how it is printed in Show() function
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
bool Temperature::Convert(char sc) //Converts temperature instance variables to different scale
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
int Temperature::Compare(const Temperature& d) //converts temp to same scale, returns int that cooresponds to temp if it is >, <, or =
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
void Temperature::Increment(int deg, char sc) //converts temp to new scale, adds degrees of that scale, then converts back to original scale
{
  char s = scale_;
  Convert(sc);
  degrees_ = degrees_ + deg;
  Convert(s);
}
