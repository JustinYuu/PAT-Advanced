#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n,k;
    int ci,cn;
    string tmp;
    map<string,vector<int>> p;

    scanf("%d %d",&n,&k);
    for(int i=0;i<k;++i)
    {
        scanf("%d %d",&ci,&cn);
        for(int j=0;j<cn;++j)
        {
            cin>>tmp;
            p[tmp].push_back(ci);
        }
    }
    for(int i=0;i<n;++i)
    {
        cin>>tmp;
        sort(p[tmp].begin(),p[tmp].end());
        cout<<tmp<<' ';
        printf("%d",p[tmp].size());
        for(int j=0;j<p[tmp].size();++j)
            cout<<' '<<p[tmp][j];
        printf("\n");
    }
    return 0;
}
