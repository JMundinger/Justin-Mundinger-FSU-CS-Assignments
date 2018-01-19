#include<iostream>
#include<iomanip>
#include<cstring>
#include "book.h"
using namespace std;

Book::Book()
{
  *title = '\0';
  *author = '\0';
  price = 0.00;
}

void Book::Set(const char * t, const char * a, Genre g, double p)
{
  strcpy(title, t);
  strcpy(author, a);
  type = g;
  price = p;
}
const char * Book::GetTitle() const
{
  const char * t;
  t = title;
  return t;
}
const char * Book::GetAuthor() const
{
  const char * a;
  a =  author;
  return a;
}
double Book::GetPrice() const
{
  return price;
}
Genre Book::GetGenre() const
{
  return type;
}
void Book::Display() const
{
  cout << left<< setw(30)<<title;
  cout << left<<setw(20)<<author;
  cout << left<<setw(10);
  if(type==FICTION)
  cout<<"Fiction";
  if(type==MYSTERY)
  cout<<"Mystery";
  if(type==SCIFI)
  cout<<"SciFi";
  if(type==COMPUTER)
  cout<<"Computer";
  cout << fixed << setprecision(2) <<"$ "<<price<<"\n";
}
