#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

typedef struct
{
    string name,pwd;
}account;
int main()
{
    int n;
    vector<account> p;
    int modi=0;
    bool ismodi;

    cin>>n;
    for(int i=0;i<n;++i)
    {
        account tmp;
        cin>>tmp.name>>tmp.pwd;
        ismodi=false;
        for(int i=0;i<tmp.pwd.length();++i)
        {
            if(tmp.pwd[i]=='1')
            {
                tmp.pwd[i]='@';
                ismodi=true;
            }
            else if(tmp.pwd[i]=='0')
            {
                tmp.pwd[i]='%';
                ismodi=true;
            }
            else if(tmp.pwd[i]=='l')
            {
                tmp.pwd[i]='L';
                ismodi=true;
            }
            else if(tmp.pwd[i]=='O')
            {
                tmp.pwd[i]='o';
                ismodi=true;
            }
        }
        if(ismodi)
        {
            p.push_back(tmp);
            modi++;
        }
    }
    if(!modi)
    {
        if(n==1)
            printf("There is 1 account and no account is modified");
        else
            printf("There are %d accounts and no account is modified",n);
    }
    else
    {
        printf("%d\n",modi);
        for(int i=0;i<modi;++i)
            cout<<p[i].name<<' '<<p[i].pwd<<endl;
    }
    return 0;
}
