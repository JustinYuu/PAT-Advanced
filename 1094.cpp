#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 110;
int n,m,layer,maxnum=0,maxlayer=0;
vector<int> p[maxn];

void bfs(int v)
{
    layer = 0;
    queue<int> q;
    int locnum=0;
    int rear = v;

    q.push(v);
    while(!q.empty())
    {
        int w = q.front();
        q.pop();
        locnum++;
        for(int i=0;i<p[w].size();++i)
        {
            q.push(p[w][i]);
        }
        if(w==rear)
        {
            layer++;
            if(locnum>maxnum)
            {
                maxnum = locnum;
                maxlayer = layer;
            }
            locnum=0;
            rear = q.back();
        }
    }
    return;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int index,tmpnum,tmp;
        cin>>index>>tmpnum;
        for(int j=0;j<tmpnum;j++)
        {
            cin>>tmp;
            p[index].push_back(tmp);
        }
    }
    bfs(1);
    printf("%d %d",maxnum,maxlayer);
    return 0;
}
