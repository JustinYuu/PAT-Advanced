#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct
{
    char name[20];
    int age;
    int worth;
}rich;
int cmp_worth(rich a,rich b)
{
    if(a.worth!=b.worth)
        return a.worth>b.worth;
    else
    {
        if(a.age!=b.age)
            return a.age<b.age;
        else
            return strcmp(a.name,b.name)<=0;
    }
}
rich p[100010];
int main()
{
    int n,k;
    int m,amin,amax;
    int num;
    bool flag;

    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i)
        scanf("%s %d %d",p[i].name,&p[i].age,&p[i].worth);
    sort(p,p+n,cmp_worth);
    for(int i=1;i<=k;++i)
    {
        num=0;
        flag=false;
        scanf("%d %d %d",&m,&amin,&amax);
        printf("Case #%d:\n",i);
        for(int j=0;j<n;++j)
        {
            if(num==100)
                break;
            if(num<m&&p[j].age>=amin&&p[j].age<=amax)
            {
                num++;
                flag=true;
                printf("%s %d %d\n",p[j].name,p[j].age,p[j].worth);
            }
        }
        if(!flag)
            printf("None");
    }
    return 0;
}
