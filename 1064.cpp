#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int CBT[maxn];
int tmp[maxn];
int n;
int num=0;
void inorder(int a)
{
    if(a>n)
        return;
    inorder(2*a);
    CBT[a]=tmp[num++];
    inorder(2*a+1);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>tmp[i];
    sort(tmp,tmp+n);
    inorder(1);
    cout<<CBT[1];
    for(int i=2;i<=n;++i)
        cout<<' '<<CBT[i];
    return 0;
}
