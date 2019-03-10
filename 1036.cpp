#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

typedef struct
{
    string name,id;
    char gender;
    int grade;
}student;

int main()
{
    int n;
    student maxf,minm,tmp;

    cin>>n;
    maxf.grade=-1;
    minm.grade=101;
    for(int i=0;i<n;++i)
    {
        cin>>tmp.name>>tmp.gender>>tmp.id>>tmp.grade;
        if(tmp.gender=='M'&&tmp.grade<minm.grade)
            minm=tmp;
        if(tmp.gender=='F'&&tmp.grade>maxf.grade)
            maxf=tmp;
    }
    if(maxf.grade!=-1)
        cout<<maxf.name<<' '<<maxf.id<<endl;
    else
        cout<<"Absent"<<endl;
    if(minm.grade!=101)
        cout<<minm.name<<' '<<minm.id<<endl;
    else
        cout<<"Absent"<<endl;
    if(maxf.grade!=-1&&minm.grade!=101)
        cout<<maxf.grade-minm.grade;
    else
        cout<<"NA";
    return 0;
}
