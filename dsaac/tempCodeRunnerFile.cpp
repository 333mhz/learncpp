template<class T> 
bool change1dLength(T * x, int d1,int nd1)
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
int main()
{
    /*
    char ** a2d;
    int a[5] = {1,2,3,4,5};
    cout << (make2dArray(a2d,5,a)?"Success":"Fail")<<endl;
    */
   int i[8] = {0,1,2,3,4,5,6,7};
   cout << i[4]<<endl;
   change1dLength(i,8,4);
   cout << i[4]<<endl;
   //cout << (i)[4] <<endl;

    return 0;
}