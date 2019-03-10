#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
    string name,id;
    int grade;
}student;

int cmp(student a,student b)
{
    return a.grade>b.grade;
}
int main()
{
    int n;
    vector<student> p;
    int lowb,uppb;

    cin>>n;
    for(int i=0;i<n;++i)
    {
        student tmp;
        cin>>tmp.name>>tmp.id>>tmp.grade;
        p.push_back(tmp);
    }
    cin>>lowb>>uppb;
    sort(p.begin(),p.end(),cmp);
    int num=0;
    for(int i=0;i<p.size();++i)
    {
        if(p[i].grade>=lowb&&p[i].grade<=uppb)
        {
            num++;
            cout<<p[i].name<<' '<<p[i].id<<endl;
        }
    }
    if(num==0)
        printf("NONE");
    return 0;
}
