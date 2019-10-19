#ifndef CXX_REVIEW
#define CXX_REVIEW
//1-1

//1-2
template<class T>
int countvalue(T* a,int length, T value)
{
    if(length < 1)
        throw "Array length should be > 0";
    int count=0;
    for(int i = 0;i<length;++i)
    {
        if(a[i] == value)
            ++count;
    }
    return count;
}

//1-3
template<class T>
bool fillarray(T* a,int start,int end,const T& value)
{
    bool bValue = true;
    for(int i = start;i<end;++i)
    { 
        a[i] = value;
        if(a[i] != value)
            bValue = false;
    }    
    return bValue;
}

//1-4
template<class T>
T inner_product(T *a,T *b,int length)
{
    T sum = 0;
    for(int i = 0;i < length;++i)
        sum += (a[i]+b[i]);
    
    return sum;
}

//1-5
template<class T>
void iota(T* a,int length,const T& value)
{
    for(int i = 0; i<length; ++i)
    { 
        a[i] = value + i;
    }    
}

//1-6
template<class T>
bool is_sorted(T* a,int length)
{
    bool bValue = false;
    for(int i = 0;i < length-1; ++i)
        if(a[i] < a [i+1] || a[i] == a [i+1])
        {
            bValue = true;
        }
        else
        {
            bValue = false;
            break;
        }

    if(bValue)
        return bValue;
    
    for(int i = 0;i < length-1; ++i)    
        if(a[i] > a [i+1] || a[i] == a [i+1])
        {
            bValue = true;
        }
        else
        {
            bValue = false;
            break;
        }
    
    return bValue;  
}

//1-7
template<class T>
int mismatch(T* a, T* b, int n)
{// Return smallest i such that a[i] != b[i].
 // Return n if no such i.
   for (int i = 0; i < n; i++)
      if (a[i] != b[i])
         return i;

   // no mismatch
   return n;
}

//1-8

//1-9

//1-10
int abcthrow(int a,int b,int c)
{
    if(a <= 0 || b <= 0 || c <= 0)
    {       
        throw (a < 0 || b < 0 || c < 0)? 1 : 2;
    }
}

//1-11

//1-12
template<class T> 
bool make2dArray(T ** &x, int d1, int d2)
{
    try
    {
        //Create dimension 1st
        x = new T* [d1];
        //Create dimension 2nd
        for(int i = 0;i < d1;++i)
            x[i] = new T[d2];
        
        return true;
    }
    catch(bad_alloc)
    {
        std::cerr << "Out of memory,fail to alloc 2D array" << '\n';
        return false;
    } 
}

template<class T> 
bool make2dArray(T ** &x, int d1, int* &d2)
{
    try
    {
        //Create dimension 1st
        x = new T* [d1];
        //Create dimension 2nd
        for(int i = 0;i < d1;++i)
            x[i] = new T[d2[i]];
        
        return true;
    }
    catch(bad_alloc)
    {
        std::cerr << "Out of memory,fail to alloc 2D array" << '\n';
        return false;
    }  
}

//1-13
template<class T> 
bool change1dLength(T * &x, int d1,int nd1)
{
    if(nd1 < 0)
        throw "illegalParameterValue: new length must be >= 0";
    try
    {   
        T* tmp = new T[nd1];
        int n = min(d1,nd1);
        //Create dimension 2nd
        //for(int i = 0;i < n;++i)
        //    tmp[i] = x[i];
        //delte[] x;
        //x = tmp;
        copy(x,x+n,tmp);
        delete[] x;
        x = tmp;
        return true;
    }
    catch(bad_alloc)
    {
        std::cerr << "Out of memory,fail to change array 1d length" << '\n';
        return false;
    }  
}

//1-14
template<class T> 
bool change2dLength(T ** &x, int d1, int d2, int nd1 , int nd2)
{
    if(nd1 < 0 || nd2 < 0)
        throw "illegalParameterValue: new length must be >= 0";
        
    try
    {   
        T** tmp = new T* [nd1];
        for(int i = 0;i < nd1; ++i)
            tmp[i] = new T[nd2];

        int n1 = min(d1,nd1);
        int n2 = min(d2,nd2);

        for(int i = 0;i < n1; ++i)
            copy(x[i],x[i]+n2, tmp[i]);

        for(int i = 0;i < d1;++i)
            delete[] x[i];
        delete[] x;

        x = tmp;

        return true;
    }
    catch(bad_alloc)
    {
        std::cerr << "Out of memory,fail to change array 1d length" << '\n';
        return false;
    }  
}

//1-15
//(1)4bytes = 32 bits.2^32-1 
//maxium = 2^32-1 dollars + 99 cents 
//minium = -2^32-1 dollars + 99 cents 
//(2)
//maxium = 2^31-1 dollars + 99 cents 
//minium = -2^31-1 dollars + 99 cents 
//(3)
//maxium = (2^31-1)/100

//1-16
enum signType{plus, minus};
/*
struct USD
{
    USD()
    {
        m_sign = plus;
        m_dollar = 0;
        m_cent = 0;
    }
    signType m_sign;
    unsigned long m_dollar;
    unsigned int m_cent;
};
*/
class currency
{
    private:
    signType m_sign;
    unsigned long m_dollar;
    unsigned int m_cent;

    public:
    currency():m_sign(plus), m_dollar(0), m_cent(0)
    {  }
    ~currency(){  }

    void setValue(signType, unsigned long, unsigned int);
    void setValue(double);
};
#endif 