#include <iostream>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    string str;
    char c;
    string word;
    map<string,int> p;

    getline(cin,str);
    int i=0;
    while(i<str.length())
    {
        int j;
        if(isalpha(str[i])||isdigit(str[i]))
        {
            j=i;
            while(j<str.length()&&(isalpha(str[j])||isdigit(str[j])))
            {
                if(isupper(str[j]))
                    str[j]=tolower(str[j]);
                ++j;
            }
            word = str.substr(i,j-i);
            p[word]++;
            i=j;
        }
        else
            i++;
    }
    int maxt = 0;
    string maxs;
    for(map<string,int>::iterator it=p.begin();it!=p.end();++it)
    {
        if(it->second>maxt)
        {
            maxs = it->first;
            maxt = it->second;
        }
    }
    cout<<maxs<<' '<<maxt;
    return 0;
}
