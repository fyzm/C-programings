#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;
int main()
{
  ifstream in("data");
  if(!in) {
    cerr << "无法打开输入文件" << endl;
    return -1;
  }
  string line;
  vector<string> words;
  while(getline(in,line)){
    words.push_back(line);
  }
  in.close();//输入文件，关闭
  vector<string>::const_iterator it = words.begin(); //迭代器
  while(it != words.end()){
    istringstream line_str(*it);
    string word;
    while(line_str >> word)// 通过istringstream 从vector读取数据
      cout << word << " ";
    cout << endl;
    ++it;
  }
  return 0;
}