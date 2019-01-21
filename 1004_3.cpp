#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int N=110;
vector<int> G[N];
int h[N]={0};
int leaf[N]={0};
int max_h=0;
void BFS()
{
    queue<int> Q;
    Q.push(1);
    while(!Q.empty())
    {
        int id=Q.front();
        Q.pop();
        max_h=max(max_h,h[id]);
        if(G[id].size()==0)
            leaf[h[id]]++;
        for(int i=0;i<G[id].size();++i)
        {
            h[G[id][i]]=h[id]+1;
            Q.push(G[id][i]);
        }
    }
}
int main()
{
    int n,m,parent,child,k;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        scanf("%d%d",&parent,&k);
        for(int j=0;j<k;++j)
        {
            scanf("%d",&child);
            G[parent].push_back(child);
        }
    }
    h[1]=1;
    BFS();
    printf("%d",leaf[1]);
    for(int i=2;i<=max_h;++i)
        printf(" %d",leaf[i]);
    return 0;
}
