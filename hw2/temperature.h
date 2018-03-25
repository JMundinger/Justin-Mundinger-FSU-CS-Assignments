#include<iostream>
#include<iomanip>
#include<cctype>
#include<string>

using namespace std;

class Temperature
{

public:
  Temperature(); //default constructor
  Temperature(double, char); //constructor

  void Input(); 
  void Show();

  bool Set(double deg, char s); //sets user input equal to class instance variables

  //accessor functions
  double GetDegrees(); //function that returns degrees (double)
  char GetScale(); //function that returns the scale (F, C, or K)

  bool SetFormat(char); //
  bool Convert(char sc); //function that converts temperature to another scale

  int Compare(const Temperature& d);
  void Increment(int, char);

private:
//instance variables
double degrees_; 
char scale_;
char format_;
};
