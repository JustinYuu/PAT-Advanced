#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 510;
const int INF = 1000000000;
bool vis[maxn]={0};
int g[maxn][maxn];
int d[maxn];
int w[maxn];
int cmax,n,m,ed;
vector<int> pre[maxn];
vector<int> path,temppath;
int minneed=INF,minremain=INF;

void dijkstra(int v)
{
    fill(d,d+maxn,INF);
    d[v]=0;
    for(int i=0;i<=n;++i)
    {
        int minn=INF,u=-1;
        for(int j=0;j<=n;++j)
        {
            if(!vis[j]&&d[j]<minn)
            {
                minn=d[j];
                u=j;
            }
        }
        if(u==-1)
            return;
        vis[u]=1;
        for(int v=0;v<=n;++v)
        {
            if(!vis[v]&&g[u][v]!=INF)
            {
                if(d[u]+g[u][v]<d[v])
                {
                    d[v]=d[u]+g[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(d[u]+g[u][v]==d[v])
                    pre[v].push_back(u);
            }
        }
    }
}

void dfs(int v)
{
    if(v==0)
    {
        temppath.push_back(v);
        int need=0,remain=0;
        for(int i=temppath.size()-1;i>=0;--i)
        {
            int id = temppath[i];
            if(w[id]>0)
                remain+=w[id];
            else
            {
                if(remain>abs(w[id]))
                    remain-=abs(w[id]);
                else
                {
                    need+=abs(w[id])-remain;
                    remain = 0;
                }
            }
        }
        if(need<minneed)
        {
            minneed=need;
            minremain=remain;
            path=temppath;
        }
        else if(need==minneed&&remain<minremain)
        {
            minremain=remain;
            path=temppath;
        }
        temppath.pop_back();
        return;
    }
    temppath.push_back(v);
    for(int i=0;i<pre[v].size();++i)
        dfs(pre[v][i]);
    temppath.pop_back();
}

int main()
{
    cin>>cmax>>n>>ed>>m;
    fill(g[0],g[0]+maxn*maxn,INF);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&w[i]);
        w[i]-=cmax/2;
    }
    for(int i=1;i<=m;++i)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        g[a][b]=g[b][a]=c;
    }
    dijkstra(0);
    dfs(ed);
    printf("%d ",minneed);
    for(int i =path.size()-1;i>=0;i--)
    {
        printf("%d",path[i]);
        if(i>0)
            printf("->");
    }
    printf(" %d",minremain);
    return 0;
}
