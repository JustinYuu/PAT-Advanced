#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MaxSize 501
#define INF 10000000
typedef struct
{
    int edges[MaxSize][MaxSize];
    int arcnum,vexnum;
}MGraph;

vector<int> pre[MaxSize];
int rescue[MaxSize]={0};
int num=0;
int weight=0;
vector<int> temppath;
void DFS(int v,int c1)
{
    if(v==c1)
    {
        temppath.push_back(v);
        num++;
        int value=0;
        for(int i=temppath.size()-1;i>=0;i--)
        {
            int id=temppath[i];
            value+=rescue[id];
        }
        if(value>weight)
            weight=value;
        temppath.pop_back();
        return;
    }
    temppath.push_back(v);
    for(int i=0;i<pre[v].size();++i)
        DFS(pre[v][i],c1);
    temppath.pop_back();
}
int main()
{
    MGraph G;
    int c1,c2;
    int min,k;
    bool visited[MaxSize]={0};
    int dist[MaxSize];
    fill(G.edges[0],G.edges[0]+MaxSize*MaxSize,INF);

    cin>>G.vexnum>>G.arcnum>>c1>>c2;
    for(int i=0;i<G.vexnum;++i)
        cin>>rescue[i];
    for(int i=0;i<G.arcnum;++i)
    {
        int a,b;
        cin>>a>>b;
        cin>>G.edges[a][b];
        G.edges[b][a]=G.edges[a][b];
    }

    fill(dist,dist+MaxSize,INF);
    dist[c1]=0;

    for(int i=0;i<G.vexnum;++i)
    {
        k=-1;
        min=INF;
        for(int j=0;j<G.vexnum;++j)
            if(!visited[j]&&dist[j]<min)
            {
                min=dist[j];
                k=j;
            }
        if(k==-1)
            break;
        visited[k]=1;
        for(int j=0;j<G.vexnum;++j)
            if(G.edges[k][j]!=INF&&!visited[j])
            {
                if(dist[j]>dist[k]+G.edges[k][j])
                {
                    dist[j]=dist[k]+G.edges[k][j];
                    pre[j].clear();
                    pre[j].push_back(k);
                }
                else if(dist[j]==dist[k]+G.edges[k][j])
                {
                    pre[j].push_back(k);
                }
            }
    }
    DFS(c2,c1);
    cout<<num<<' '<<weight;
    return 0;
}

