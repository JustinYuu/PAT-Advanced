#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

bool isprime(int a)
{
    if(a<2)
        return false;
    else if(a==2)
        return true;
    else
    {
        for(int i=2;i<=sqrt(a);++i)
            if(a%i==0)
                return false;
        return true;
    }
}
bool Hashtable[10010]={0};
int main()
{
    int msize,n;
    bool flag = false;

    cin>>msize>>n;
    while(!isprime(msize))
        msize++;
    for(int i=0;i<n;++i)
    {
        int tmp,pos,coef;
        cin>>tmp;
        pos = tmp%msize;
        coef = 1;
        while(Hashtable[pos]&&coef<msize)
        {
            pos=(tmp+coef*coef)%msize;
            coef++;
        }
        if(coef<msize)
        {
            Hashtable[pos]=true;
            if(flag)
                printf(" %d",pos);
            else
            {
                printf("%d",pos);
                flag=true;
            }
        }
        else
        {
            if(flag)
                printf(" -");
            else
            {
                printf("-");
                flag = true;
            }
        }
    }
    return 0;
}
