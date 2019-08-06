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
	GradeMap grades;

	char& gradeJoe = grades["Joe"]; // does a push_back

	gradeJoe = 'A';

	char& gradeFrank = grades["Frank"]; // does a push_back

	gradeFrank = 'C';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';

	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}