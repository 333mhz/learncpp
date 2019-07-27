#ifndef RMG_H
#define RMG_H

#include "header.h"

class RMG
{
    public:
    enum MonsterType
    {
        DRAGON,
        GOBLIN,
        OGRE,
        ORC,
        SKELETON,
        TROLL,
        VAMPIRE,
        ZOMBIE,
        MAX_MONSTER_TYPES
    };
    string getMT()
    {
	switch(m_t)
    {
        case DRAGON: return "dragon";
        case GOBLIN: return "goblin";
        case OGRE:   return "orge";
        case ORC:    return "orc";
        case SKELETON:return "skeleton";
        case TROLL: return "troll";
        case VAMPIRE:return "vampire";
        case ZOMBIE:return "zombie";
    }
    return "unknow";
    }

    private:
    MonsterType m_t;
    string m_name;
    string m_roar;
    int m_health;

    public:
    RMG(MonsterType t, string n, string r, int hp):
    m_t(t), m_name(n), m_roar(r), m_health(hp)
    {
    }

    void prt(RMG &m)
    {
        cout << m.m_name <<" the "<< m.getMT() <<" has "<<m.m_health<< " hit points and roars: "<<m.m_roar<<endl;
    }
};

#endif