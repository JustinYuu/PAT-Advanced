#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define MAXV 501
#define INF 10000000

struct Node
{
    int v,dis;
    Node(int _v,int _dis):v(_v),dis(_dis){}
};
vector<Node> Adj[MAXV];
int n,m,st,ed,weight[MAXV];
int d[MAXV],w[MAXV],num[MAXV];
set<int> pre[MAXV];

void Bellman(int s)
{
    fill(d,d+MAXV,INF);
    memset(num,0,sizeof(num));
    memset(w,0,sizeof(w));
    d[s]=0;
    w[s]=weight[s];
    num[s]=1;
    for(int i=0;i<n-1;i++)
        for(int u=0;u<n;u++)
            for(int j=0;j<Adj[u].size();j++)
            {
                int v=Adj[u][j].v;
                int dis= Adj[u][j].dis;
                if(d[u]+dis<d[v])
                {
                    d[v]=d[u]+dis;
                    w[v]=w[u]+weight[v];
                    num[v]=num[u];
                    pre[v].clear();
                    pre[v].insert(u);
                }else if(d[u]+dis==d[v])
                {
                    if(w[u]+weight[v]>w[v])
                        w[v]=w[u]+weight[v];
                pre[v].insert(u);
                num[v]=0;
                set<int>::iterator it;
                for(it= pre[v].begin();it!=pre[v].end();it++)
                    num[v]+=num[*it];
                }
            }
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&st,&ed);
    for(int i=0;i<n;++i)
        scanf("%d",&weight[i]);
    int u,v,wt;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&wt);
        Adj[u].push_back(Node(v,wt));
        Adj[v].push_back(Node(u,wt));
    }
    Bellman(st);
    cout<<num[ed]<<' '<<w[ed];
    return 0;
}

