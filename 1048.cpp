#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int main()
{
    int n,m;
    int p[maxn];
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d",&p[i]);
    sort(p,p+n);
    for(int i=0;i<n;++i)
    {
        int j=lower_bound(p,p+n,m-p[i])-p;
        if(p[i]+p[j]==m&&i!=j)
        {
            printf("%d %d",p[i],p[j]);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}
