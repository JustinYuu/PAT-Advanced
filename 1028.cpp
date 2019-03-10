#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

typedef struct
{
    char id[7];
    char name[9];
    int grade;
}student;

int cmp1(student a,student b)
{
    return strcmp(a.id,b.id)<0;
}

int cmp2(student a,student b)
{
    if(strcmp(a.name,b.name)!=0)
        return strcmp(a.name,b.name)<0;
    else
        return strcmp(a.id,b.id)<0;
}

int cmp3(student a,student b)
{
    if(a.grade!=b.grade)
        return a.grade<b.grade;
    else
        return a.id<b.id;
}


int main()
{
    int n,c;
    scanf("%d %d",&n,&c);
    student* p =new student[n];

    for(int i=0;i<n;++i)
        scanf("%s %s %d",p[i].id,p[i].name,&p[i].grade);

    if(c==1)
        sort(p,p+n,cmp1);
    else if(c==2)
        sort(p,p+n,cmp2);
    else
        sort(p,p+n,cmp3);

    for(int i=0;i<n;++i)
        printf("%s %s %d\n",p[i].id,p[i].name,p[i].grade);
    return 0;
}
