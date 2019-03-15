#include <iostream>
#include <string>
using namespace std;
int main(){
  string s1,s2;
  cout << "please cin two strings" << endl;
  cin  >> s1 >> s2;
  if(s1 == s2)
    cout << "two stirng are equal" << endl;
  else if(s1 > s2)
    cout << s1 << "is big than" << s2 << endl;
  else 
    cout << s2 << "is big than" << s1 << endl;
  return 0; 
}