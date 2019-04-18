#include<iostream>
using namespace std;

double myAdd(double val1,double val2)
{
  double result = val1 + val2;
  static unsigned iCnt = 0;
  ++iCnt;
  cout << "this funtion excute" << iCnt << "times" << endl;
  return result;
}
int main()
{
  double num1,num2;
  cout << "Please cin two numbers:";
  while(cin >> num1 >> num2)
  {
    cout << num1 << "and" << num2 << "sum are:"
         << myAdd(num1,num2) << endl; 
  }
  return 0;
}