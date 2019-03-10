#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> p;
    string str;
    int n;

    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;++i)
    {
        getline(cin,str);
        reverse(str.begin(),str.end());
        p.push_back(str);
    }
    int len=0;
    char tocmp;
    while(len<p[0].length())
    {
        bool flag = true;
        tocmp = p[0][len];
        for(int i=1;i<n;++i)
        {
            if(p[i][len]!=tocmp)
            {
                flag = false;
                break;
            }
        }
        if(!flag)
            break;
        else
            len++;
    }
    if(len==0)
        printf("nai");
    else
    {
        for(int i=len-1;i>=0;i--)
            printf("%c",p[0][i]);
    }
    return 0;
}
