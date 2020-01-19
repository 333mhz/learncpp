#ifndef CXX_REVIEW
#define CXX_REVIEW
#include "stdafx.hpp"
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
    return 0;
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
    friend istream& operator>>(ostream&,const currency&);
    friend ostream& operator<<(ostream&,const currency&);

    private:
    signType m_sign;
    unsigned long m_dollar;
    unsigned int m_cent;
    long amount;

    public:
    currency():m_sign(signType::plus), m_dollar(0), m_cent(0)
    {  }
    currency(signType s, unsigned long d, unsigned int c):m_sign(s), m_dollar(d), m_cent(c)
    {   if(m_cent >100)
            throw illegalParameterValue("Cents should be < 100");
        
        if(m_sign == signType::plus)
            amount = m_dollar*100+m_cent;
        else
            amount = -(m_dollar*100+m_cent);
    }
    ~currency(){  }

    void setValue(signType s, unsigned long d, unsigned int c)
    {  
        if(c >=100)
            throw illegalParameterValue("Cents should be < 100");
            
        if(s == signType::plus)
            amount = d*100+c;
        else
            amount = -(d*100+c);
    }

    void setValue(double);
    signType getSign() const{
        if(amount < 0) return signType::minus;
        else return signType::plus;
    }
    unsigned long getDollars() const{
        if(amount < 0 ) return (-amount)/100;
        else return amount/100;
    }
    unsigned int getCents() const{
        if(amount < 0) return (-amount)-getDollars()*100;
        else return amount-getDollars()*100;
    }
    currency operator+(const currency& x) const{
        currency result;
        result.amount = this->amount + x.amount;
        return result;
    }
    currency& operator+=(const currency& x){
        this->amount += x.amount;return *this;
    }
    void output(ostream& out)const{
        long theAmount = this->amount;
        if(theAmount < 0){
            out << '-';
            theAmount = - this->amount;
        }
        long dollars = theAmount/100;
        int cents = theAmount - dollars*100;
        if(cents <10)
            out <<'$'<<dollars<<".0"<<cents<<std::endl;
        else
            out <<'$'<<dollars<<'.'<<cents<<std::endl;
    }
};
    ostream& operator<<(ostream& out,const currency& x){
        x.output(out); return out;
    }

//recursive

int rFactorial(int n){
    std::cout<<"In:"<<n<<std::endl;
    if(n<=1){
        std::cout<<"1.Fin"<<std::endl;
        return 1;
    }
    else{
        int r = n*rFactorial(n-1);
        std::cout<<"Re:"<<r<<std::endl;
        return r;
    } 
}

template<class T>
T rSum(T a[],int n){
    if(n >0)
        return rSum(a,n-1)+a[n-1];
    
    return 0;
}
//1-32
template<class T>
void permutations(T list[],int k,int m)
{
    if(k == m){
        copy(list ,list + m+1,ostream_iterator<T>(cout,","));
        std::cout << endl;    
    }
    else{
        for(int i = k; i<= m;i++)
        {
            swap(list[k],list[i]);
            permutations(list,k+1,m);
            swap(list[k],list[i]);
        }
    }
}

//1e19
//1 1 2 3 5 8 13 21 34 55 
//f n = 
int fib(int n)
{
    if(n<=2)
    {
        return 1;
    }
    else {
        return fib(n-1)+fib(n-2);
    }
}

int isOddEven(int n)
{

    if(n<=0)
        return 0;

    if(n%2 == 0)
    {
        return 2;
    }
    else if(isOddEven(3*n+1) == 2)
    {
       return 1;
    }
    return 0;
}

template<class T>
bool isFound(T* a, T x,int n)
{
    if(n == 0)
        return false;
    else if(a[n-1] == x)
        return true;
    else
        return isFound(a, x,n - 1);  
}

//https://blog.csdn.net/a7055117a/article/details/48391923
//recursve????
template<class T>
int prtSubset(T *A, bool *B, int cur,int n)
{
    if(B == NULL)
    {   
        cout << "/0"<<endl;
        B = new bool[n];
    }    

    if(cur==n)//当设置完布尔数组内的全部元素后输出
    {
        for(int i = 0; i<n;i++)
        {
            if(B[i] == true)
                cout << A[i];
        }
        cout << endl;
    }
    else
    {
        B[cur] = true;//选第cur个元素
        prtSubset(A,B,cur + 1,n);
        B[cur] = false;//不选第cur个元素
        prtSubset(A,B,cur + 1,n);
    }
    
    return 0;
}

void prtSubsetB(bool *B,int n,int s)
{
     if(B == NULL)
    {   
        B = new bool[n];
    }    

    if(s == n)//当设置完布尔数组内的全部元素后输出
    {
        for(int i = 0; i<n;i++)
        {
            if(B[i] == true)
                cout << 1;
            else
                cout<<0;
            
        }
        cout << endl;
    }
    else
    {
        B[s] = true;//选第cur个元素
        prtSubsetB(B,n,s + 1);
        B[s] = false;//不选第cur个元素
        prtSubsetB(B,n,s + 1);
    }
    
    return;
}
void prtSubsetB2(int n)//输出子集s包含的元素
{
    for(int s=0;s<(1<<n);s++)
    {   
        for(int i=0;i<n;i++)
        {
            //<<把一个整型数的所有位向左移动指定的位数，移动到左边界之外的多余二进制位会被丢弃，并从右边界移入0
            if(s&(1<<i))//从最右侧开始遍历s中是否含有相应的元素
                cout << 1;
            else
                cout << 0;         
        }
        cout << endl;
    }
}

void greyflip(int n)
{
    if(n == 1)
        cout << 1;
    else
    {
        greyflip(n-1);
        cout << n;
        greyflip(n-1);
    }
    
}

void greycode(int n)
{

}

//STL
template<typename T>
T sum(T a[], int n)
{
    T tsum = 0;
    return accumulate(a,a+n,tsum);
}
template<typename T>
T product(T a[],int n)
{
    T theProduct = 1;
    return accumulate(a,a+n,theProduct,multiplies<T>());
}

template<typename T>
void npermutations(T list[],int k,int m)
{
    do{
        copy(list ,list+m+1,ostream_iterator<T>(cout,""));
        cout << endl;
    }while (next_permutation(list,list+m+1));
}

#endif 