#include "header.h"
#include "randomMonsterGenerator.h"

double dist2(Pnt2d &p1,Pnt2d &p2)
{   return sqrt(pow((p1.m_x - p2.m_x),2)+pow((p1.m_y - p2.m_y),2));    }

int main()
{
	Timer t;

	RMG m = mGenerator::gm();

	m.prt();

	return 0;
}