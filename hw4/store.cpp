#include<iostream>
#include<iomanip>
#include<cstring>
#include<cctype>
#include "book.h"
#include "store.h"

using namespace std;

Store::Store()
{
  size_ = 0;
  maxsize_ = 5;
  money_ = 0.00;
  books_ = new Book[maxsize_];
  items_ = 0;
}
Store::~Store()
{
  delete [] books_;
}
void Store::SetCash(double c)
{
  money_ = c;
}
double Store::GetMoney()
{
  return money_;
}
void Store::ShowMenu()
{
  cout<<"\n\n\t\t\t\t*** BOOKSTORE MENU ***\n";
  cout<<"\t\tA\t\tAdd a Book to Inventory\n";
  cout<<"\t\tF\t\tFind a book from Inventory\n";
  cout<<"\t\tS\t\tSell a book\n";
  cout<<"\t\tD\t\tDisplay the inventory list\n";
  cout<<"\t\tG\t\tGenre Summary\n";
  cout<<"\t\tM\t\tShow this Menu\n";
  cout<<"\t\tX\t\tExit Program\n";
}
void Store::DisplayInventory()
{
  if(size_==0)
    cout<<"No books currently in inventory\n";
  else
  {
    cout <<left<<setw(30)<<"Title"<<left<<setw(20)<<"Author";
    cout <<left<<setw(10)<<"Genre"<<left<<setw(4)<<"Price\n\n";  
    for(int i=0; i<size_; i++)
      books_[i].Display();
  }
  cout<<"\nNumber of books = "<<size_;
  cout<<"\nMoney in register = $ "<<fixed<<setprecision(2)<<money_;
  cout<<"\n\n";
}
void Store::Grow()
{
  maxsize_ = size_ + 5;
  Book * newbooks = new Book[maxsize_];
  for(int i=0; i < size_; i++)
    newbooks[i] = books_[i];
  delete [] books_;
  books_ = newbooks;
  cout << "\nArray being resized to "<<maxsize_<<" allocated slots.\n"; 
}
void Store::AddBook(const char * t, const char * a, Genre g, double p)
{
  books_[size_++].Set(t, a, g, p);
  if(size_==maxsize_)
    Grow();
}
void Store::Shrink()
{
  maxsize_ = size_ - 5;
  Book * newbooks = new Book[maxsize_];
  for(int i=0; i < size_; i++)
    newbooks[i] = books_[i];
  delete [] books_;
  books_ = newbooks;
  cout <<"\nArray being resized to " <<maxsize_<<" allocated slots.\n";

}
void Store::Sell(const char * s)
{
  int x = Find(s);
  if(x==-1)
    cout <<"\n* No sale made *\n";
  else
  {
    money_ += books_[x].GetPrice();
    for(int i=x + 1; i < size_; i++)
      books_[i - 1] = books_[i];
    size_--;
    cout<<"\n* Sale complete! *\n";
  }
  if(maxsize_==size_)
    Shrink();
}
int Store::Find(const char * x)
{
  for(int i=0; i < size_; i++)
  {
    if(strcmp(books_[i].GetTitle(), x)==0)
      return i;
  }
  return -1;
}
bool Store::FindAuthor(const char * x)
{

  for(int i=0; i < size_; i++)
  {
    if(strcmp(books_[i].GetAuthor(), x)==0)
    {
      return true;
    }
    else
      return false;
  }
}
void Store::FindAll(const char * x)
{
  int p = Find(x);
  if(p!=-1)
  {
    cout <<"\nBook(s) found: \n";
    cout <<left<<setw(30)<<"\nTitle"<<left<<setw(20)<<"Author";
    cout <<left<<setw(10)<<"Genre"<<left<<setw(4)<<"Price\n\n";
    books_[p].Display();
  }
  if(FindAuthor(x)==true)
  {
    cout <<"\nBook(s) found: \n";
    cout <<left<<setw(30)<<"\nTitle"<<left<<setw(20)<<"Author";
    cout <<left<<setw(10)<<"Genre"<<left<<setw(4)<<"Price\n\n";
    for(int i =0; i < size_; i++)
    {
      if(strcmp(books_[i].GetAuthor(), x)==0)
        books_[i].Display();
    }
  }
  else if(p==-1 && FindAuthor(x)==false)
    cout << x <<" not found.\n";
}
void Store::FindGenre(Genre g)
{
  int num = 0;
  double p = 0.00;
  for(int i=0; i < size_; i++)
  {
    if(g==books_[i].GetGenre())
    {
      books_[i].Display();
      p += books_[i].GetPrice();
      num++;
    }
  }
  cout <<"\nTotal books in this genre = " << num;
  cout <<"\nTotal price of books in this genre = $"<<fixed<<setprecision(2)<<p;
}
