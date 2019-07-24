#include "header.h"

class Fruit
{
public:
	// Note: we've moved FruitType inside the class, under the public access specifier
	enum FruitType
	{
		APPLE,
		BANANA,
		CHERRY
	};
    
    enum FruitTaste
    {
        SWEET,
        SOUR,
        FRAGRANT
    };

private:
	FruitType m_type;
    FruitTaste m_taste;
	int m_percentageEaten = 0;
  
public:
 
	Fruit(FruitType type,FruitTaste taste):m_type(type),m_taste(taste){}
 
	FruitType getType() { return m_type;  }
    FruitTaste getTaste() { return m_taste; }
	int getPercentageEaten() { return m_percentageEaten;  }
};
 
int main()
{
	// Note: we access the FruitType via Fruit now
	Fruit apple(Fruit::APPLE,Fruit::SWEET);
	
	if (apple.getType() == Fruit::APPLE)
		std::cout << "I am an apple\n";
	else
		std::cout << "I am not an apple\n";

	if (apple.getTaste() == Fruit::SWEET)
		std::cout << "It's sweet\n";
	else
		std::cout << "It's not sweet\n";
	return 0;
}