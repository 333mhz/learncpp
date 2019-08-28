#include "header.h"
#include "func_Template.h"
template<typename type>

const type& max(const type& x,const type& y)
{
    return (x>y)?x:y; 
}

int main()
{
    
    double i = max(1.234,2.3456);
    cout << i;

}