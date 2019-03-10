#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int p;
    int n,len=0;
    long long q[100010];

    scanf("%d %d",&n,&p);
    for(int i=0;i<n;++i)
        scanf("%lld",&q[i]);
    sort(q,q+n);
    for(int i=0;i<n;++i)
    {
        int j=upper_bound(q+i,q+n,p*q[i])-q;
        len = max(j-i,len);
    }
    printf("%d",len);
}
