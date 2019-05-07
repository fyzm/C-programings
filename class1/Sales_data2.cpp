#include<iostream>
#include<fstream>
#include "Sales_data.h"

using namespace std;

int main(int argc,char *argv[])
{
  if(argc !=3){
    cerr << "please cin,cout files name" << endl;
    return  -1;
  }
  ifstream in(argv[1]);
  if(!in) {
    cerr << "无法打开输入文件" << endl;
    return -1;
  }
  ofstream out(argv[2]);
  if(!out){
    cerr << "无法打开输出文件" << endl;
    return -1;
  }
  
}