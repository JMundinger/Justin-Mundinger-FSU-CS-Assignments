#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<fstream>
#include "student.h"

using namespace std;

ofstream out1;
ifstream in1;
int a = 0, b = 0, c = 0, d = 0, f = 0;
void PrintHeader()
{
 out1<<left <<setw(42)<<"Student"<<left<<setw(8)<<"Final"<<left<<setw(8)<<"Final"<<"Letter\n";
 out1<<left<<setw(42)<<"Name"<<left<<setw(8)<<"Exam"<<left<<setw(8)<<"Avg"<<"Grade\n";
 out1<<"----------------------------------------------------------------\n";
}
char FindLetter(double x)
{
  char letter;
  if(x >= 90)
  {
    letter = 'A';
    a++;
  }
  else if(x >= 80 && x <= 89)
  {
    letter = 'B';
    b++;
  }
  else if(x >= 70 && x <= 79)
  {
    letter = 'C';
    c++;
  }
  else if(x >= 60 && x <= 69)
  {
    letter = 'D';
    d++;
  }
  else
  {
    letter = 'F';
    f++;
  }
  return letter;
}
string FullName(string x, string y)
{
  char s = ' ';
  string full = x + s + y;
  return full;
}

int main()
{

char filename[21];

do
{
  in1.clear();
  cout <<"Please enter the name of the input file.\nFilename: ";
  cin >> filename;
  in1.open(filename);
  if(!in1)
    cout << "Not a valid file.  Try again.\n";
} while(!in1);

do
{
  out1.clear();

  cout << "Please enter the name of the output file.\nFilename: ";
  cin >> filename;
  out1.open(filename);
  if(!out1)
    cout << "Not a valid file.  Try again.\n";
} while(!out1);

int size;
in1 >> size;
Student ** s = new Student*[size];
int i = 0;
while(i < size)
{
  char ch;
  string last;
  string first;
  string course;
  in1.ignore();
  getline(in1, last, ',');
  in1.ignore();
  getline(in1, first);
  getline(in1, course, ' ');
  if(course=="Math")
  {
    int q1, q2, q3, q4, q5, t1, t2, f;
    in1 >> q1 >> q2 >> q3 >> q4 >> q5 >> t1 >> t2 >> f;
    Math * m = new Math(q1, q2, q3, q4, q5, t1, t2, f);
    s[i] = m;
  }
  else if(course=="English")
  {
    int a, p, m, f;
    in1 >> a >> p >> m >> f;
    English * e = new English(a, p, m, f);
    s[i] = e;
  }
  else if(course=="History")
  {
    int p, m, f;
    in1 >> p >> m >> f;
    History * h = new History(p, m, f);
    s[i] = h;
  }
  s[i]->Set(last, first, course);
  i++;
}

out1 << "\nStudent Grade Summary\n";
out1 << "--------------------- \n";
out1 <<"\nENGLISH CLASS\n\n";
PrintHeader();
for(int i=0; i < size; i++)
{
  if(s[i]->GetCourse()=="English")
  {
    out1 << left<<setw(42)<< FullName(s[i]->GetFirstName(), 
s[i]->GetLastName());
    out1 << left<<setw(8)<< s[i]->GetFinal() <<left<<setw(8)<<fixed<<setprecision(2) << 
s[i]->ComputeAvg();
    double g = s[i]->ComputeAvg();
    out1 <<FindLetter(g) << endl;
  }
}
out1 <<"\n\nHISTORY CLASS\n\n";
PrintHeader();
for(int i=0; i < size; i++)
{
  if(s[i]->GetCourse()=="History")
  {
    out1 << left<<setw(42)<< FullName(s[i]->GetFirstName(), s[i]->GetLastName());
    out1 << left<<setw(8)<< s[i]->GetFinal()<< left<<setw(8) << setprecision(2) << s[i]->ComputeAvg();
    double g = s[i]->ComputeAvg();
    out1 << FindLetter(g) << endl;
  }
}
out1 << "\n\nMATH CLASS\n\n";
PrintHeader();
for(int i=0; i < size; i++)
{
  if(s[i]->GetCourse()=="Math")
  {
    out1 << left<<setw(42)<< FullName(s[i]->GetFirstName(),s[i]->GetLastName());
    out1 << left<<setw(8)<< s[i]->GetFinal() << left<<setw(8) << setprecision(2) << s[i]->ComputeAvg();
    double g = s[i]->ComputeAvg();
    out1 <<FindLetter(g) << endl;
  }
}
out1 << "\n\nOVERALL GRADE DISTRIBUTION\n\n"; 
out1 <<"A: "<<setw(8)<<a<<endl;
out1 <<"B: "<<setw(8)<<b<<endl;
out1 <<"C: "<<setw(8)<<c<<endl;
out1 <<"D: "<<setw(8)<<d<<endl;
out1 <<"F: "<<setw(8)<<f<<endl;

for(int i=0; i < size; i++)
  delete s[i];
delete [] s;
in1.close();
out1.close();
cout << "\nProcessing complete.\n";

return 0;
}
