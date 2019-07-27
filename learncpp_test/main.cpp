#include "header.h"
#include "randomMonsterGenerator.h"

void sortArr(array<int,g_arrayElements> &arr)
{
	for(int si = 0;si < g_arrayElements-1;si++)
	{
		int min = si;

		for(int ci = si+1;ci < g_arrayElements; ci++ )
		{
			if(arr[ci] < arr[si])
				min = ci;
		}
	

	swap(arr[si], arr[min]);
	}
}


double dist2(Pnt2d &p1,Pnt2d &p2)
{   return sqrt(pow((p1.m_x - p2.m_x),2)+pow((p1.m_y - p2.m_y),2));    }

int main()
{
	Timer t;

	RMG Bones(RMG::SKELETON,"Bones","haha",3);

	Bones.prt(Bones);

	return 0;
}