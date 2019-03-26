#include<iostream>
#include<string>
using namespace std;

class Person
{
  private:
    string strName;
    string strAddress;
  public:
    string getName() const { return strName;}
    string getAddress() const {return strAddress;};
};
/* class Sales_data{

};

Sales_data add(const Sales_data &lhs,const Sales_data &rhs)
{
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}

std::istream &read(std::istream &is,Sales_data &item)

{
  is >> item.bookNo >> item.units.sold >> item.sellingprice >> 
      item.saleprice;
  return is;  
}
std::ostream &print(std::ostream &os,const Sales_data &item)
{
  os << item.isbn() << " " << item.units_sold << " " << item.sellingprice
   << item.saleprice << " " << item.discount;
  return os;
}
 */
