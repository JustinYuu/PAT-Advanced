#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int m;
    int earh,earm,ears,lath,latm,lats;
    int tmpeart,tmplatt,eart=1000000,latt=0;
    char tmpe[10],tmpl[10];
    char tmpid[16];
    char earid[16],latid[16];
    cin>>m;
    for(int i=0;i<m;++i)
    {
        scanf("%s ",tmpid);
        scanf("%s ",tmpe);
        scanf("%s",tmpl);
        sscanf(tmpe,"%d:%d:%d",&earh,&earm,&ears);
        sscanf(tmpl,"%d:%d:%d",&lath,&latm,&lats);
        tmpeart=ears+earm*100+earh*10000;
        tmplatt=lats+latm*100+lath*10000;
        if(tmpeart<eart)
        {
            eart=tmpeart;
            strcpy(earid,tmpid);
        }
        if(tmplatt>latt)
        {
            latt=tmplatt;
            strcpy(latid,tmpid);
        }
    }
    printf("%s ",earid);
    printf("%s",latid);
    return 0;
}
