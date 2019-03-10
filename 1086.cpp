#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;
int ppo[40];
int len;
void postorder(int po[],int io[],int pl,int pr,int il,int ir)
{
    if(pl>pr||il>ir)
        return;
    int i;
    for(i=il;i<ir;++i)
        if(io[i]==po[pl])
            break;
    ppo[len]=io[i];
    len--;
    postorder(po,io,pl+i-il+1,pr,i+1,ir);
    postorder(po,io,pl+1,pl+i-il,il,i-1);
}

int main()
{
    int po[40],io[40];
    int n,node;
    int ionum,ponum;
    string str;
    stack<int> s;


    cin>>n;
    ionum = ponum = 1;
    len=n;
    for(int i=0;i<2*n;++i)
    {
        cin>>str;
        if(str=="Push")
        {
            cin>>node;
            s.push(node);
            po[ponum++] = node;
        }
        else if(str == "Pop")
        {
            node = s.top();
            s.pop();
            io[ionum++] = node;
        }
    }
    postorder(po,io,1,n,1,n);
    printf("%d",ppo[1]);
    for(int i=2;i<=n;++i)
        printf(" %d",ppo[i]);
    return 0;
}
