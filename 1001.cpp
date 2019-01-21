#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    char c[10];
    sprintf(c,"%d",abs(a+b));
    if(a+b<0)
        cout<<'-';
    for(int i=strlen(c);i>0;i--)
    {
        if(i%3==0&&i!=strlen(c))
            cout<<',';
        cout<<c[strlen(c)-i];
    }
    return 0;
}
