#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;

int main()
{
  vector<int> vInt;
  srand((unsigned)time(NULL));
  for(int i = 0; i < 10;i++ )
  {
    vInt.push_back(rand() % 1000);
  }
  cout << "random ten numbers are:" << endl;
  for(auto it = vInt.cbegin(); it !=vInt.cend();it++)
  {
    cout << *it << " ";
  }
  cout << endl;
  cout << "ten numbers are:" << endl;
  for(auto it = vInt.begin(); it !=vInt.end();it++)
  {
    *it *=2;
    cout << *it << endl;
  }
  cout << endl;
  return 0;
}