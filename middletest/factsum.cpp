#include<iostream>
using namespace std;
int fact(int val)
{
  if(val < 0)
    return -1;
  int ret = 1;
  for(int i = 1; i !=val+1;++i)
      ret *= i;
  return ret;
}

int main()
{
  int num,sum = 0;
  cout << "请输入一个正整数：";
  cin >> num;
  for(int i = 1; i !=num+1;++i)
    sum = sum + fact(i);
  cout << "前"<<num<<"数的阶乘之和是:" << sum <<endl;
  return 0;
}