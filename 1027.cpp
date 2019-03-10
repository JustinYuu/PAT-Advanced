#include <iostream>
#include <cstdio>
using namespace std;
void Output(int a)
{
    if(a==10)
        cout<<'A';
    else if(a==11)
        cout<<'B';
    else if(a==12)
        cout<<'C';
    else
        cout<<a;
}
int main()
{
    int r,g,b;
    cin>>r>>g>>b;
    int r1,r2,g1,g2,b1,b2;
    r1 = r/13;
    r2 = r%13;
    g1 = g/13;
    g2 = g%13;
    b1 = b/13;
    b2 = b%13;
    cout<<'#';
    Output(r1);
    Output(r2);
    Output(g1);
    Output(g2);
    Output(b1);
    Output(b2);
    return 0;
}
