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

    private:
    MonsterType m_t;
    string m_name;
    string m_roar;
    int m_health;


    public:

    string getMT() const
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

    RMG(MonsterType t, string n, string r, int hp):
    m_t(t), m_name(n), m_roar(r), m_health(hp)
    {
    }

    void prt() const
    {
        cout << m_name <<" the "<< getMT() <<" has "<< m_health<< " hit points and roars: "<< m_roar <<endl;
    }

};

class mGenerator
{
    public:
    static int getRandNum(int min, int max)
    {
        static const double frac = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

        return static_cast<int>(rand() * frac * (max - min + 1) + min);
    }
    static RMG gm()
    {
        RMG::MonsterType mt = static_cast<RMG::MonsterType>(getRandNum(0, RMG::MAX_MONSTER_TYPES - 1));

        static const string r_name[7]{"HELIX", "MOOG", "PIXIE","DALAX", "PULA", "NOIX", "SKII"};
        static const string r_roar[7]{"*lalala*", "*hahaha*", "*papapa*", "*dadada*", "*rarara*", "*kakaka*", "*wawawa*"};

        return RMG(mt, r_name[getRandNum(0,6)], r_roar[getRandNum(0,6)], getRandNum(1,100));
    }

};

#endif