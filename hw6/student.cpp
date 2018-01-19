#include<iostream>
#include<iomanip>
#include<string>
#include<cctype>
#include "student.h"

using namespace std;

Student::Student()
{
  firstname = "";
  lastname = "";
  course = "";
}
Student::~Student()
{

}
void Student::Set(string last, string first, string c)
{
  firstname = first;
  lastname = last;
  course = c;
}
string Student::GetFirstName()
{
  return firstname;
}
string Student::GetLastName()
{
  return lastname;
}
string Student::GetCourse()
{
  return course;
}
English::English(int a, int p, int m, int f)
{
  attendance_ = a;
  project_ = p;
  midterm_ = m;
  final_ = f;
}
English::~English()
{

}
double English::ComputeAvg()
{
  double a = attendance_*.1;
  double p = project_*.3;
  double m = midterm_*.3;
  double f = final_*.3;
  double result = a + p + m + f;
  return result;
}
int English::GetFinal()
{
  return final_;
}
Math::Math(int a, int b, int c, int d, int e, int t1, int t2, int f)
{
  q1=a;
  q2=b;
  q3=c;
  q4=d;
  q5=e;
  test1_ = t1;
  test2_ = t2;
  final_ = f;
}
Math::~Math()
{

}
int Math::GetFinal()
{
  return final_;
}
double Math::QuizAvg()
{
  double result = (q1 + q2 + q3 + q4 + q5) / 5.0;
  return result;
}
double Math::ComputeAvg()
{
  double result = (QuizAvg()*.15) + (test1_*.25) + (test2_*.25) + (final_*.35);
  return result;
}
History::History(int p, int m, int f)
{
  paper_ = p;
  midterm_ = m;
  final_ = f;
}
History::~History()
{

}
int History::GetFinal()
{
  return final_;
}
double History::ComputeAvg()
{
  double result = (paper_*.25) + (midterm_*.35) + (final_*.4);
  return result;
}
