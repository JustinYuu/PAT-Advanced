#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    int Hashtable[37]={0};
    string stra,strb;
    cin>>stra>>strb;
    for(int i=0;i<stra.length();++i)
    {
        if(isalpha(stra[i]))
        {
            stra[i]=toupper(stra[i]);
            Hashtable[stra[i]-'A']=1;
        }
        else if(isdigit(stra[i]))
            Hashtable[stra[i]-'0'+26]=1;
        else
            Hashtable[36] = 1;
    }
    for(int i=0;i<strb.length();++i)
    {
        if(isalpha(strb[i]))
        {
            strb[i]=toupper(strb[i]);
            Hashtable[strb[i]-'A']=2;
        }
        else if(isdigit(strb[i]))
            Hashtable[strb[i]-'0'+26]=2;
        else
            Hashtable[36] = 2;
    }
    for(int i=0;i<stra.length();++i)
    {
        if(isalpha(stra[i]))
        {
            if(Hashtable[stra[i]-'A']==1)
            {
                printf("%c",stra[i]);
                Hashtable[stra[i]-'A']=0;
            }
        }
        else if(isdigit(stra[i]))
        {
            if(Hashtable[stra[i]-'0'+26]==1)
            {
                printf("%c",stra[i]);
                Hashtable[stra[i]-'0'+26]=0;
            }
        }
        else
        {
            if(Hashtable[36] == 1)
            {
                printf("%c",stra[i]);
                Hashtable[36]=0;
            }
        }
    }
    return 0;
}
