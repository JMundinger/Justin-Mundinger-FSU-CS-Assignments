#include<iostream>
#include<iomanip>
#include "temperature.h"

using namespace std;

int main() //Main function that tests class functions
{
Temperature t1;
Temperature t2(68.9, 'f');
t2.Increment(6, 'C');
cout << "\nTemperature t2 is now: \n";
t2.Show();
t1.Set(200.645, 'k');
cout << "\nTemperature t1 is now: \n";
t1.Show();
return 0;
}
