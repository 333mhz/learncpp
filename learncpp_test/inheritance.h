#ifndef INHERITANCE_H
#define INHERITANCE_H

#include "header.h"

class Person
{
private:
    string m_name;
    int m_age;
public:
    Person(string n = "UNKNOW",int a = -1):m_name(n),m_age(a)
    {
    }

    string getName()const{return m_name;}
    int getAge()const{return m_age;}
};

class BaseballPlayer:public Person
{
private:
    double m_battingAverage;
    int m_homeRuns;
public:
    BaseballPlayer(string n,int a,double ba = 0.0,int hr =0):Person(n,a),m_battingAverage(ba),m_homeRuns(hr)
    {}

    double getBattingAverage() const { return m_battingAverage; }
    int getHomeRuns() const { return m_homeRuns; }
};

class A
{
public:
    A(int a)
    {
        std::cout << "A: " << a << '\n';
    }
};
 
class B: public A
{
public:
    B(int a, double b)
    : A(a)
    {
        std::cout << "B: " << b << '\n';
    }
};
 
class C: public B
{
public:
    C(int a , double b , char c)
    : B(a, b)
    {
        std::cout << "C: " << c << '\n';
    }
};
 

class Base
{
    private:
   int m_id;

    public:
    Base(int id=0)
        : m_id(id)
    {
    }
 
    int getId() const { return m_id; }

    friend std::ostream& operator<< (std::ostream &out, const Base &b)
	{
		out << "In Base\n";
		out << b.m_id << '\n';
		return out;
	}
};

class Derived: public Base
{
private:
    double m_cost;

public:
    Derived(double cost=0.0, int id = 0)
        : m_cost(cost), Base(id)
    {
    }
 
    double getCost() const { return m_cost; }

    friend std::ostream& operator<< (std::ostream &out, const Derived &d)
	{
		out << "In Derived\n";
		// static_cast Derived to a Base object, so we call the right version of operator<<
		out << static_cast<Base>(d); 
		return out;
	}
};

class Fruit
{
    private:
    string m_name;
    string m_color;

    public:
    Fruit(string n,string c):m_name(n), m_color(c)
    {
    }

    const string getName() const
    {
        return m_name;
    }
    const string getColor() const
    {
        return m_color;
    }
};

class Apple:public Fruit
{
    private:
    double m_fiber;

    public:
    Apple(string n = "Apple", string c = "Red", double f = 0.0):Fruit(n,c),m_fiber(f)
    {}

    friend ostream& operator<<(ostream& out,const Apple& a)
    {
        out << "Apple("<<a.getColor()<<","<<a.m_fiber<<")"<<endl;

        return out;
    }
};

class Banana:public Fruit
{
    private:
    public:
    Banana(string n = "Banana", string c = "Yellow"):Fruit(n,c)
    {}
    friend ostream& operator<<(ostream& out,const Banana& b)
    {
        out << "Banana("<<","<<b.getColor()<<")"<<endl;

        return out;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////

class Creature
{
protected:
    string m_name;
    char m_symbol;
    int m_health;
    int m_attack;
    int m_gold;

public:
    Creature(string n = "Unknow",char s = ' ',int h = 1,int a = 1,int g = 0)
    :m_name(n),m_symbol(s),m_health(h),m_attack(a),m_gold(g)
    {}

    const string & getName() const {return m_name;}
    char getSym() const{  return m_symbol;  }
    int getHp() const{  return m_health;  }
    int getAtk() const{  return m_attack;  }
    int getGold() const{  return m_gold;  }

    void reduceHp(int r){ m_health -= r;}
    bool isDead(){  return m_health <= 0;  }
    void addGold(int a){ m_gold += a;}

    friend ostream& operator<<(ostream& out,const Creature& c)
    {
        out << "The "<<c.m_name<<" has "<<c.m_health <<" health and is carrying " << c.m_gold << " gold.\n";
        return out;
    }
};

class Player:public Creature
{
private:
    int m_level;
public:
    Player(string n = "?",char s = '@',int h = 10,int a = 1,int l = 1)
    :Creature(n,s,h,a),m_level(l)
    {}
    int getLv()const{return m_level;}
    bool isWon(){return m_level>=20;}

    void levelUp()
    {
        Creature::m_attack++;
        Creature::m_health++;
        m_level++;
        cout << "Brave "<<m_name<<"is now level "<<m_level<<endl;
    }

    friend ostream& operator<<(ostream& out,const Player& p)
    {
        out << "Brave "<<p.getName()<<" has "<<p.getHp() <<" health and is carrying " << p.getGold() << " gold.\n";
        return out;
    }

};

Player InitPlayer()
{ 
    string name;
    while(name.size() == 0)
    {
        cout << "Enter your name: ";
        cin >> name;
    }   
    Player p(name);
    return p;    
}
class Monster:public Creature
{
    public:
    enum mType
    {
        DRAGON,
        ORC,
        SLIME,
        GOBLIN,
        MAX_TYPES
    };
    struct MonsterData
	{
		const char* name;
		char symbol;
		int health;
		int damage;
		int gold;
	};

    static MonsterData monsterData[MAX_TYPES];

    mType m_type;
    Monster(mType type = SLIME)
		: Creature(monsterData[type].name, monsterData[type].symbol, 
                   monsterData[type].health, monsterData[type].damage,
                   monsterData[type].gold), 
                   m_type(type)
	{
        
    }
    
    friend ostream& operator<<(ostream& out,const Monster& m)
    {
        out << "A "<<m.getName()<<" has "<<m.getHp() <<" health and is carrying " << m.getGold() << " gold.\n";
        return out;
    }

};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 16, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 },
    { "goblin", 'g', 2, 1, 15 }
};

// static Monster getRandomMonster()
// {
//     Random mseed(0,Monster::MAX_TYPES-1);
//     return Monster( static_cast<Monster::mType>( mseed.getRandomNumber() ) );
// }

class SimpleGame:public Player,public Monster
{
private:

public:
    SimpleGame()
    :Player("alex"),Monster()
    {
        cout<< "Enter your name: (defalut: alex)\n";
        cin >> Player::m_name;
        cout << static_cast<Player>(*this);
    }

    bool playerAttackedBy(Monster &m)
    {
        Player::reduceHp(m.getAtk());
        cout <<"Brave "<<Player::getName()<<" suffer "<<m.getAtk()<<"damage,\n";
        if(static_cast<Player>(*this).isDead())
            return true;
        else 
            return false;
    }

    bool playerAttack(Monster &m)
    {
        m.reduceHp(static_cast<Player>(*this).getAtk());
        cout <<m.getName()<<" gain "<<Player::getAtk()<<"damage,\n";
        if(m.isDead())
        {
            Player::levelUp();
            Player::addGold(m.getGold());
            cout << static_cast<Player>(*this);
            return true;
        }
        else 
            return false;
    }
    
    int isFight(int r)
    {
        cout << "(R)un or (F)ight:";
        char n = ' ';

        while ( n != 'R' && n != 'F' && n != 'r' && n != 'f')
        {
            n = ' ';
            cin >> n;
        }

        if( n == 'F' || n == 'f')
        {
            return 2;
        }    
        else if(r == 1)
        {
            cout << "Escape Failure\n";
            return 1;
        }
        else
        {
            cout << "Escape Success\n";
            return 0;
        }        
    }

    bool deadOrAlive()
    {
        Random mseed(0,Monster::MAX_TYPES-1);
        cout <<"Brave "<<Player::m_name <<" enter the dungeon.\n";
        Monster m;
        while( true )
        {

            if(static_cast<Player>(*this).isWon())
                return true;
            else if(static_cast<Player>(*this).isDead())
                return false;

            m = Monster( static_cast<Monster::mType>( mseed.getRandomNumber() ) );

            cout << "Brave " << static_cast<Player>(*this).getName()<<" encounter "<<m.getName()<<endl;
            
            int fight = 1;
            while( fight )
            {   
                fight = isFight(mseed.getRandomNumber());
                if(fight == 2)
                {
                    if(playerAttack(m))
                        break;
                }
                if(fight >= 1)
                {
                    if(playerAttackedBy(m))
                        break;
                }
            }

        }
    }
};

#endif

