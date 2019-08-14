#include "object_relationship.h"

void Doctor::addPat(Patient* p)
{
    m_pat.push_back(p);

    p->addDoc(this);
}

ostream& operator<<(ostream& out,const Doctor &d)
{
    unsigned int length = d.m_pat.size();

    if(length == 0)
    {
        out << d.m_name<<" has no patients right now.";
        return out;
    }

    out <<d.m_name<<" is taking patients: ";
    for(unsigned int i = 0;i < length;i++)
        out<<d.m_pat[i]->getName()<<' ';
    
    return out;
}

ostream& operator<<(ostream& out,const Patient &p)
{
    unsigned int length = p.m_doc.size();

    if(length == 0)
    {
        out << p.m_name<<" has no doctor right now.";
        return out;
    }

    out <<p.m_name<<" is taken by: ";
    for(unsigned int i = 0;i < length;i++)
        out<<p.m_doc[i]->getName()<<' ';
    
    return out;
}

Car CarLot::s_carlot[4] = {Car("A",3),Car("B",16),Car("C",5),Car("D",7)};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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


void patAndDoc()
{
    // Create a Patient outside the scope of the Doctor

    Patient *p1 = new Patient("Dave");
    Patient *p2 = new Patient("Frank");
    Patient *p3 = new Patient("Betsy");

    Doctor *d1 = new Doctor("James");
    Doctor *d2 = new Doctor("Scott");

    d1->addPat(p1);
    d2->addPat(p1);
    d2->addPat(p3);

    std::cout << *d1 << '\n';
    std::cout << *d2 << '\n';
    std::cout << *p1 << '\n';
    std::cout << *p2 << '\n';
    std::cout << *p3 << '\n';

    delete p1;
    delete p2;
    delete p3;
    delete d1;
    delete d2;
}

void CarNDrv()
{
    Driver d("Franz", 7); // Franz is driving the car with ID 17
    Car *car = CarLot::getCar(d.getCarid()); // Get that car from the car lot

    if (car)
        std::cout << d.getName() << " is driving a " << car->getName() << '\n';
    else
        std::cout << d.getName() << " couldn't find his car\n"; 
}
