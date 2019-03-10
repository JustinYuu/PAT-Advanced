#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct Node
{
     int addr;
     int nextaddr;
     int data;
}Node;

int main()
{
    int n,k;
    int firstaddr;
    int next;
    int num,tmp;
    Node a,p[100000];
    cin>>firstaddr>>n>>k;
    vector <Node> Order;
    vector <Node> Reverse;
    for(int i=0;i<n;i++)
    {
        cin>>a.addr>>a.data>>a.nextaddr;
        p[a.addr]=a;
    }
    next = firstaddr;
    while(next!=-1)
    {
        Order.push_back(p[next]);
        next = p[next].nextaddr;
    }
    num = Order.size();
    tmp = k-1;
    while(tmp<num)
    {
        for(int i=tmp;i>tmp-k;i--)
            Reverse.push_back(Order[i]);
        tmp+=k;
    }
    for(int i=tmp-k+1;i<num;i++)
        Reverse.push_back(Order[i]);
    for(int i=0;i<num-1;i++)
    {
        Reverse[i].nextaddr = Reverse[i+1].addr;
        printf("%05d %d %05d\n",Reverse[i].addr,Reverse[i].data,Reverse[i].nextaddr);
    }
    printf("%05d %d %d\n",Reverse[num-1].addr,Reverse[num-1].data,-1);
    return 0;
}
