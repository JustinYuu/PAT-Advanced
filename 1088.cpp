#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

typedef struct
{
    ll up,down;
}ration;

ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

ration reduction(ration a)
{
    if(a.down<0)
    {
        a.up = -a.up;
        a.down = -a.down;
    }
    if(a.up==0)
        a.down = 1;
    else
    {
        ll c = gcd(abs(a.up),abs(a.down));
        a.up/=c;
        a.down/=c;
    }
    return a;
}

ration rat_plus(ration a,ration b)
{
    ration c;
    c.up = a.up * b.down + a.down * b.up;
    c.down = a.down * b.down;
    c = reduction(c);
    return c;
}

ration rat_minus(ration a,ration b)
{
    ration c;
    c.up = a.up * b.down - a.down * b.up;
    c.down = a.down * b.down;
    c = reduction(c);
    return c;
}

ration rat_multi(ration a,ration b)
{
    ration c;
    c.up = a.up * b.up;
    c.down = a.down * b.down;
    c = reduction(c);
    return c;
}

ration rat_divide(ration a,ration b)
{
    ration c;
    swap(b.down,b.up);
    c.up = a.up * b.up;
    c.down = a.down * b.down;
    c = reduction(c);
    return c;
}

void rat_print(ration a)
{
    if(a.down==1)
    {
        if(a.up>=0)
            printf("%lld",a.up);
        else
            printf("(%lld)",a.up);
    }
    else if(a.down==0)
        printf("Inf");
    else
    {
        if(abs(a.up)>a.down)
        {
            if(a.up*a.down>0)
                printf("%lld %lld/%lld",a.up/a.down,a.up%a.down,a.down);
            else
                printf("(%lld %lld/%lld)",a.up/a.down,abs(a.up%a.down),a.down);
        }
        else
        {
            if(a.up*a.down>0)
                printf("%lld/%lld",a.up,a.down);
            else
                printf("(%lld/%lld)",a.up,a.down);
        }
    }
}

int main()
{
    ration a,b;
    scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);
    a=reduction(a);
    b=reduction(b);
    for(int i=1;i<=4;++i)
    {
        rat_print(a);
        if(i==1)
            printf(" + ");
        else if(i==2)
            printf(" - ");
        else if(i==3)
            printf(" * ");
        else
            printf(" / ");
        rat_print(b);
        printf(" = ");
        if(i==1)
            rat_print(rat_plus(a,b));
        else if(i==2)
            rat_print(rat_minus(a,b));
        else if(i==3)
            rat_print(rat_multi(a,b));
        else
            rat_print(rat_divide(a,b));
        printf("\n");
    }
    return 0;
}
