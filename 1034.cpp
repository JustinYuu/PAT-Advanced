#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

const int MAXN = 2010;
int arcnum,vexnum=0;
int g[MAXN][MAXN];
bool vis[MAXN]={0};
map<string,int> strToint;
map<int,string> intTostr;
map<string,int> com_num;
map<int,int> node;
int comnum;
int maxtime;
int gangtime;
string maxtimeind;

void DFS(int v)
{
    vis[v]=true;
    comnum++;
    if(node[v]>maxtime)
    {
        maxtime=node[v];
        maxtimeind = intTostr[v];
    }
    for(int i=1;i<=vexnum;++i)
    {
        if(g[v][i]!=0)
        {
            gangtime+=g[v][i];
            if(!vis[i])
                DFS(i);
        }
    }
}

int main()
{
    int k,ganum=0;
    string a,b;
    string heads[MAXN];

    cin>>arcnum>>k;
    fill(g[0],g[0]+MAXN*MAXN,0);
    for(int i=0;i<arcnum;++i)
    {
        int tmp;
        cin>>a>>b;
        if(!strToint[a])
            strToint[a]=++vexnum;
        if(!strToint[b])
            strToint[b]=++vexnum;
        cin>>tmp;
        node[strToint[a]]+=tmp;
        node[strToint[b]]+=tmp;
        intTostr[strToint[a]]=a;
        intTostr[strToint[b]]=b;
        g[strToint[a]][strToint[b]]+=tmp;
        g[strToint[b]][strToint[a]]+=tmp;
    }
    for(int i=1;i<=vexnum;++i)
    {
        if(!vis[i])
        {
            comnum=0;
            maxtime=0;
            gangtime=0;
            DFS(i);
            if(comnum>=3&&(gangtime/2)>k)
            {
                ganum++;
                heads[ganum]=maxtimeind;
                com_num[maxtimeind]=comnum;
            }
        }
    }
    printf("%d\n",ganum);
    for(int i=1;i<=ganum;++i)
        cout<<heads[i]<<' '<<com_num[heads[i]]<<endl;
    return 0;
}
