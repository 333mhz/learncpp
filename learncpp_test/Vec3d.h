#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "Pot3d.h"

class Vec3d
{
private:
    double m_x,m_y,m_z;

public:
    Vec3d(double x = 0.0,double y = 0.0,double z = 0.0):m_x(x),m_y(y),m_z(z){}

    void prt();

    friend void Pot3d::movByVec(const Vec3d &vec);
};

#endif