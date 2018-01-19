#include<iostream>
#include<iomanip>
#include "triangle.h"

using namespace std;

int main()
{
Triangle t1(5, 'x', 'o');

cout << "t1 has size = " << t1.GetSize() << " units.\n";
t1.Draw();

t1.Summary();

return 0;
}
