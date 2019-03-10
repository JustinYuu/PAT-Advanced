#include <cstdio>
#include <iostream>
using namespace std;
const int INF = 100010;
typedef struct node
{
    int next;
    int data;
}node;
int main()
{
    int n,addr;
    int start;
    int minv=INF,mini=-1;
    node p[100010];
    int q[100010];
    fill(q,q+100010,-1);

    cin>>n>>start;
    for(int i=0;i<n;++i)
    {
        cin>>addr;
        cin>>p[addr].data>>p[addr].next;
        if(p[addr].data<minv)
        {
            minv = p[addr].data;
            mini = addr;
        }
    }
    int ptr = start;
    int ptrm = mini;
    while(ptr!=-1)
    {
        ptrm=mini;
        while(q[ptrm]!=-1&&p[ptr].data>=p[q[ptrm]].data)
            ptrm=q[ptrm];
        int tmpptr=mini;

        int tmp=q[ptrm];
        q[ptrm]=ptr;
        q[ptr]=tmp;
        ptr=p[ptr].next;
        if(ptr==start)
            ptr=p[ptr].next;
    }
    ptrm=mini;
    printf("%d %05d\n",n,mini);
    while(q[ptrm]!=-1)
    {
        printf("%05d %d %05d\n",ptrm,p[ptrm].data,q[ptrm]);
        ptrm=q[ptrm];
    }
    printf("%05d %d -1",ptrm,p[ptrm].data);
    return 0;
}
