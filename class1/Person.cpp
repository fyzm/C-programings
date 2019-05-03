#include<iostream>
#include<string>
using namespace std;
class Person
{
  private:
    string strName;
    string strAddress;
  public:
    Person() = default;
    Person(const string &name,const string &add)
    {
      strName = name;
      strAddress = add;
    }
    //Person(std::istream &is){ is >> *this;}
    public:
      string getName() const {return strName;}
      string getAddress() const{return strAddress;}
}


