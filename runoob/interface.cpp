//接口描述了类的行为和功能,而不才需要完成类的特定实现

// class Box
// {
//   public:
//     virtual double getVolume() = 0;
//   private:
//     double length;
//     double breadth;
//     double height;
// }

#include <iostream>
using namespace std;
class Shape
{
  public:
    virtual int getArea() = 0;
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
class Triangle: public Shape
{
  public:
    int getArea()
    {
      return (width * height) / 2;
    }
};

int main(void)
{
  Rectangle Rect;
  Triangle Tri;
  Rect.setWidth(5);
  Rect.setHeight(7);
  cout << "Total Rectangle area:" << Rect.getArea() << endl;
  Tri.setWidth(10);
  Tri.setHeight(3);
  cout << "Total Triangle area:" << Tri.getArea() << endl;
  return 0;
}









