#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    long long n,b;
    cin>>n>>b;
    bool flag = true;
    vector<int> p;
    while(n)
    {
        p.push_back(n%b);
        n=n/b;
    }
    for(int i=0,j=p.size()-1;i<j;++i,--j)
    {
        if(p[i]!=p[j])
        {
            flag=false;
            break;
        }
    }
    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    for(int i=p.size()-1;i>=0;--i)
    {
        if(i==p.size()-1)
            cout<<p[i];
        else
            cout<<' '<<p[i];
    }
    return 0;
}
