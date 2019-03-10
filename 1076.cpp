#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 1010;
bool vis[maxn] = {0};
vector<int> g[maxn];
int n;
void bfs(int v,int len)
{
    queue<int> q;
    int layer=0;
    int rear=v;
    q.push(v);
    vis[v]=true;
    while(!q.empty()&&layer<len)
    {
        int w=q.front();
        q.pop();
        for(int i=0;i<g[w].size();i++)
        {
            if(!vis[g[w][i]])
            {
                q.push(g[w][i]);
                vis[g[w][i]]=true;
            }
        }
        if(w==rear)
        {
            layer++;
            rear=q.back();
        }
    }
}

int main()
{
    int l,k,v,num;

    scanf("%d %d",&n,&l);
    for(int i=1;i<=n;++i)
    {
        int num,tmp;
        scanf("%d",&num);
        for(int j=1;j<=num;++j)
        {
            scanf("%d",&tmp);
            g[tmp].push_back(i);
        }
    }
    scanf("%d",&k);
    for(int i=0;i<k;++i)
    {
        num=0;
        fill(vis,vis+maxn,false);
        scanf("%d",&v);
        bfs(v,l);
        for(int i=1;i<=n;++i)
            if(vis[i]&&i!=v)
                num++;
        printf("%d\n",num);
    }
    return 0;
}
