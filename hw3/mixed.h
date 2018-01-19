#include<iostream>
using namespace std;

class Mixed
{
friend istream& operator>>(istream&, Mixed& m);
friend ostream& operator<<(ostream&, const Mixed& m);

friend bool operator<(const Mixed&, const Mixed&);
friend bool operator>(const Mixed&, const Mixed&);
friend bool operator<=(const Mixed&, const Mixed&);
friend bool operator>=(const Mixed&, const Mixed&);
friend bool operator==(const Mixed&, const Mixed&);
friend bool operator!=(const Mixed&, const Mixed&);

friend Mixed operator+(const Mixed&, const Mixed&);
friend Mixed operator-(const Mixed&, const Mixed&);
friend Mixed operator*(const Mixed&, const Mixed&);
friend Mixed operator/(const Mixed&, const Mixed&);

public:
Mixed(int i, int n, int d);
Mixed(int i = 0);

Mixed& operator++();
Mixed operator++(int);
Mixed& operator--();
Mixed operator--(int);
double Evaluate();
void ToFraction();
void Simplify();
void ImproperSimplify();
private:
bool Set(int i, int n, int d);
int whole_;
int numerator_;
int denominator_;

};
