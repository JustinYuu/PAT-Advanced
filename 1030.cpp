#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 510;
const int INF = 1000000000;
int g[MAXN][MAXN];
int dist[MAXN];
int w[MAXN][MAXN];
bool _set[MAXN]={0};
int n,m,s,d;
vector<int>pre[MAXN];
int minCost=INF;
vector<int> path,tempPath;

void dijkstra(int s)
{
    fill(dist,dist+MAXN,INF);
    dist[s]=0;
    for(int i=0;i<n;++i)
    {
        int minn = INF,u=-1;
        for(int j=0;j<n;++j)
            if(_set[j]==0&&minn>dist[j])
            {
                minn = dist[j];
                u = j;
            }
        if(u==-1)
            return;
        _set[u]=1;
        for(int v=0;v<n;++v)
        {
            if(_set[v]==false&&g[u][v]!=INF)
            {
                if(g[u][v]+dist[u]<dist[v])
                {
                    dist[v]=dist[u]+g[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(g[u][v]+dist[u]==dist[v])
                    pre[v].push_back(u);
            }
        }
    }
}

void DFS(int v)
{
    if(v==s)
    {
        tempPath.push_back(v);
        int tempCost = 0;
        for(int i=tempPath.size()-1;i>0;i--)
        {
            int id=tempPath[i],idNext=tempPath[i-1];
            tempCost+=w[id][idNext];
        }
        if(tempCost<minCost)
        {
            minCost=tempCost;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i=0;i<pre[v].size();++i)
        DFS(pre[v][i]);
    tempPath.pop_back();
}

int main()
{
    cin>>n>>m>>s>>d;
    int a,b;
    fill(g[0],g[0]+MAXN*MAXN,INF);
    fill(w[0],w[0]+MAXN*MAXN,INF);
    for(int i=0;i<m;++i)
    {
        cin>>a>>b;
        cin>>g[a][b]>>w[a][b];  // Input must in two lines
        g[b][a]=g[a][b];
        w[b][a]=w[a][b];
    }
    dijkstra(s);
    DFS(d);
    for(int i=path.size()-1;i>=0;i--)
        printf("%d ",path[i]);
    printf("%d %d\n",dist[d],minCost);
    return 0;
}
