#ifndef SALES_DATA_H_INCLUDED
#define SALES_DATA_H_INCLUDED

#include<iostream>
#include<string>
using namespace std;

class Sales_data{
  friend std::istream& operator >> (std::istream&,Sales_data&);
  friend std::ostream& operator << (std::ostream&,const Sales_data&);
  friend bool operator < (const Sales_data&,const Sales_data&);
  friend bool operator == (const Sales_data&,const Sales_data&);
  public://构造函数的三种形式
    Sales_data() = default;
    Sales_data(const std::string &book): bookNo(book) {}
    Sales_data(const std::string &book,const unsigned num,const double sellp,const double salep);
    Sales_data(std::istream &is){is >> *this;}
  public:
    Sales_data& operator += (const Sales_data&);
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data &rhs)
    {
      units_sold += rhs.units_sold;//累计书的销量
      saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold) / (rhs.units_sold + units_sold);//重新计算实际销售价格
      if(sellingprice !=0)
        discount = saleprice / sellingprice;
      return *this; //返回合并后的结果
    }
  public:
    string bookNo;
    unsigned units_sold = 0;//销售量
    double sellingprice = 0.0;//原始价格
    double saleprice = 0.0;//实际价格
    double discount = 0.0;//折扣
};

inline bool compareIsbn(const Sales_data &lhs,const Sales_data &rhs)
{return lhs.isbn()== rhs.isbn();}
Sales_data::Sales_data(const std::string &book,const unsigned num,const double sellp,const double salep)
{
  bookNo = book;
  units_sold = num;
  sellingprice = sellp;
  saleprice = salep;
  if(sellingprice !=0){
    discount = saleprice /sellingprice;
  }
}
Sales_data operator +(const Sales_data&,const Sales_data&);
inline bool operator ==(const Sales_data &lhs,const Sales_data &rhs)
{
  return lhs.units_sold == rhs.units_sold && lhs.sellingprice == rhs.sellingprice
  && lhs.saleprice == rhs.saleprice && lhs.discount == rhs.discount;
}

inline bool operator !=(const Sales_data &lhs,const Sales_data &rhs)
{
  return !(lhs == rhs);
}

Sales_data& Sales_data::operator+= (const Sales_data& rhs)
{
  units_sold +=rhs.units_sold;
  saleprice = (rhs.saleprice*rhs.units_sold + saleprice * units_sold) / (rhs.units_sold + units_sold);
  if(sellingprice !=0)
    discount = saleprice / sellingprice;
  return *this;
}

Sales_data operator +(const Sales_data& lhs,const Sales_data& rhs)
{
  Sales_data ret(lhs);
  ret +=rhs;
  return ret;
}


Sales_data add(const Sales_data &lhs,const Sales_data &rhs)
{
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}

std::istream &read(std::istream &is,Sales_data &item)
{
  is >> item.bookNo >> item.units_sold >>item.sellingprice >> item.saleprice;
  return is;
}

std::ostream &print(std::ostream &os,const Sales_data &item)
{
  os << item.isbn() << " "<< item.units_sold <<""<<item.sellingprice <<" "<< item.saleprice << " " <<item.discount;
  return os;
}

std::istream& operator>>(std::istream& in,Sales_data& s)
{
  in >> s.bookNo >> s.units_sold >> s.sellingprice >> s.saleprice;
  if(in && s.sellingprice !=0)
    s.discount = s.saleprice / s.sellingprice;
  else
    s = Sales_data();
    return in;
}

std::ostream& operator <<(std::ostream& out,const Sales_data& s)
{
  out << s.isbn() << " " << s.units_sold << " "
      << s.sellingprice << s.saleprice << " "<< s.discount;
  return out;
}

#endif