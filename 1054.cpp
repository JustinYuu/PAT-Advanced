#include <cstdio>

const int maxn = 100000000;
int p[maxn]={0};
int main()
{
    int m,n;
    int tmp;
    scanf("%d %d",&m,&n);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            scanf("%d",&tmp);
            p[tmp]++;
        }
    }
    for(int i=0;i<maxn;++i)
        if(p[i]*2>m*n)
        {
            printf("%d",i);
            break;
        }
    return 0;
}
