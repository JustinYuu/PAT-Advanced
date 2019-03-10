#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct user
{
    bool issub=false;
    int id=99999,ts=0,rk,pn=0;
    int sc[6];
    user()
    {
        for(int i=0;i<=5;++i)
            sc[i]=-2;
    }
}user;

int cmp(user a,user b)
{
    if(a.ts!=b.ts)
        return a.ts>b.ts;
    else if(a.pn!=b.pn)
        return a.pn>b.pn;
    else
        return a.id<b.id;
}
int main()
{
    int n,k,m;
    user p[10010];
    int prob[6];

    cin>>n>>k>>m;
    for(int i=1;i<=k;++i)
        scanf("%d",&prob[i]);
    for(int i=1;i<=m;++i)
    {
        int probnum,tmpid,tmpsc;
        scanf("%d %d %d",&tmpid,&probnum,&tmpsc);
        p[tmpid].id = tmpid;
        if(tmpsc!=-1)
            p[tmpid].issub = true;
        if(tmpsc==-1 && p[tmpid].sc[probnum]<0)
            p[tmpid].sc[probnum]=0;
        if(tmpsc>=p[tmpid].sc[probnum])
            p[tmpid].sc[probnum]=tmpsc;
    }
    for(int i=1;i<=n;++i)
    {
        if(p[i].issub)
        {
            for(int j=1;j<=k;++j)
            {
                if(p[i].sc[j]>0)
                {
                    p[i].ts += p[i].sc[j];
                    if(p[i].sc[j]==prob[j])
                        p[i].pn++;
                }
            }
        }
    }
    sort(p+1,p+n+1,cmp);
    p[1].rk = 1;
    int kk=1;
    for(int i=2;i<=n;++i)
    {
        if(p[i].ts == p[i-1].ts)
        {
            p[i].rk = p[i-1].rk;
            kk++;
        }
        else
        {
            p[i].rk = p[i-1].rk+kk;
            kk=1;
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(p[i].issub)
        {
            printf("%d %05d %d",p[i].rk,p[i].id,p[i].ts);
            for(int j=1;j<=k;++j)
            {
                if(p[i].sc[j]==-2)
                    printf(" -");
                else
                    printf(" %d",p[i].sc[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
