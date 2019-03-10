#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int minn[4];
    int maxn[4];
    int num[4];
    int maxv,minv;

    cin>>n;
    do
    {
        maxv=minv=0;
        for(int i=0,a=10;i<4;++i)
        {
            num[i]=n%a;
            maxn[i]=minn[i]=num[i];
            n=n/a;
        }
        sort(minn,minn+4);
        sort(maxn,maxn+4,greater<int>());
        for(int i=3,a=1;i>=0;--i,a*=10)
        {
            minv += minn[i]*a;
            maxv += maxn[i]*a;
        }
        n = maxv - minv;
        printf("%04d - %04d = %04d\n",maxv,minv,n);
    }while(n!=0&&n!=6174);
    return 0;
}
