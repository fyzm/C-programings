#include<iostream>
using namespace std;


class Distance
{
  private:
    int feet,inches;
  public:
    Distance(){
      feet = 0;
      inches = 0;
    }
    Distance(int f,int i){
      feet = f;
      inches = i;
    }
    void displayDistance()
    {
      cout << "F:" << feet << "I:" << inches <<endl;
    }
    Distance operator- ()
    {
      feet = -feet;
      inches = -inches;
      return Distance(feet,inches);
    }
    bool operator <(const Distance& d)
    {
      if(feet < d.feet)
      {
        return true;
      }
      if(feet == d.feet && inches < d.inches)
      {
        return true;
      }
        return false;
    }
    Distance operator()(int a,int b,int c)//重载函数调用运算符
    {
      Distance D;
      D.feet = a + c + 10;
      D.inches = b + c + 100;
      return D;
    }
};

int main()
{
  Distance D1(11,10),D2(5,11),D3;
  if(D1 < D2){
    cout << "D1 is less than D2" << endl;
  }
  else
  {
    cout << "D2 is less than D1" << endl;
  }
  -D1;
  D1.displayDistance();
  -D2;
  D2.displayDistance();
  D3 = D1(10,10,10);
  D3.displayDistance();
  return 0;
}

