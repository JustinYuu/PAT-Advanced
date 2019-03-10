#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int n;
double p,r;
int num=0;
int maxdepth=0;
vector<int> g[maxn];

void DFS(int v,int depth)
{
    if(g[v].size()==0)
    {
        if(depth>maxdepth)
        {
            maxdepth = depth;
            num=1;
        }
        else if(depth == maxdepth)
            num++;
        return;
    }
    for(int i=0;i<g[v].size();++i)
        DFS(g[v][i],depth+1);
}

int main()
{
    int father,root;

    cin>>n>>p>>r;
    r/=100;
    for(int i=0;i<n;++i)
    {
        cin>>father;
        if(father!=-1)
            g[father].push_back(i);
        else
            root = i;
    }
    DFS(root,0);
    printf("%.2f %d",p*pow(1+r,maxdepth),num);
    return 0;
}
