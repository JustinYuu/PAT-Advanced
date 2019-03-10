#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n,m,s;
const int maxn = 101;
bool vis[maxn]={0};
int w[maxn];
vector<int> adjl[maxn];
vector<int> path;
void dfs(int v,int wei)
{
    vis[v]=true;
    wei+=w[v];
    if(wei>s)
        return;
    else if(wei==s&&adjl[v].size()==0)
    {
        path.push_back(w[v]);
        printf("%d",path[0]);
        for(int i=1;i<path.size();++i)
            printf(" %d",path[i]);
        printf("\n");
        path.pop_back();
    }
    else if(wei<s&&adjl[v].size()>0)
    {
        int maxweight=0,maxid=0;
        path.push_back(w[v]);
        while(maxid!=-1)
        {
            maxid=maxweight=-1;
            for(int i=0;i<adjl[v].size();++i)
            {
                if(!vis[adjl[v][i]]&&w[adjl[v][i]]>maxweight)
                {
                    maxweight=w[adjl[v][i]];
                    maxid=adjl[v][i];
                }
            }
            if(maxid!=-1)
            {
                vis[maxid]=1;
                dfs(maxid,wei);
            }
        }
        path.pop_back();
    }
    return;
}

int main()
{
    scanf("%d %d %d",&n,&m,&s);
    for(int i=0;i<n;++i)
        scanf("%d",&w[i]);
    for(int i=0;i<m;++i)
    {
        int tmp,num,tmpnode;
        scanf("%d %d",&tmp,&num);
        for(int j=0;j<num;++j)
        {
            scanf("%d",&tmpnode);
            adjl[tmp].push_back(tmpnode);
        }
    }
    dfs(0,0);
    return 0;
}
