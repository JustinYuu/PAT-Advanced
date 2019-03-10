#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const int maxn = 100010;
bool vis[maxn]={0};
vector<int> g[maxn];
int n;
double p,r;
double total=0.0;
int wgt[maxn]={0};

void bfs(int v)
{
    int len = 0;
    int rear = 0;
    queue<int> q;
    q.push(0);
    vis[0]=true;
    while(!q.empty())
    {
        int w = q.front();
        q.pop();
        for(int i=0;i<g[w].size();++i)
        {
            if(!vis[g[w][i]])
            {
                q.push(g[w][i]);
                vis[g[w][i]]=true;
            }
        }
        if(g[w].size()==0)
        {
            double pri;
            pri=wgt[w]*p*pow((1+r*0.01),len);
            total+=pri;
        }
        if(w==rear)
        {
            len++;
            rear = q.back();
        }
    }
}

int main()
{
    int num;

    scanf("%d %lf %lf",&n,&p,&r);
    for(int i=0;i<n;++i)
    {
        int tmp;
        scanf("%d",&num);
        if(num==0)
        {
            scanf("%d",&tmp);
            wgt[i] = tmp;
            continue;
        }
        for(int j=0;j<num;++j)
        {
            scanf("%d",&tmp);
            g[i].push_back(tmp);
        }
    }
    bfs(0);
    printf("%.1f",total);
    return 0;
}
