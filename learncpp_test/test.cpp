#include "header.h"
#include "virtual_Functions.h"

int main()
{
    covariantReturnTypesD d;
	covariantReturnTypes *b = &d;
	d.getThis()->printType(); // calls Derived::getThis(), returns a Derived*, calls Derived::printType
	b->getThis()->printType(); // calls Derived::getThis(), returns a Base*, calls Base::printType
    
    return 0;
}