#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int INF = 1000000000;
const int maxn = 510;
bool vis[maxn]={0};
int d[maxn];
int n,m,st,ed;
int w[maxn][maxn];
int g[maxn][maxn];
vector<int> pre[maxn];
vector<int> path,temppath;
int optvalue=INF;

void dijkstra(int s)
{
    fill(d,d+maxn,INF);
    d[s]=0;
    for(int i=0;i<n;++i)
    {
        int minn=INF,u=-1;
        for(int j=0;j<n;++j)
        {
            if(!vis[j]&&minn>d[j])
            {
                minn=d[j];
                u=j;
            }
        }
        if(u==-1)
            return;
        vis[u]=1;
        for(int v=0;v<n;++v)
        {
            if(!vis[v]&&g[v][u]!=INF)
            {
                if(d[u]+g[v][u]<d[v])
                {
                    d[v]=d[u]+g[v][u];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(d[u]+g[v][u]==d[v])
                    pre[v].push_back(u);
            }
        }
    }
}

void dfs(int v)
{
    if(v==st)
    {
        temppath.push_back(v);
        int value=0;
        for(int i=temppath.size()-1;i>0;--i)
        {
            int id=temppath[i],idnext=temppath[i-1];
            value+=w[id][idnext];
        }
        if(value<optvalue)
        {
            optvalue=value;
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
    cin>>n>>m>>st>>ed;
    fill(g[0],g[0]+maxn*maxn,INF);
    for(int i=0;i<m;++i)
    {
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        g[b][a]=g[a][b]=c;
        w[a][b]=w[b][a]=d;
    }
    dijkstra(st);
    dfs(ed);
    for(int i=path.size()-1;i>=0;i--)
        printf("%d ",path[i]);
    printf("%d %d",d[ed],optvalue);
    return 0;
}
