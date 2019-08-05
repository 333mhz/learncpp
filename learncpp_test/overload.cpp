#include "overload.h"

    Fraction operator*(const Fraction f1, const Fraction f2)
    {
        return Fraction(f1.getNume() * f2.getNume(), f1.getDeno() * f2.getDeno());
    }

    Fraction operator*(const Fraction f1, int a)
    {
        return Fraction(f1.getNume() * a, f1.getDeno());
    }
    
    Fraction operator*(int a, const Fraction f1)
    {
        return Fraction(a * f1.getNume() , f1.getDeno());
    }