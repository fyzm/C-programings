#include<iostream>
#include<stdexcept>

using namespace std;

istream & f(istream & in)
{
  int v;
  while (in>>v,!in.eof()) {
    if(in.bad())
      throw runtime_error("IO流错误");
    if (in.fail()){
      cerr << "数据失误,请重载: " << endl;
      in.clear();
      in.ignore(100,'\n');
      continue;
    }
    cout << v << endl;
  }
  in.clear();
  return in;
}

int main()
{
  cout << "please cin some numbers:ctrl + z end" << endl;
  f(cin);
  return 0;
}

