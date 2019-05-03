namespace namespace_name {

}

//name::code //code可以是变量或者函数


#include <iostream>
using namespace std;

namespace first_space{
  void func(){
    cout<<"Inside first_space" << endl;
  }
}
namespace second_space{
  void func(){
    cout <<"Inside second_space"<<endl;
  }
}

int main()
{
  first_space::func();
  second_space::func();
  return 0;
}



