#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int k,tmp;
    int seq[55];
    int res[55];
    int lasres[55];

    cin>>k;
    for(int i=1;i<=54;++i)
    {
        cin>>seq[i];
        lasres[i]=i;
    }
    while(k>0)
    {
        for(int i=1;i<=54;++i)
            res[seq[i]]=lasres[i];
        for(int i=1;i<=54;++i)
            lasres[i]=res[i];
        k--;
    }
    for(int i=1;i<=54;++i)
    {
        if(i!=1)
            printf(" ");
        if(res[i]<=13)
            printf("S%d",res[i]);
        else if(res[i]<=26)
            printf("H%d",res[i]-13);
        else if(res[i]<=39)
            printf("C%d",res[i]-26);
        else if(res[i]<=52)
            printf("D%d",res[i]-39);
        else
            printf("J%d",res[i]-52);
    }
    return 0;
}
