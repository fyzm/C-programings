#include<iostream>
using namespace std;

int power(int x,int y);
int compute_poly(int x);



int main(void)
{
  int num;
  cout << "计算下列多项式:" << endl;
  cout << "3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6" << endl;
  cout << "输入 x: ";
  cin >> num ;
  cout << "答案是:" << compute_poly(num);
  return 0; 
}

int power(int x ,int n)
{
  if(n < 1)
    return 1;
  else
    return x * power(x,n-1);
}

int compute_poly(int x)
{
  int result;
  result = 3 * power(x,5);
  result += 2 * power(x,4);
  result -= 5 * power(x,3);
  result -= power(x,2);
  result += 7 * x - 6; 
  return result;
}