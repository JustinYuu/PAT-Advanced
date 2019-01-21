#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int k1,k2,n,k=0;
    float a[1001]={0};
    float b[1001]={0};
    float c[2002]={0};
    cin>>k1;
    for(int i=0;i<k1;++i)
    {
        cin>>n;
        cin>>a[n];
    }
    cin>>k2;
    for(int i=0;i<k2;++i)
    {
        cin>>n;
        cin>>b[n];
    }
    for(int i=0;i<1001;++i)
        for(int j=0;j<1001;++j)
        {
            c[j+i]+=b[j]*a[i];
        }
    for(int i=0;i<2002;++i)
        if(c[i])
            k++;
    cout<<k;
    for(int i=2001;i>=0;--i)
        if(c[i])
            printf(" %d %.1f",i,c[i]);
    return 0;
}
