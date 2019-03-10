#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

bool p[10010]={0};
int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    for(int i=0;i<s2.length();++i)
        p[s2[i]]=1;
    for(int i=0;i<s1.length();++i)
        if(!p[s1[i]])
            cout<<s1[i];
    return 0;
}
