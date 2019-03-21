#include<iostream>
using namespace std;

double myADD(double vall,double va12)
{
    double result = vall + va12;
    static unsigned iCnt = 0;
    ++iCnt;
    cout << "function alreay is" << iCnt << "times" << endl;
    return result; 
}

int main()
{
    double num1,num2;
    cout << "please two numbers:";
    while(cin >> num1 >> num2)
    {
      cout << num1 << "and" << num2 << "result are:"
            << myADD(num1,num2) << endl;
    }
    return 0;
}