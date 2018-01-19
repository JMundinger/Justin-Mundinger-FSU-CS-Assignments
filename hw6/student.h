#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
Student();
~Student();
void Set(string, string, string);
virtual double ComputeAvg() = 0;
virtual int GetFinal() = 0;
string GetCourse();
string GetFirstName();
string GetLastName();
protected:
string firstname;
string lastname;
string course;

};
class English : public Student
{
public:
English(int, int, int, int);
~English();
int GetFinal();
double ComputeAvg();
private:
int attendance_;
int project_;
int midterm_;
int final_;

};
class History : public Student
{
public:
History(int, int, int);
~History();
int GetFinal();
double ComputeAvg();
private:
int paper_;
int midterm_;
int final_;
};
class Math : public Student
{
public:
Math(int, int, int, int, int, int, int, int);
~Math();
int GetFinal();
double QuizAvg();
double ComputeAvg();
private:
int q1, q2, q3, q4, q5;
int test1_;
int test2_;
int final_;
};
