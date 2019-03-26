#include<iostream>
#include "Sales_item.h"
using namespace std;

/* 
std::istream &read(std::istream &is,Person &per)
{
  is >> per.strName >> per.strAddress;
  return is;

}
std::ostream &print(std::ostream &os,const Person &per)
{
  os << per.getName() << per.getAddress();
  return os;  
}
 */

class Sales_data
{
  public://构造函数的四种形式
    Sales_data() = default;
    Sales_data(const std::string &book): bookNo(book) {}
    Sales_data(const std::string &book,const unsigned num,
        const double sellp,const double salep);
    Sales_data(std::istream &is);
  public:
    std::string bookNo;
    unsigned units_sold = 0;
    double sellingprice = 0.0;
    double saleprice = 0.0;
    double discount = 0.0;
};

Sales_data::Sales_data(const std::string &book,const unsigned num,
     const double sellp,const double salep)
{
  
}

