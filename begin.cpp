#include<iostream>
#include<vector>

using namespace std;

int main()
{
  vector<unsigned> vUS(11);
  auto it = vUS.begin();
  int iVal;
  cout << "please cin a set of grid:" << endl;
  while(cin >> iVal)
    if(iVal < 101)
        ++ *(it + iVal / 10);
  cout << "your total numbers are:" << vUS.size() << "grads" << endl;
  cout << "all numbers are " <<endl;
  for(it = vUS.begin();it !=vUS.end();it++)
  {
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}