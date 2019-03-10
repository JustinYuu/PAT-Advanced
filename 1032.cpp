#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct node
{
    int next;
    bool flag=false;
    char data;
}node;

int main()
{
    int addr_a,addr_b,addr,next;
    int n;
    node p[100001];

    cin>>addr_a>>addr_b>>n;
    for(int i=0;i<n;++i)
    {
        cin>>addr;
        cin>>p[addr].data>>p[addr].next;
    }
    while(addr_a!=-1)
    {
        p[addr_a].flag=true;
        addr_a=p[addr_a].next;
    }
    while(addr_b!=-1)
    {
        if(p[addr_b].flag)
        {
            printf("%05d",addr_b);
            break;
        }
        addr_b=p[addr_b].next;
    }
    if(addr_b==-1)
        cout<<"-1";
    return 0;
}
