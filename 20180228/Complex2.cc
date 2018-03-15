 ///
 /// @file    Complex.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-03 16:18:51
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Complex
{
public:
	Complex(double x = 0, double y = 0) : dreal(x), dimag(y) 
	{
       cout << "initial.\n";
	}
	void print() const
	{
		cout << "real:" << dreal << " dimag:" << dimag  << "i" << endl;
    }
	double getReal() const 
	{
		return dreal;
	}
	double getImage() const
	{
		return dimag;
	}
	Complex & operator+=(const Complex &c)
	{
       this -> dreal+= c.dreal; 
	   this -> dimag+= c.dimag;
	   return *this;
	}
private:
	double dreal;
	double dimag;
};
int main()
{
  Complex num1(3,2);
  Complex num2(2,3);
  Complex num3;
  num1.print();
  cout <<  num1.getReal() << endl;
  cout <<  num1.getImage() << endl;
  num3 = num1 += num2;
  num1.print();
  cout << "num 3" << endl;
  num3.print();

  return 0;
}
