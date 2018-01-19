#include<iostream>
#include<iomanip>
#include<cstring>
#include<cctype>
#include "stack.h"

using namespace std;

bool IsLetter(char x)
{
  if((x>='a' && x <='z')||(x>='A' && x <= 'Z'))
    return true;
  else
    return false;
}
int main()
{
  Stack <char> s;
  bool pal;
  char input[100];
  cout << "Please enter a string:\n> ";
  cin.getline(input, 100);
  int length = strlen(input);
  char letters[length];
  for(int i=0; i < length; i++)
  {
    if(input[i]==' '||input[i]==','||input[i]=='.'||input[i]=='?'|| input[i]=='!'|| 
input[i]=='\''||input[i]==':'||input[i]==';')
    { }
    else if(IsLetter(input[i])==0)
    {
      letters[i] = toupper(input[i]);
      s.push(letters[i]);
    }
  }
  char x;
  int i = 0;
  while(!s.isStackEmpty() )
  {
    s.pop(x);
    if(x==letters[i])
      pal = 0;
    else
    {
      pal = -1;
      break;
    }
    i++;
  }
  if(pal==0)
  {
    cout <<"\n\"";
    cout << input;
    cout <<"\" IS a palindrome\n";
  }
  else
  {
    cout <<"\n\"";
    cout << input;
    cout<<"\" is NOT a palindrome\n";
  }
  return 0;
}
