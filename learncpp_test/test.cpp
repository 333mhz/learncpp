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
int main()
{
	myString02();
	return 0;
}