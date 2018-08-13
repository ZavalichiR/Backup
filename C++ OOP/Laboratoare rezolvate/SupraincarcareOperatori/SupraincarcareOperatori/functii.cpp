#include"Header.h"

complex::complex(int x, int y)
{
	re =  x;
	im = y;
}
complex::complex()
{
	re = 0; im = 0;
}
complex::complex(complex &c)
{
	re = c.re;
	im = c.im;
}
void complex::afisare()
{
	cout << re << "+" << "("<<im << "*i)" << endl;

}


//complex& complex::operator=(complex &c)
//{
//	re = c.re;
//	im = c.im;
//	return *this;
//}
//void complex::operator=(complex &c)
//{
//	this->re = c.re;
//	this->im = c.im;
//}
complex complex::operator=(complex c)
{
	complex tmp(*this);
	tmp.re = c.re;
	tmp.im = c.im;
	return tmp;


}

complex complex::operator+(complex &c)
{
	complex tmp(*this);  
	tmp.re = tmp.re + c.re;
	tmp.im = tmp.im + c.im;
	return tmp;
	
}
/*complex operator+(complex &c1, complex &c2)
{
	complex tmp(c1);//tmp=c1

	tmp.re = tmp.re + c2.re;
	tmp.im = tmp.im + c2.im;
	return tmp;
}
*/

complex complex::operator-(complex &c)
{
	complex tmp(*this);
	tmp.re = tmp.re - c.re;
	tmp.im = tmp.im - c.im;
	return tmp;
}
/*complex operator-(complex &c1, complex &c2)
{
	complex tmp(c1);
	tmp.re = tmp.re - c2.re;
	tmp.im = tmp.im - c2.im;
	return tmp;
}
*/

//(a,b)*(c,d)=(ac-bd,bc+ad)
complex complex::operator*(complex &c)
{
	complex tmp(*this);
	tmp.re = tmp.re*c.re - tmp.im*c.im;
	tmp.im = tmp.im*c.re + tmp.re*c.im;
	return tmp;
}
/*complex operator*(complex &c1, complex &c2)
{
	complex tmp(c1);
	tmp.re = tmp.re*c2.re - tmp.im*c2.im;
	tmp.im = tmp.im*c2.re + tmp.re*c2.im;
	return tmp;
}
*/

complex& complex::operator++()
{
	re = re + 1;
	im = im + 1;
	return *this;
}
/*complex& operator++(complex &c)
{
	c.re = c.re + 1;
	c.im = c.im + 1;
	return c;
}
*/

complex complex::operator++(int)
{
	complex tmp(*this);
	tmp.re = re + 1;
	tmp.im = im + 1;
	return tmp;
}
/*complex operator++(complex &c, int)
{
	complex tmp(c);
	tmp.re = tmp.re +1;
	tmp.im = tmp.im +1;
	return c;
}
*/

complex& complex::operator--()
{
	re = re - 1;
	im = im - 1;
	return *this;
}
/*complex& operator--(complex &c)
{
	c.re = c.re - 1;
	c.im = c.im - 1;
	return c;
}
*/
complex complex::operator--(int)
{
	complex tmp(*this);
	tmp.re = re - 1;
	tmp.im = im - 1;
	return tmp;
}
/*complex operator--(complex &c, int)
{
	complex tmp(c);
	tmp.re = tmp.re - 1;
	tmp.im = tmp.im - 1;
	return c;
}
*/

std::istream& operator>>(std::istream& input, complex &c)
{
	cout << "Re: ";
	input >> c.re;
	cout << "Im: ";
	input >> c.im;
	return input;
}
std::ostream& operator<<(std::ostream& output, complex &c) 
{
	return output << c.re << "+(" << c.im << "*j)" << endl;
}