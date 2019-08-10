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
int main()
{
	average();
	return 0;
}