#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int cmp(string a,string b)
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
            if(k==b.length()&&i<a.length())
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
            if(k==a.length()&&j<b.length())
                k=0;
        }
    }
}

int main()
{
    vector<string> p;
    int n;
    string tmp;

    cin>>n;
    cin>>tmp;
    p.push_back(tmp);
    for(int i=1;i<n;++i)
    {
        cin>>tmp;
        p.push_back(tmp);
        int j=i;
        while(j>0)
        {
            if(cmp(p[j-1],p[j])>0)
            {
                swap(p[j],p[j-1]);
                j--;
            }
            else
                break;
        }
    }
    int k=0;
    while(p[0][k]=='0')
        k++;
    string str(p[0],k);
    p[0]=str;
    if(p.size()==0)
        cout<<0;
    for(int i=0;i<p.size();++i)
        cout<<p[i];
    return 0;
}


