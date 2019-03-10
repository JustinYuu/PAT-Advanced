#include <iostream>
#include <cstdio>
using namespace std;

typedef struct
{
    long long int nu,de;
}ratnum;

int gcd(long long int a,long long int b)
{
    if(!b)
        return a;
    else
        return gcd(b,a%b);
}
ratnum reduction(ratnum res)
{
    if(res.de<0)
    {
        res.nu = -res.nu;
        res.de = -res.de;
    }
    if(res.nu==0)
        res.de=1;
    else
    {
        int d = gcd(abs(res.nu),abs(res.de));
        res.nu/=d;
        res.de/=d;
    }
    return res;
}
ratnum rat_plus(ratnum a,ratnum b)
{
    ratnum c;
    c.nu = a.nu*b.de + a.de*b.nu;
    c.de = a.de*b.de;
    return reduction(c);
}


int main()
{
    int n;
    ratnum fir,pls;
    scanf("%d",&n);
    scanf("%lld/%lld",&fir.nu,&fir.de);
    for(int i=1;i<n;++i)
    {
        scanf("%lld/%lld",&pls.nu,&pls.de);
        fir = rat_plus(fir,pls);
    }
    long long int coef;
    coef = abs(fir.nu)/fir.de;
    fir = reduction(fir);       // quite important to pass test point 4!
    if(fir.de==1)
        printf("%lld",fir.nu);
    else
    {
        if(abs(fir.nu)>fir.de)
            printf("%lld %lld/%lld",fir.nu/fir.de,abs(fir.nu)%fir.de,fir.de);
        else
            printf("%lld/%lld",fir.nu,fir.de);
    }
    return 0;
}
