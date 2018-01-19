#include <iostream>
#include <iomanip>
#include <cmath>
#include "triangle.h"

using namespace std;

Triangle::Triangle(int size, char border, char fill)
{
  if(size < 1)
  size = 1;
  if(size > 39)
  size = 39;
  size_ = size;
  border_ = border;
  fill_ = fill;
}
int Triangle::GetSize()
{
  if(size_ <=1 && size_ >= 39)
  return size_;
}
int Triangle::Perimeter()
{
  int perimeter = 0;
  perimeter = size_ * 3;
  return perimeter;

}
double Triangle::Area()
{
  double area = 0.00;
  area = (sqrt(3)/4) * pow(size_, 2);
  return area;
}
int Triangle::Grow()
{
  if(size_ < 39)
  {
  size_ = size_ + 1;
  }
  return size_;
}
int Triangle::Shrink()
{
  if(size_ > 1)
  {
  size_ = size_ - 1;
  }
  return size_;
}
char Triangle::SetBorder(char border)
{
  if((int)border >= 33 && (int)border <= 126)
  border_ = border;
  else
    border_ = '#';

  return border_;
}
char Triangle::SetFill(char fill)
{
  if((int)fill >= 33 && (int)fill <= 126)
  fill_ = fill;
  else
    fill_ = '*';

  return fill_;
}
void Triangle::Draw()
{
  int i;
    for(i = 1; i < size_; i++)
    {
      for(int j = 0; j < size_ - i; j++)
      {
        cout << " ";
      }
    if(i > 1)
    {
    cout << border_ << " ";
      for(int k = 3; k <= i; k++)
      {
        cout << fill_ << " ";
      }
    }
      cout << border_ << "\n";
    }
    for(int l = 0; l < size_; l++)
    {
      cout << border_ << " ";
    }
  cout << "\n";
}
void Triangle::Summary()
{
  cout << "Size of triangle's side = " << GetSize() <<" units.";
  cout << "\nPerimeter of triangle = " << Perimeter() << " units.";
  cout << fixed;
  cout << showpoint;
  cout << setprecision(2);
  cout <<  "\nArea of triangle = " << Area() << " units.";
  cout << "\nTriangle looks like:\n";
  Draw();
}
