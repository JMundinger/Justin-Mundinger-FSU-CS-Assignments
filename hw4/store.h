#include<iostream>
#include<iomanip>
#include<cstring>
#include<cctype>
#include "book.h"

class Store
{
  public:
  Store();
  ~Store();
  void SetCash(double);
  double GetMoney();
  void AddBook(const char*, const char*, Genre, double); 
  void Sell(const char*);
  void DisplayInventory();
  void ShowMenu();
  void FindGenre(Genre);
  int Find(const char *);
  bool FindAuthor(const char *);
  void FindAll(const char *);

  private:
  double money_;
  Book * books_;
  int items_;
  int size_;
  int maxsize_;
  void Grow();
  void Shrink();
};
