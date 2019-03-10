#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 210;
const int INF = 1000000000;
bool vis[maxn] = {0};
int d[maxn];
map<string,int> cityname;
map<int,string> citynum;
int g[maxn][maxn];
int w[maxn]={0};
int numpath = 0;
int optvalue = 0;
double opt2value = 0;
int n,k,st;
vector<int> pre[maxn];
vector<int> tmppath,path;

void dijkstra(int s)
{
    fill(d,d+maxn,INF);
    d[s]=0;
    for(int i=0;i<n;++i)
    {
        int u=-1,minn=INF;
        for(int j=0;j<n;++j)
        {
            if(!vis[j]&&d[j]<minn)
            {
                u = j;
                minn = d[j];
            }
        }
        if(u == -1)
            return;
        vis[u] = true;
        for(int w=0;w<n;++w)
        {
            if(!vis[w]&&g[u][w]!=INF)
            {
                if(d[w]>d[u]+g[u][w])
                {
                    d[w] = d[u] + g[u][w];
                    pre[w].clear();
                    pre[w].push_back(u);
                }
                else if(d[w]==d[u]+g[w][u])
                    pre[w].push_back(u);
            }
        }
    }
}

void dfs(int v)
{

    if(v==st)
    {
        int value = 0;
        double value2 = 0;
        tmppath.push_back(v);
        numpath++;
        for(int i=tmppath.size()-1;i>=0;i--)
            value+=w[tmppath[i]];
        value2 = 1.0 * value / (tmppath.size()-1);
        if(value>optvalue)
        {
            opt2value = value2;
            optvalue=value;
            path=tmppath;
        }
        else if(value==optvalue && value2>opt2value)
        {
            path = tmppath;
            opt2value = value2;
        }
        tmppath.pop_back();
        return;
    }
    tmppath.push_back(v);
    for(int i=0;i<pre[v].size();++i)
    {
        dfs(pre[v][i]);
    }
    tmppath.pop_back();
}


int main()
{
    string start,city1,city2;


    cin>>n>>k>>start;
    st = 0;
    cityname[start] = 0;
    citynum[0] = start;
    fill(g[0],g[0]+maxn*maxn,INF);
    for(int i=1;i<=n-1;++i)
    {
        cin>>city1>>w[i];
        cityname[city1]=i;
        citynum[i]=city1;
    }
    for(int i=0;i<k;++i)
    {
        cin>>city1>>city2;
        int c1 = cityname[city1],c2 = cityname[city2];
        cin>>g[c1][c2];
        g[c2][c1]=g[c1][c2];
    }
    dijkstra(0);
    int rom = cityname["ROM"];
    dfs(rom);
    printf("%d %d %d %d\n",numpath,d[rom],optvalue,(int)opt2value);
    for(int i=path.size()-1;i>=0;i--)
    {
        int tmp = path[i];
        cout<<citynum[tmp];
        if(i>0)
            printf("->");
    }
    return 0;
}
