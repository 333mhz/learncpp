#include "stdafx.hpp"
#include "1_C++_Review.hpp"

int main()
{
    //int a[3]={4,6,8};
    //prtSubset(a,NULL,0,3);
    for(int i=0;i<(1<<3);i++)
        prtSubsetB(3,i);

    return 0;
}