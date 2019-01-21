#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    float _max,sum,tmp;
    char flag[3],p[3]={'W','T','L'};
    for(int i=0;i<3;++i)
    {
        _max=0;
        for(int j=0;j<3;++j)
        {
            cin>>tmp;
            if(tmp>_max)
            {
                _max=tmp;
                flag[i]=p[j];
            }
        }
        if(i==0)
            sum=_max;
        else
            sum*=_max;
    }
    float res=(sum*0.65-1)*2;
    for(int i=0;i<3;++i)
        cout<<flag[i]<<' ';
    printf("%.2f",res);
    return 0;
}
