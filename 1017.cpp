#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
    int prot;
    int time;
}people;
int cmp(people a,people b)
{
    return a.time<b.time;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<people> p;
    for(int i=0;i<n;++i)
    {
        people tmp;
        int hh,mm,ss;
        scanf("%d:%d:%d %d",&hh,&mm,&ss,&tmp.prot);
        tmp.time = ss+mm*60+hh*3600;
        tmp.prot*=60;
        if(tmp.time>61200)
            continue;
        p.push_back(tmp);
    }

    sort(p.begin(),p.end(),cmp);
    double waittime=0.0;
    int* clock = new int[k];
    for(int i=0;i<k;++i)
        clock[i]=28800;
    for(int i=0;i<p.size();++i)
    {
        int ind=0;
        for(int j=0;j<k;++j)
            if(clock[j]<clock[ind])
                ind = j;
        if(p[i].time<clock[ind])
        {
            waittime+=(clock[ind]-p[i].time);
            clock[ind]+=p[i].prot;
        }
        else
            clock[ind]=p[i].time+p[i].prot;
    }
    if(p.size()==0)
        printf("0.0");
    else
        printf("%.1f",waittime/60.0/p.size());
    return 0;
}
