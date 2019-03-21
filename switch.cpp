#include<iostream>
using namespace std;

int main()
{
  unsigned int aCnt = 0,eCnt = 0,iCnt = 0,oCnt = 0,uCnt = 0;
  char ch;
  cout << "please cin some text:" << endl;
  while(cin >> ch)
  {
    switch(ch)
    {
      case 'a':
      case 'A':
        ++aCnt;
        break;
      case 'e':
      case 'E':
        ++eCnt;
        break;
      case 'i':
      case 'I':
        ++iCnt;
        break;
      case 'o':
      case 'O':
        ++oCnt;
      case 'u':
      case 'U':
        ++uCnt;
    }
  }
  cout << "a is" << aCnt << endl;
  cout << "e is" << eCnt << endl;
  cout << "i is" << iCnt << endl;
  cout << "o is" << oCnt << endl;
  cout << "u is" << uCnt << endl;
  return 0;
}