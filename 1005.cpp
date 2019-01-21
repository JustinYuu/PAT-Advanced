#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void print(char c)
{
    int a=c-'0';
    switch(a)
    {
        case 1: printf("one");
                break;
        case 2: printf("two");
                break;
        case 3: printf("three");
                break;
        case 4: printf("four");
                break;
        case 5: printf("five");
                break;
        case 6: printf("six");
                break;
        case 7: printf("seven");
                break;
        case 8: printf("eight");
                break;
        case 9: printf("nine");
                break;
        case 0: printf("zero");
                break;
    }
    return;
}
int main()
{
    char n[110];
    int sum=0;
    scanf("%s",n);
    for(int i=0;i<strlen(n);++i)
        sum+=(n[i]-'0');
    char res[110];
    sprintf(res,"%d",sum);
    for(int i=0;res[i]!='\0';i++)
    {
        if(i==0)
            print(res[i]);
        else
        {
            printf(" ");
            print(res[i]);
        }
    }
}
