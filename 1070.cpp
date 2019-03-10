#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;
typedef struct
{
    double am,pr,ep;
}mk;

int cmp(mk a,mk b)
{
    return a.ep>b.ep;
}
int main()
{
    int n,d;
    double sum=0;
    mk p[maxn];

    cin>>n>>d;
    for(int i=0;i<n;++i)
        scanf("%lf",&p[i].am);
    for(int i=0;i<n;++i)
    {
        scanf("%lf",&p[i].pr);
        p[i].ep=p[i].pr/p[i].am;
    }
    sort(p,p+n,cmp);
    for(int i=0;i<n;++i)
    {
        if(p[i].am<d)
        {
            d-=p[i].am;
            sum+=p[i].pr;
        }
        else
        {
            p[i].am-=d;
            sum+=p[i].ep*d;
            break;
        }
    }
    printf("%.2f",sum);
    return 0;
}
