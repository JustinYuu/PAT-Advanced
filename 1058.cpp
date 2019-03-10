#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int ag,as,ak,bg,bs,bk;
    int cg,cs,ck;
    scanf("%d.%d.%d %d.%d.%d",&ag,&as,&ak,&bg,&bs,&bk);

    ck=(ak+bk)%29;
    cs=((ak+bk)/29+as+bs)%17;
    cg=((ak+bk)/29+as+bs)/17+ag+bg;
    printf("%d.%d.%d",cg,cs,ck);
    return 0;
}
