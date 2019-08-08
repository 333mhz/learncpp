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
int main()
{
	MyString ms = 'x';

	cout << ms;
	return 0;
}