#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef struct
{
    int month,day,hour,minute;
    bool ison;
}info;
typedef struct
{
    vector<info> data;
    string name;
}user;

int cmp1(user a,user b)
{
    return a.name<b.name;
}

int cmp2(info a,info b)
{
    int tmpa,tmpb;
    tmpa=a.minute+a.hour*100+a.day*10000+a.month*1000000;
    tmpb=b.minute+b.hour*100+b.day*10000+b.month*1000000;
    return tmpa<tmpb;
}

int main()
{
    float price[24];
    int n;
    int namenum=1;
    float total;
    vector<user> p;

    for(int i=0;i<24;++i)
    {
        cin>>price[i];
        price[i]/=100;
    }
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int j;
        user tmp1;
        info tmp2;
        string tmp3;
        cin>>tmp1.name;
        scanf("%d:%d:%d:%d",&tmp2.month,&tmp2.day,&tmp2.hour,&tmp2.minute);
        cin>>tmp3;
        if(tmp3=="on-line")
            tmp2.ison=true;
        else
            tmp2.ison=false;

        for(j=0;j<p.size();++j)
            if(p[j].name==tmp1.name)
                break;
        if(j==p.size())
            p.push_back(tmp1);
        p[j].data.push_back(tmp2);
    }
    sort(p.begin(),p.end(),cmp1);
    for(int i=0;i<p.size();++i)
    {
        int flag=0;
        total=0;
        sort(p[i].data.begin(),p[i].data.end(),cmp2);
        int j=0;
        while(p[i].data[j].ison==false)
            j++;
        for(;j<p[i].data.size();++j)
        {
            float once=0;
            info start,end;
            if(p[i].data[j].ison)
                start=p[i].data[j];
            else if(p[i].data[j-1].ison)
            {
                if(flag==0)
                {
                    cout<<p[i].name;
                    printf(" %02d\n",p[i].data[0].month);
                    flag=1;
                }
                end=p[i].data[j];
                printf("%02d:%02d:%02d %02d:%02d:%02d ",start.day,start.hour,start.minute,end.day,end.hour,end.minute);
                int time=end.minute+end.hour*60+end.day*24*60-(start.minute+start.hour*60+start.day*24*60);
                cout<<time<<' ';
                if(end.day-start.day>1)
                {
                    for(int k=0;k<24;++k)
                        once+=price[k]*60*(end.day-start.day-1);
                }
                if(end.day-start.day>=1)
                {
                    for(int k=0;k<end.hour;++k)
                        once+=price[k]*60;
                    for(int k=start.hour+1;k<24;++k)
                        once+=price[k]*60;
                    once+=price[end.hour]*end.minute;
                    once+=price[start.hour]*(60-start.minute);
                }
                else
                {
                    if(end.hour-start.hour>1)
                    {
                        for(int k=start.hour+1;k<end.hour;k++)
                            once+=price[k]*60;
                    }
                    if(end.hour-start.hour>=1)
                    {
                        once+=price[end.hour]*end.minute;
                        once+=price[start.hour]*(60-start.minute);
                    }
                    else
                        once+=price[start.hour]*(end.minute-start.minute);
                }
                printf("$%.2f\n",once);
                total+=once;
            }
        }
        if(total!=0)
            printf("Total amount: $%.2f\n",total);
    }
}
