#include <cstdio>
const int maxn = 1000010;
const int INF = 0x7fffffff;
int S1[maxn];

int main()
{
    int n,m,S2,i,j;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&S1[i]);
    scanf("%d",&m);
    scanf("%d",&S2);
    S1[n]=INF;
    int medianPos = (n+m-1)/2;
    int count=0;
    i=j=0;
    while(count<medianPos)
    {
        if(S1[i]<S2)
            ++i;
        else
        {
            ++j;
            if(j<m)
                scanf("%d",&S2);
            else if(j==m)
                S2=INF;
            else
                break;
        }
        count++;
    }
    if(S1[i]<S2)
        printf("%d",S1[i]);
    else
        printf("%d",S2);
    return 0;
}
