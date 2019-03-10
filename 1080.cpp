#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 40010;
const int maxm = 110;

typedef struct
{
    int ge,gi;
    int id;
}grade;

int cmp(grade a,grade b)
{
    if((a.ge+a.gi)!=(b.ge+b.gi))
        return (a.ge+a.gi)>(b.ge+b.gi);
    else
        return a.ge>b.ge;
}
int main()
{
    int n,m,k;
    int adnum[maxm];
    grade p[maxn];
    vector<int> req[maxn];
    vector<int> lst[maxn];

    cin>>n>>m>>k;
    for(int i=0;i<m;++i)
        cin>>adnum[i];
    for(int i=0;i<n;++i)
    {
        p[i].id = i;
        cin>>p[i].ge>>p[i].gi;
        for(int j=0;j<k;++j)
        {
            int tmpch;
            cin>>tmpch;
            req[i].push_back(tmpch);
        }
    }
    sort(p,p+n,cmp);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<k;++j)
        {
            int lastreqstnum;
            int reqscnum = req[p[i].id][j];
            if(lst[reqscnum].size()>0)
                lastreqstnum = lst[reqscnum][lst[reqscnum].size()-1];
            if(adnum[reqscnum]>0||(lst[reqscnum].size()>0&&p[i].ge==p[lastreqstnum].ge&&p[i].gi==p[lastreqstnum].gi))
            {
                adnum[reqscnum]--;
                lst[reqscnum].push_back(p[i].id);
                break;
            }
        }
    }
    for(int i=0;i<m;++i)
    {
        sort(lst[i].begin(),lst[i].end());
        if(lst[i].size()>0)
        {
            printf("%d",lst[i][0]);
            for(int j=1;j<lst[i].size();++j)
                printf(" %d",lst[i][j]);
        }
        printf("\n");
    }
    return 0;
}
