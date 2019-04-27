#include<iostream>
using namespace std;

int main()
{
  int n,sums = 0;
  cout << "Enter a number:";
  cin >> n;
  for (int i = 0;i <=n;++i){
    sums = sums + i;
  }
  cout << "Sums is :" << sums;
  return 0;
}

int sum(int m){
  if(m == 1)
    return m;
  else
    return m + sum(m - 1);
}

