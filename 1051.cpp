#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main()
{
    int m,n,k;

    cin>>m>>n>>k;
    for(int i=0;i<k;++i)
    {
        int num;
        stack<int> p;
        int seq[n];
        for(int j=1;j<=n;++j)
            cin>>seq[j];
        num=1;
        for(int j=1;j<=n;++j)
        {
            if(p.size()<m)
                p.push(j);
            else
                break;
            while(p.size()>0&&seq[num]==p.top())
            {
                p.pop();
                num++;
            }
        }
        if(p.size()==0&&num==n+1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
