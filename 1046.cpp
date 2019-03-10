#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int dis[100010];
    int A[100010];
    int m;
    int a,b;
    int sum=0;

    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&A[i]);
        sum+=A[i];
        dis[i]=sum;
    }
    scanf("%d",&m);
    for(int i=0;i<m;++i)
    {
        scanf("%d%d",&a,&b);
        if(a>b)
            swap(a,b);
        int tmp=dis[b-1]-dis[a-1];
        printf("%d\n",min(tmp,sum-tmp));
    }
    return 0;
}
