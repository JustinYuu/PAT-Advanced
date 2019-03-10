#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct
{
    double dis,pri;
}station;

int cmp(station a,station b)
{
    if(a.dis!=b.dis)
        return a.dis<b.dis;
    else
        return a.pri<b.pri;
}
int main()
{
    double c,now=0.0,cur=0.0,d,avg,sum=0.0;
    int n,curind=0;
    station p[501];

    cin>>c>>d>>avg>>n;
    for(int i=0;i<n;++i)
    {
        cin>>p[i].pri>>p[i].dis;
    }
    sort(p,p+n,cmp);
    if(p[0].dis!=0)
    {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    while(cur<d)
    {
        bool flag=false;
        int i;
        for(i=curind+1;i<n;++i)
        {
            if(p[i].pri<p[curind].pri&&c*avg>=p[i].dis-p[curind].dis)
            {
                sum+=(p[i].dis-p[curind].dis)/avg*p[curind].pri;
                curind=i;
                flag=true;
                cur=p[i].dis;
                break;
            }
        }
        if(!flag)
        {
            if((d-p[curind].dis)<=c*avg)
            {
                sum+=(d-p[curind].dis)/avg*p[curind].pri;
                break;
            }
            sum+=p[curind].pri*(c-now);
            now = c;
            for(i=curind+1;i<n&&(p[i].dis-p[curind].dis)<=c*avg&&p[i].dis<d;++i)
            {
                cur=p[i].dis;
                now = c-(cur-p[curind].dis)/avg;
            }
            if(i==curind+1)
            {
                cur+=c*avg;
                printf("The maximum travel distance = %.2f",cur);
                return 0;
            }
            curind=i;
        }
    }
    printf("%.2f",sum);
    return 0;
}
