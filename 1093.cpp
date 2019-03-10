#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int maxn = 1000000007;
int main()
{
    string str;
    long long int num=0;
    int nump=0,numt=0;

    cin>>str;
    for(int i=0;i<str.length();++i)
        if(str[i]=='T')
            numt++;
    for(int i=0;i<str.length();++i)
    {
        if(str[i]=='P')
            nump++;
        else if(str[i]=='A')
            num+=(nump*numt);
        else
            numt--;
    }
    printf("%d",num%maxn);
    return 0;
}
