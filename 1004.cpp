#include <iostream>
#include <cstdio>
using namespace std;
#define MaxSize 10000
typedef struct tree
{
    struct tree* firstchild;
    struct tree* nextsibling;
    int data;
}tree;
void inserttr(int iddata,int partid,tree* root)
{
    tree *p=root;
    if(root==NULL)
        return;
    if(p->data==partid)
    {
        if(p->firstchild)
        {
            p=p->firstchild;
            while(p->nextsibling)
                p=p->nextsibling;
            p->nextsibling=(tree*)malloc(sizeof(tree));
            p->nextsibling->data=iddata;
            p->nextsibling->nextsibling=NULL;
            p->nextsibling->firstchild=NULL;
            return;
        }
        else
        {
            p->firstchild=(tree*)malloc(sizeof(tree));
            p->firstchild->data=iddata;
            p->firstchild->firstchild=NULL;
            p->firstchild->nextsibling=NULL;
            return;
        }
    }
    inserttr(iddata,partid,p->firstchild);
    inserttr(iddata,partid,p->nextsibling);
}
int main()
{
    int n,m;
    int id,k,idtmp;
    tree* p;
    tree* root = (tree*)malloc(sizeof(tree));
    root->firstchild=NULL;
    root->nextsibling=NULL;
    root->data=1;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        cin>>id>>k;
        for(int j=0;j<k;++j)
        {
            cin>>idtmp;
            inserttr(idtmp,id,root);
        }
    }
    if(!root->firstchild)
    {
        cout<<'1';
        return 0;
    }
    cout<<'0';
    tree* queue[MaxSize];
    int front=0,rear=0,last=0,num=0;
    queue[rear++]=root;
    last=rear;
    while(front!=rear)
    {
        p=queue[front++];
        if(!p->firstchild)
                num++;
        p=p->firstchild;
        while(p)
        {
            queue[rear++]=p;
            p=p->nextsibling;
        }
        if(front==last)
        {
            if(front!=1)
                cout<<' '<<num;
            num=0;
            last=rear;
        }
    }
    return 0;
}
