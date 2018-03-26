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

  void Input(); //initializes user input to instance variables
  void Show(); //prints the temperature and scale in the format

  bool Set(double deg, char s); //sets user input equal to class instance variables

  //accessor functions
  double GetDegrees(); //function that returns degrees (double)
  char GetScale(); //function that returns the scale (F, C, or K)

  bool SetFormat(char); //function that sets the decimal format for the degrees
  bool Convert(char sc); //function that converts temperature to another scale

  int Compare(const Temperature& d); //calls convert function, compares parameter's temp to current object's temp
  void Increment(int, char); //adds degrees of a scale to the current object's temperature

private:
//instance variables
double degrees_; 
char scale_;
char format_;
};
