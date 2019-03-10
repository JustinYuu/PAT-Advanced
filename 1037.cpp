#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int nc,np;
    int total;
    int coup[100010],prod[100010];

    total=0;
    cin>>nc;
    for(int i=0;i<nc;i++)
        cin>>coup[i];
    cin>>np;
    for(int i=0;i<np;i++)
        cin>>prod[i];

    sort(coup,coup+nc);
    sort(prod,prod+np);
    for(int i=0,j=0;i<nc,j<np;++i,++j)
    {
        if(coup[i]<0&&prod[j]<0)
            total+=coup[i]*prod[j];
        if(coup[i]*prod[j]<0)
            break;
    }
    for(int i=nc-1,j=np-1;i>=0,j>=0;--i,--j)
    {
        if(coup[i]>0&&prod[j]>0)
            total+=coup[i]*prod[j];
        if(coup[i]*prod[j]<0)
            break;
    }

    cout<<total;
    return 0;
}
