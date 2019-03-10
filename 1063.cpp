#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,m,k,tmp,totnum,comnum;
    int nc,nt;
    vector<int> q[51];
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        int num;
        scanf("%d",&num);
        for(int j=0;j<num;++j)
        {
            scanf("%d",&tmp);
            q[i].push_back(tmp);
        }
        sort(q[i].begin(),q[i].end());
        q[i].erase(unique(q[i].begin(), q[i].end()), q[i].end());
    }
    scanf("%d",&m);
    for(int i=0;i<m;++i)
    {
        comnum=0;
        totnum=0;
        scanf("%d %d",&nc,&nt);
        int j=0,k=0;
        while(j<q[nt].size()&&k<q[nc].size())
        {
            if(q[nt][j]<q[nc][k])
                j++;
            else if(q[nt][j]>q[nc][k])
                k++;
            else
            {
                j++;
                k++;
                comnum++;
            }
        }
        totnum = q[nt].size()+q[nc].size()-comnum;
        float per = (comnum*100.0)/(totnum*1.0);
        printf("%.1f\%\n",per);
    }
    return 0;
}

