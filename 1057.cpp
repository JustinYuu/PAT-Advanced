#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 100010;

int findmid(int s[],int top)
{
    int p[maxn];
    for(int i=1;i<top+1;i++)
        p[i]=s[i];
    sort(p,p+top);
    return (top%2==0)?p[top/2]:p[(top-1)/2];
}
int main()
{
    string str;
    int s[maxn];
    int top=0;
    int n;

    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>str;
        if(str=="Pop")
        {
            if(top==0)
                printf("Invalid\n");
            else
            {
                printf("%d\n",s[top]);
                top--;
            }
        }
        else if(str=="Push")
        {
            int tmp;
            cin>>tmp;
            s[++top]=tmp;
        }
        else if(str=="PeekMedian")
        {
            if(top==0)
            {
                printf("Invalid\n");
                continue;
            }
            int tmp;
            tmp = findmid(s,top);
            printf("%d\n",tmp);
        }
    }
    return 0;
}
