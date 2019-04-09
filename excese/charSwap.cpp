#include<iostream>
#include<string>
using namespace std;

void swap(char *&a,char *&b);

int main(){
  char *ga = "good morning";
  char *gb = "good afternoon";
  // swap(&ga,&gb);
  swap(ga,gb);
  cout << "ga:" << ga << endl;
  cout << "gb:" << gb << endl;
  return 0;
}

void swap(char** a,char** b)
{
  char* temp;
  temp  = *a;
  *a = *b;
  *b = temp;
}

void swap(char **a,char **b)
{
  char* temp = *a;
  *a = *b;
  *b = temp;
}




void swap(char *  &a,char*  &b)
{
  char *temp = a;
  a = b;
  b = temp;
}

