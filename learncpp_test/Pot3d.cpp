#include <iostream>
#include "Pot3d.h"
#include "Vec3d.h"

using namespace std;

void Pot3d::prt()
{
    cout << "Point(" << m_x<<","<< m_y<<","<< m_z<<")\n";
}

void Pot3d::movByVec(const Vec3d &vec)
{
    m_x += vec.m_x;
    m_y += vec.m_y;
    m_z += vec.m_z;
}

