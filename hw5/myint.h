#include<iostream>
using namespace std;

class MyInt
{
   // these overload starters are declared as friend functions

   friend MyInt operator+ (const MyInt& x, const MyInt& y);
   // add in multiplication, as well
   friend MyInt operator* (const MyInt& x, const MyInt& y);

   friend bool operator< (const MyInt& x, const MyInt& y);
   // add in the other comparison overloads, as well
   friend bool operator> (const MyInt& x, const MyInt& y);
   friend bool operator<= (const MyInt& x, const MyInt& y);
   friend bool operator>= (const MyInt& x, const MyInt& y);
   friend bool operator== (const MyInt& x, const MyInt& y);
   friend bool operator!= (const MyInt& x, const MyInt& y);
   // declare overloads for input and output (MUST be non-member functions)
   //  you may make them friends of the class
   friend ostream& operator<<(ostream& s, const MyInt& x);
   friend istream& operator>>(istream& s, MyInt& x);

public:
   MyInt(int n = 0);		// first constructor
   // be sure to add in the second constructor, and the user-defined 
   //  versions of destructor, copy constructor, and assignment operator
   MyInt(const char *);
   ~MyInt();
   MyInt(const MyInt & m);
   MyInt& operator= (const MyInt & m);
   MyInt& operator++();
   MyInt operator++(int);
   int GetSize();
   void Set(const char *, MyInt);
   void Reverse(); 
   bool IsNumber(char);
private:
   // member data (suggested:  use a dynamic array to store the digits)
unsigned int * digits_;
unsigned int size_;
unsigned int maxsize_;
void Grow();
void Shrink();
};
