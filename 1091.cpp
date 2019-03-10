#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct
{
    int x,y,z;
}node;
int g[1300][130][65];
int m,n,l,t;
bool vis[1300][130][65] = {0};
int X[6] = {0,0,0,0,1,-1};
int Y[6] = {0,0,1,-1,0,0};
int Z[6] = {1,-1,0,0,0,0};

bool judge(int x,int y,int z)
{
    if(x>=n||y>=m||z>=l||x<0||y<0||z<0)
        return false;
    if(g[x][y][z]==0||vis[x][y][z]==1)
        return false;
    return true;

}
int bfs(int x,int y,int z)
{
    queue<node> q;
    int tot=0;
    node Node;
    Node.x = x;
    Node.y = y;
    Node.z = z;
    vis[x][y][z]=true;
    q.push(Node);
    while(!q.empty())
    {
        node top = q.front();
        q.pop();
        tot++;
        for(int i=0;i<6;++i)
        {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            int newZ = top.z + Z[i];
            if(judge(newX,newY,newZ))
            {
                Node.x = newX;
                Node.y = newY;
                Node.z = newZ;
                q.push(Node);
                vis[newX][newY][newZ] = true;
            }
        }
    }
    if(tot>=t)
        return tot;
    else
        return 0;
}

int main()
{
    cin>>n>>m>>l>>t;
    for(int i=0;i<l;++i)
    {
        for(int j=0;j<n;++j)
            for(int k=0;k<m;++k)
                scanf("%d",&g[j][k][i]);
    }
    int ans=0;
    for(int z=0;z<l;++z)
    {
        for(int x=0;x<n;++x)
        {
            for(int y=0;y<m;++y)
            {
                if(g[x][y][z]==1 && !vis[x][y][z])
                    ans+=bfs(x,y,z);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
