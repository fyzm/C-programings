#include<iostream>
using namespace std;

unsigned myCnt(){
  static unsigned iCnt = -1;
  ++iCnt;
  return iCnt;
}

int main()
{
  cout << "please cin some string:" << endl;
  char ch;
  while(cin >>ch)
  {
    cout << "function excute doing :" << myCnt() << endl;
  }
  return 0;
}