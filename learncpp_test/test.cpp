#include "header.h"
#include "overload.h"

Fraction operator*(const Fraction f1, const Fraction f2)
{
    return Fraction(f1.getNume() * f2.getNume(), f1.getDeno() * f2.getDeno());
}


    
Fraction operator*(int a, const Fraction f1)
{
    return Fraction(a * f1.getNume() , f1.getDeno());
}

void prtDouble(double x){ cout << x;}

void prtCents(Cents c){ cout << c; }

Fraction mkNega(Fraction f)
{
	f.setNume(-f.getNume());

	return f;
}

void myString01()
{
	MyString alex("alex");
	cout << alex;
	MyString employee;
	employee = alex;
	cout << employee;
}
void myString02()
{
	MyString alex("alex");
	alex = alex;
	cout << alex;
}
void average()
{
	Average avg;
	
	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4
	
	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6
 
	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12
 
	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5
 
	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7
 
	Average copy = avg;
	std::cout << copy << '\n';
}

void fillArray()
{
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;
	
	//cout << a;

	auto &ref = a; // we're using this reference to avoid compiler self-assignment errors
	a = ref;
	
	IntArray b(3);
	b = a;
	cout << b;
}

void fixPoint2()
{
	FixedPoint2 a(34, 56);
	std::cout << a << '\n';
 
	FixedPoint2 b(-2, 8);
	std::cout << b << '\n';
 
	FixedPoint2 c(2, -8);
	std::cout << c << '\n';
 
	FixedPoint2 d(-2, -8);
	std::cout << d << '\n';
 
	FixedPoint2 e(0, -5);
	std::cout << e << '\n';
 
	std::cout << static_cast<double>(e) << '\n';

	FixedPoint2 f(0.01);
	std::cout << f << '\n';
 
	FixedPoint2 g(-0.01);
	std::cout << g << '\n';
 
	FixedPoint2 h(5.01); // stored as 5.0099999... so we'll need to round this
	std::cout << h << '\n';
 
	FixedPoint2 i(-5.01); // stored as -5.0099999... so we'll need to round this
	std::cout << i << '\n';
 
}

FixedPoint2 operator+(const FixedPoint2 &f1,const FixedPoint2 &f2)
{
    return (static_cast<double>(f1)+static_cast<double>(f2));
}
void testAddition()
{
        // h/t to reader Sharjeel Safdar for this method of testing
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.23) == FixedPoint2(1.98)) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.50) == FixedPoint2(2.25)) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.23) == FixedPoint2(-1.98)) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.50) == FixedPoint2(-2.25)) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.23) == FixedPoint2(-0.48)) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.50) == FixedPoint2(-0.75)) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.23) == FixedPoint2(0.48)) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.50) == FixedPoint2(0.75)) << '\n'; // first negative, possible decimal overflow

	FixedPoint2 a(-0.48); 
	std::cout << a << '\n';
 
	std::cout << -a << '\n';
 
	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;
	
	std::cout << "You entered: " << a << '\n';
}
int main()
{
	testAddition();
	return 0;
}