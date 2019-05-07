#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main()
{
  ifstream in("data");
  if(!in){
    cerr<<"not open ifile" <<endl;
    return -1;
  }
  string line;
  vector<string> words;
  while(getline(in,line)){//change for in >> line:表示的是将每个单词作为一个独立的元素进行存储
    words.push_back(line);
  }
  in.close();

  vector<string>::const_iterator it = words.begin();
  while(it !=words.end()) {
    cout << *it << endl;
    ++it;
  }

  return 0;
}