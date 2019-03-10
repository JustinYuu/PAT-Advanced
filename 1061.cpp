#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
    string str1,str2;
    int dd=0,hh,mm;
    cin>>str1>>str2;
    int len = min(str1.length(),str2.length());
    bool flag = false;
    for(int i=0;i<len;++i)
    {
        if(!flag&&str1[i]==str2[i]&&str1[i]>='A'&&str1[i]<='G')
        {
            dd=str1[i]-'A'+1;
            flag = true;
            continue;
        }
        if(flag&&str1[i]==str2[i]&&(isdigit(str1[i])||(str1[i]<='N'&&str1[i]>='A')))
        {
            if(isdigit(str1[i]))
            {
                hh=str1[i]-'0';
                break;
            }
            else
            {
                hh=str1[i]-'A'+10;
                break;
            }
        }
    }
    cin>>str1>>str2;
    len = min(str1.length(),str2.length());
    for(int j=0;j<len;++j)
    {
        if(str1[j]==str2[j]&&(isupper(str1[j])||islower(str1[j])))
        {
            mm=j;
            break;
        }
    }
    if(dd==1)
        printf("MON ");
    else if(dd==2)
        printf("TUE ");
    else if(dd==3)
        printf("WED ");
    else if(dd==4)
        printf("THU ");
    else if(dd==5)
        printf("FRI ");
    else if(dd==6)
        printf("SAT ");
    else
        printf("SUN ");
    printf("%02d:%02d",hh,mm);
    return 0;
}
