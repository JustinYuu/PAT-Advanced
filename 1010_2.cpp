#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int convert(char c)
{
    if(c>='0'&&c<='9')
        return c-'0';
    else
        return c-'a'+10;
}
long long findradix(string n1,string n2,int tag,long long radix)
{
    string target,prepared;
    target=tag==1?n2:n1;
    prepared=tag==1?n1:n2;
    int prelen=prepared.length(),tarlen=target.length();
    long long preval=0,tarval=0;
    for(int i=0;i<prelen;++i)
        preval+=convert(prepared[prelen-i-1])*pow(radix,i);
    long long _min=0;
    for(unsigned int i=0;i<target.length();++i)
        _min=convert(target[i])>_min?convert(target[i]):_min;
    long long left=_min+1;
    long long right=max(_min+1,preval)+1;
    long long res=preval+2;
    while(left<=right)
    {
        long long i=(left+right)/2;
        tarval=0;
        for(int j=0;j<tarlen;++j)
        {
            tarval+=convert(target[tarlen-j-1])*pow(double(i),j);
            //cout<<"tarval= "<<tarval<<" radix= "<<i<<endl;
            if(tarval<0||tarval>preval)
                break;
        }
        if(preval==tarval)
        {
            res=min(res,i);
            right--;
        }
        else if(tarval>preval||tarval<0)
            right=i-1;
        else if(tarval<preval)
            left=i+1;
    }
    if(res==preval+2)
        return 0;
    else
        return res;
}
int main()
{
    int tag;
    string n1,n2;
    long long radix,res;
    cin>>n1>>n2>>tag>>radix;
    res=findradix(n1,n2,tag,radix);
    if(res==0)
        cout<<"Impossible";
    else
        printf("%lld",res);
    return 0;
}
