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
	// Create a teacher outside the scope of the Department
    Teacher *t1 = new Teacher("Bob"); // create a teacher
    Teacher *t2 = new Teacher("Frank");
    Teacher *t3 = new Teacher("Beth");
 
    {
        // Create a department and use the constructor parameter to pass
        // the teacher to it.
        Department dept; // create an empty Department
        dept.add(t1);
        dept.add(t2);
        dept.add(t3);
 
        std::cout << dept;
 
    } // dept goes out of scope here and is destroyed
 
    std::cout << t1->getName() << " still exists!\n";
    std::cout << t2->getName() << " still exists!\n";
    std::cout << t3->getName() << " still exists!\n";
 
    delete t1;
    delete t2;
    delete t3;
}
int main()
{
	teacherDepartment();
	return 0;
}