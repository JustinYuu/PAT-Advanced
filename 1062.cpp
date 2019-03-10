#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef struct
{
    int id,vg,tg;
}student;

int cmp(student a,student b)
{
    if((a.vg+a.tg)!=(b.vg+b.tg))
        return (a.vg+a.tg)>(b.vg+b.tg);
    else if(a.vg!=b.vg)
        return a.vg>b.vg;
    else
        return a.id<b.id;
}
int main()
{
    int n,l,h,total;
    student tmp;
    vector<student> sage,noble,fool,small;

    cin>>n>>l>>h;
    for(int i=0;i<n;++i)
    {
        scanf("%d %d %d",&tmp.id,&tmp.vg,&tmp.tg);
        if(tmp.vg<l||tmp.tg<l)
            continue;
        else if(tmp.tg>=h&&tmp.vg>=h)
            sage.push_back(tmp);
        else if(tmp.tg<h&&tmp.vg>=h)
            noble.push_back(tmp);
        else if(tmp.tg<h&&tmp.vg<h&&tmp.vg>=tmp.tg)
            fool.push_back(tmp);
        else
            small.push_back(tmp);
    }
    total=sage.size()+noble.size()+fool.size()+small.size();
    sort(sage.begin(),sage.end(),cmp);
    sort(noble.begin(),noble.end(),cmp);
    sort(fool.begin(),fool.end(),cmp);
    sort(small.begin(),small.end(),cmp);


    printf("%d\n",total);
    for(int i=0;i<sage.size();++i)
        printf("%d %d %d\n",sage[i].id,sage[i].vg,sage[i].tg);
    for(int i=0;i<noble.size();++i)
        printf("%d %d %d\n",noble[i].id,noble[i].vg,noble[i].tg);
    for(int i=0;i<fool.size();++i)
        printf("%d %d %d\n",fool[i].id,fool[i].vg,fool[i].tg);
    for(int i=0;i<small.size();++i)
        printf("%d %d %d\n",small[i].id,small[i].vg,small[i].tg);
    return 0;
}
