#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    int n,n1,n2;

    cin>>word;
    n = word.length()+2;
    n1=n/3;
    n2=n-n1-n1;
    //cout<<n1<<' '<<n2;

    for(int i=0;i<n1-1;i++)
    {
        printf("%c",word[i]);
        for(int j=0;j<n2-2;++j)
            printf(" ");
        printf("%c\n",word[n-3-i]);
    }
    for(int j=n1-1;j<n1-1+n2;++j)
        printf("%c",word[j]);
    return 0;
}
