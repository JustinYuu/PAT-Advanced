#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int k;
    float p[1001]={0.0};
    int n;
    float an;
    for(int i=0;i<2;++i)
    {
        cin>>k;
        for(int j=0;j<k;++j)
        {
            cin>>n>>an;
            p[n]+=an;
        }
        //getchar();
    }
    k=0;
    for(int i=0;i<1001;++i)
        if(p[i])
            k++;
    cout<<k;
    for(int i=1000;i>=0;--i)
    {
        if(p[i])
        {
            cout<<' '<<i<<' ';
            printf("%.1f",p[i]);
        }
    }
    return 0;
}
