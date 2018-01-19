#include<iostream>
#include<iomanip>
#include<cctype>
#include<string>

using namespace std;

class Temperature
{

public:
  Temperature();
  Temperature(double, char);

  void Input();
  void Show();

  bool Set(double deg, char s);

  //accessor functions
  double GetDegrees();
  char GetScale();

  bool SetFormat(char);
  bool Convert(char sc);

  int Compare(const Temperature& d);
  void Increment(int, char);

private:

double degrees_;
char scale_;
char format_;
};
