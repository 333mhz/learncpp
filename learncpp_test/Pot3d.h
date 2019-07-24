#ifndef POINT3D_H
#define POINT3D_H

class Vec3d;

class Pot3d
{
private:
    double m_x,m_y,m_z;

public:
    Pot3d(double x = 0.0,double y = 0.0,double z = 0.0):m_x(x),m_y(y),m_z(z){}

    void prt();

    void movByVec(const Vec3d &vec);
};

#endif