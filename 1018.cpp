#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define maxSize 501
#define INF 1000000000
using namespace std;
bool vis[maxSize]={0};
int c,prst;
int g[maxSize][maxSize];
int vexnum,arcnum;
int w[maxSize]={0};
int d[maxSize],minNeed = INF ,minRemain= INF;
vector<int> pre[maxSize];
vector<int> tempPath,path;
void Dijkstra(int s)
{
    fill(d,d+maxSize,INF);
    d[s]=0;
    for(int i=0;i<vexnum;++i)
    {
        int u=-1,min=INF;
        for(int j=0;j<=vexnum;++j)
        {
            if(!vis[j]&&d[j]<min)
            {
                u=j;
                min=d[j];
            }
        }
        if(u==-1)
            return;
        vis[u]=true;
        for(int v=0;v<=vexnum;++v)
        {
            if(vis[v]==false&&g[u][v]!=INF)
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
void DFS(int v)
{
    if(v==0)
    {
        tempPath.push_back(v);
        int need=0,remain=0;
        for(int i=tempPath.size()-1;i>=0;i--)
        {
            int id = tempPath[i];
            if(w[id]>0)
                remain += w[id];
            else
            {
                if(remain>abs(w[id]))
                    remain -= abs(w[id]);
                else
                {
                    need += abs(w[id])-remain;
                    remain = 0;
                }
            }
        }
        if(need<minNeed)
        {
            minNeed = need;
            minRemain = remain;
            path = tempPath;
        }
        else if(need == minNeed && remain<minRemain)
        {
            minRemain = remain;
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
    cin>>c>>vexnum>>prst>>arcnum;
    fill(g[0],g[0]+maxSize*maxSize,INF);
    for(int i=1;i<=vexnum;++i)
    {
        cin>>w[i];
        w[i]-=c/2;
    }
    for(int i=1;i<=arcnum;++i)
    {
        int col,row;
        cin>>col>>row;
        cin>>g[col][row];
        g[row][col]=g[col][row];
    }
    Dijkstra(0);
    DFS(prst);
    printf("%d ",minNeed);
    for(int i =path.size()-1;i>=0;i--)
    {
        printf("%d",path[i]);
        if(i>0)
            printf("->");
    }
    printf(" %d",minRemain);
    return 0;
}
