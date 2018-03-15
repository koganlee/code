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
private:
	double dreal;
	double dimag;
};
int main()
{
  Complex num(3,2);
  num.print();
  cout <<  num.getReal() << endl;
  cout <<  num.getImage() << endl;
  return 0;
}
