#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    int Hashtable[62] = {0};
    int extra=0,need=0;
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.length();++i)
    {
        if(isupper(a[i]))
            Hashtable[a[i]-'A']++;
        else if(islower(a[i]))
            Hashtable[a[i]-'a'+26]++;
        else
            Hashtable[a[i]-'0'+52]++;
    }
    for(int i=0;i<b.length();++i)
    {
        if(isupper(b[i]))
            Hashtable[b[i]-'A']--;
        else if(islower(b[i]))
            Hashtable[b[i]-'a'+26]--;
        else
            Hashtable[b[i]-'0'+52]--;
    }
    for(int i=0;i<62;++i)
    {
        if(Hashtable[i]<0)
            need+=(-Hashtable[i]);
        else if(Hashtable[i]>0)
            extra+=(Hashtable[i]);
    }
    if(need>0)
        printf("No %d",need);
    else
        printf("Yes %d",extra);
    return 0;
}
