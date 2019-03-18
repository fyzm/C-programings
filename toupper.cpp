#include<iostream>
#include<vector>
#include<string>

using namespace std;
int main()
{
  vector<string> vString;
  string s;
  char cont = 'y';
  cout << "Please cin first words:" << endl;
  while(cin >> s)
  {
    vString.push_back(s);
    cout << "are you go (y or n) ?" << endl;
    cin >> cont;
    if(cont != 'y' && cont !='Y')
      break;
    cout << "Please cin next word:" << endl;
  }
  cout << "tranfer result is :" << endl;
  for(auto &mem : vString)
  {
    for(auto &c : mem)
      c = toupper(c);
    cout << mem << endl;
  }

  return 0;
}