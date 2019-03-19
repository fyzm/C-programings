#include<iostream>
#include<vector>
using namespace std;

int main() 
{
  vector<int> vInt;
  int iVal;
  cout << "Please cin some numbers:" << endl;
  while(cin >> iVal){
    vInt.push_back(iVal);
  if(vInt.size() == 0)
    {
      cout << "no any numbers:" <<endl;
      return -1;
    }
    cout << "firstandend numbers:" << endl;
    for(decltype(vInt.size()) i = 0; i < vInt.size() / 2; i++){
        cout << vInt[i] + vInt[vInt.size() - i -1] << " ";
        if((i+1) % 5 == 0)
            cout << endl;
    }
    // if numbers is odd,only end number
    if(vInt.size() % 2 != 0)
      cout << vInt[vInt.size() / 2];
    return 0;
  }
}