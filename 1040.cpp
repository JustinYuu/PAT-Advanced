#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool issym(char str[],int a,int b)
{
    int i=a,j=b;
    while(i<j)
    {
        if(str[i]!=str[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int main()
{
    char str[1010];
    cin.getline(str,1010,'\n');
    int i,j,k;
    int sta,_end;

    sta=_end=-1;
    i=0,j=strlen(str)-1;
    while(i<=j)
    {
        k=j;
        while(i+(_end-sta)<=k)
        {
            if(issym(str,i,k))
            {
                _end=k;
                sta=i;
            }
            k--;
        }
        i++;
    }
    if(_end!=-1)
        cout<<_end-sta+1;
    else
        cout<<0;
    return 0;
}
