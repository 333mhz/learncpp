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

int main()
{

	// Cents cents1(7);
	// Cents cents2(8);
	// Cents cents3(9);
	// Cents centsSum = cents1 - cents2 + cents3;
	// std::cout << "I have " << centsSum.getCents() << " cents." << std::endl;

	Fraction f1(6,8);
	Fraction f2;
	cin >> f2;
	Fraction fx = - f1 * f2 * 7;

	cout << f1 << " x " << f2 << " x 7 "<< " = " << fx ;

	fx = - fx;
	cout << fx;

	fx = + fx;
	cout << fx;

	return 0;
}