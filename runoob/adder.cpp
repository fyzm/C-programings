#include<iostream>
using namespace std;

class Adder{
  public:
   //构造函数
    Adder(int i = 0)
    {
      total = i;
    }
    //对外提供接口
    void addNum(int number)
    {
      total += number;
    }
    //对外提供接口
    int getTotal()
    {
      return total;
    }
  private:
    //对外隐藏数据
    int total;
};
int main()
{
  Adder a;
  a.addNum(10);
  a.addNum(20);
  cout << "Total" << a.getTotal() <<endl;
  return 0;
}