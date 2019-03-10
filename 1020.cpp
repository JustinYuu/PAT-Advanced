#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

typedef struct btnode
{
    struct btnode* left;
    struct btnode* right;
    int data;
}btnode;

btnode* create(int pl,int pr,int il,int ir,int po[],int io[])
{
    if(pl>pr||il>ir)
        return NULL;
    btnode* p = (btnode*)malloc(sizeof(btnode));
    int mid;
    for(int i=il;i<=ir;++i)
        if(io[i]==po[pr])
        {
            mid = i;
            break;
        }
    p->data = io[mid];
    p->left = create(pl,pl+mid-il-1,il,mid-1,po,io);
    p->right= create(pl+mid-il,pr-1,mid+1,ir,po,io);
    return p;
}

void layerorder(btnode* bt,int lo[])
{
    int k=0;
    if(bt==NULL)
        return;
    queue<btnode*> q;
    btnode *p;
    q.push(bt);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        lo[k++]=p->data;
        if(p->left)
            q.push(p->left);
        if(p->right)
            q.push(p->right);
    }
    return;
}
int main()
{
    int n;
    int po[30],io[30],lo[30];
    int ll,lr,rl,rr;
    btnode* p;

    cin>>n;
    for(int i=0;i<n;++i)
        cin>>po[i];
    for(int i=0;i<n;++i)
        cin>>io[i];

    p=create(0,n-1,0,n-1,po,io);
    layerorder(p,lo);

    for(int i=0;i<n;++i)
    {
        if(i==0)
            cout<<lo[i];
        else
            cout<<' '<<lo[i];
    }
    return 0;
}
