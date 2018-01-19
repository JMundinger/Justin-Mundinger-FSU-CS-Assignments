#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

class Flex
{
friend ostream& operator<<(ostream&, const Flex&);

public:
Flex();
Flex(const char * );
~Flex();
void cat(const Flex&);

private:
char * str_;
int current;
};
