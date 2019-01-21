#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n,m,k,q;
    int query;
    int sum[21]={0};
    int topt[21]={0};
    queue<int> line[21];
    int durt[1001];
    int endt[1001];

    cin>>n>>m>>k>>q;
    fill(topt,topt+21,480);
    fill(sum,sum+21,480);
    for(int i=0;i<k;++i)
        cin>>durt[i];
    for(int i=0;i<k;++i)
    {
        if(i<n*m)
        {
             line[i%n].push(i);
             sum[i%n]+=durt[i];
             if(i<n)
                topt[i]=durt[i];
             endt[i]=sum[i%n];
        }
        else
        {
            int minw=-1,minv=1<<30;
            for(int j=0;j<n;++j)
                if(topt[j]<minv)
                {
                    minw=j;
                    minv=topt[j];
                }
            line[minw].pop();
            line[minw].push(i);
            sum[minw]+=durt[i];
            topt[minw]+=durt[line[minw].front()];
            endt[i]=sum[minw];
        }
    }
    for(int i=0;i<q;++i)
    {
        cin>>query;
        if(endt[query-1]-durt[query-1]<1020)
            printf("%02d:%02d\n",endt[query-1]/60,endt[query-1]%60);
        else
            printf("Sorry\n");
    }
    return 0;
}
