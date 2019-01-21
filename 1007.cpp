#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int k;
    int fir=0,las=k-1;
    int sum=0,max=-1;
    int tempfir=0;
    int p[10001];
    cin>>k;
    for(int i=0;i<k;++i)
        cin>>p[i];
    for(int i=0;i<k;++i)
    {
        sum=sum+p[i];
        if(sum<0)
        {
            sum=0;
            tempfir=i+1;
        }
        else if(sum>max)
        {
            max=sum;
            fir=tempfir;
            las=i;
        }
    }
    if(max>=0)
        cout<<max<<' '<<p[fir]<<' '<<p[las];
    else
        cout<<0<<' '<<p[0]<<' '<<p[k-1];
    return 0;
}
