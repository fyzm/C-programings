#include<iostream>
using namespace std;
class Shape
{
  public:
    void setWidth(int w)
    {
      width = w;
    }
    void setHeight(int h)
    {
      height = h;
    }
  protected:
    int width;
    int height;
};

class Rectangle: public Shape
{
  public:
    int getArea()
    {
      return (width * height);
    }
};

int main(void)
{
  Rectangle Rect;
  Rect.setHeight(5);
  Rect.setWidth(10);
  cout << "Total area:" << Rect.getArea() << endl;
  return 0;
}

