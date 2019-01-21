#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MaxSize 501
#define INF 10000000
typedef struct
{
    int edges[MaxSize][MaxSize];
    int arcnum,vexnum;
}MGraph;

int main()
{
    MGraph G;
    int c1,c2;
    int min,k;
    bool visited[MaxSize]={0};
    int dist[MaxSize];
    int num[MaxSize]={0};
    int w[MaxSize]={0};
    int rescue[MaxSize];
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
    w[c1]=rescue[c1];
    num[c1]=1;

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
                    w[j]=w[k]+rescue[j];
                    num[j]=num[k];
                }
                else if(dist[j]==dist[k]+G.edges[k][j])
                {
                    if(w[k]+rescue[j]>w[j])
                        w[j]=w[k]+rescue[j];
                    num[j]+=num[k];
                }
            }
    }
    cout<<num[c2]<<' '<<w[c2];
    return 0;
}
