#include "header.h"
#include "object_relationship.h"

void theCreature()
{
	std::cout << "Enter a name for your creature: ";
    std::string name;
    std::cin >> name;

    Creature c(name, Pnt2d(4, 7));
	cout << c << '\n';

    while (1)
    {
        // print the creature's name and location
        std::cout << c << '\n';

        std::cout << "Enter new X location for creature (-1 to quit): ";
        int x=0;
        std::cin >> x;
        if (x == -1)
            break;

        std::cout << "Enter new Y location for creature (-1 to quit): ";
        int y=0;
        std::cin >> y;
        if (y == -1)
            break;

        c.mov2(x, y);
    }
}

void teacherDepartment()
{
	Teacher *t = new Teacher("John");
	{
		Department dept(t);
	}
	cout << t->getName() << " still exists!";
    delete t;
}
int main()
{
	teacherDepartment();
	return 0;
}