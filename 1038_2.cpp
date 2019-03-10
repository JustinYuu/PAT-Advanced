#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct cmp
{
    bool operator()(const string &a,const string &b)const
    {
        int i,j,k;
        if(a==b)
            return 0;
        for(i=0,j=0;i<a.length()&&j<b.length();++i,++j)
        {
            if(a[i]!=b[j])
                return a[i]>b[j];
        }
        if(i<a.length())
        {
            k=0;
            while(i<a.length())
            {
                if(a[i]!=b[k])
                    return a[i]>b[k];
                else
                {
                    k++;
                    i++;
                }
                if(k==b.length())
                    k=0;
            }
        }
        else if(j<b.length())
        {
            k=0;
            while(j<b.length())
            {
                if(a[k]!=b[j])
                    return a[k]>b[j];
                else
                {
                    k++;
                    j++;
                }
                if(k==a.length())
                    k=0;
            }
        }
    }
};

int main()
{
    int n;
    string tmp;
    priority_queue <string,vector<string>,cmp> p;

    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>tmp;
        p.push(tmp);
    }
    int k=0;
    while(p.top()[k]=='0')
        k++;
    string str(p.top(),k);
    p.pop();
    p.push(str);
    if(p.empty())
        cout<<"0";
    while(!p.empty())
    {
        cout<<p.top();
        p.pop();
    }
    return 0;
}
