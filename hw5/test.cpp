#include<iostream>
#include<iomanip>
#include<cstring>
#include<cctype>
#include "myint.h"
using namespace std;

int main()
{
  MyInt x(123);
  MyInt y(123);
  MyInt z;
cout <<"MyInt object x is: " <<  x << endl;
cout <<"\nMyInt object y is: "<< y << endl;
z = x * y;
cout << "\nx times y is: " << z << endl;
cout << "\nEnter new x: ";
cin >> x;
cout <<"\nX is now: "<< x << endl;


  return 0;
}
