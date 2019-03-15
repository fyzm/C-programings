#include<iostream>
#include<string>
using namespace std;
int main(){
  string word,line;
  cout << "please reading string: 1.read every word 2.read auto lines" << endl;
  char ch;
  cin >> ch;
  if(ch == '1'){
    cout << " please cin string: Welcome to C++ famil! " << endl;
    cin >> word;
    cout << "systream read string is:" << endl;
    cout << word << endl;
    return 0;
  }
  //clear up cin Buffer
  cin.clear();
  cin.sync();
  if(ch == '2')
  {
    cout << "please cin string: Welcome to C++ family" << endl;
    getline(cin,line);
    cout << "systream read using string is:" << endl;
    cout << line << endl;
    return 0;
  }
  cout << "your cin is error";
  return -1;
}