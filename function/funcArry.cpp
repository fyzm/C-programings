#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int myCompare(const int val,const int *p)
{
  return (val > *p) ? val : *p;

}

int main(){
  srand((unsigned) time (NULL));
  int a[10];
  for(auto &i :a)
    i = rand() % 100;
  cout << "please cin a number:";
  int j;
  cin >> j;
  cout << "val or Array element's bignumbers is:" << myCompare(j,a) <<endl;
  cout << "All of array elements are: " << endl;
  for(auto i : a)
    cout << i <<  " ";
  cout << endl;
  return 0;
}

