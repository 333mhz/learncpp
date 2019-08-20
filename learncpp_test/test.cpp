#include "header.h"
#include "inheritance.h"

int main()
{
      SimpleGame simplegame;
    
      if(simplegame.deadOrAlive())
          cout<<"Victory";
      else
          cout<<"Game Over";
    
    cin.get();
    cin.get();
    return 0;
}