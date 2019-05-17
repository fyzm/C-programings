#include<iostream>
using namespace std;

class Quote
{
  public:
    Quote()=default;
    Quote(const std::string &book,double sales_price):
                  bookNo(book),price(sales_price){}
    std::string isbn() const{return bookNo;}
    virtual double net_price(std::size_t n)const {return n*price;}
    virtual ~Quote()=default;                  
  private:
    std::string bookNo;
  protected:
    double price=0.0;
};

double print_total(ostream &os,const Quote &item,size_t n)
{
  double ret = item.net_price(n);
  os << "ISBN:" << item.isbn() << "# sold:" << n <<"total due:"
      << ret <<endl; 
  return ret;
}

class Bulk_quote : public Quote
{
  public:
    double net_price( size_t cnt) const override
    {
      if(cnt >= min_qty)
          return cnt * (1-discount) * price;
      else
          return cnt * price;
    }
  private:
    size_t min_qty;
    double discount;
};

class Limited_quote:public Quote
{
  public:
    double net_price(size_t cnt) const override
    {
      if(cnt <=min_qty)
        return cnt * (1-discount) * price;
      else
        return min_qty * (1-discount) * price + (cnt - min_qty) * price;
    }
  private:
    size_t min_qty;
    double discount;
};


























