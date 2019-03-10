#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=10010;
const int maxc=210;
int dp[maxn],HashTable[maxc];
int A[maxn];

int main()
{
    int n,m,x,l;
    int num;

    memset(HashTable,-1,sizeof(HashTable));
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        scanf("%d",&x);
        HashTable[x]=i;
    }
    scanf("%d",&l);
    num=0;
    for(int i=0;i<l;++i)
    {
        scanf("%d",&x);
        if(HashTable[x]>=0)
            A[num++]=HashTable[x];
    }

    int ans=-1;
    for(int i=0;i<num;++i)
    {
        dp[i]=1;
        for(int j=0;j<i;++j)
            if(A[j]<=A[i]&&dp[i]<dp[j]+1)
                dp[i]=dp[j]+1;
        ans = max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}
