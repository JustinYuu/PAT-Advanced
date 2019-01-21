#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct
{
    int id;
    int data;
    int _rank=0;
}info;
int cmp(info a,info b)
{
    return (a.data>b.data);
}
void printmax(int c,int m,int e,int a)
{
    if(a<=c&&a<=m&&a<=e)
        printf("%d A\n",a);
    else if(c<a&&c<=m&&c<=e)
        printf("%d C\n",c);
    else if(m<a&&m<c&&m<=e)
        printf("%d M\n",m);
    else
        printf("%d E\n",e);
}

int main()
{
    int n,M;
    int tar;
    cin>>n>>M;
    int id,c,m,e,a;
    info *ic = new info[n];
    info *im = new info[n];
    info *ie = new info[n];
    info *ia = new info[n];
    for(int i=0;i<n;++i)
    {
        cin>>id>>c>>m>>e;
        a = round((c + m + e) / 3.0)+0.5;
        ic[i].data=c;
        ic[i].id=id;
        im[i].data=m;
        im[i].id=id;
        ie[i].data=e;
        ie[i].id=id;
        ia[i].data=a;
        ia[i].id=id;
    }
    sort(ic,ic+n,cmp);
    sort(im,im+n,cmp);
    sort(ie,ie+n,cmp);
    sort(ia,ia+n,cmp);
    ic[0]._rank=im[0]._rank=ie[0]._rank=ia[0]._rank=1;
    for(int i=1;i<n;++i)
    {
        if(ic[i].data==ic[i-1].data)
            ic[i]._rank=ic[i-1]._rank;
        else
            ic[i]._rank=i+1;
        if(im[i].data==im[i-1].data)
            im[i]._rank=im[i-1]._rank;
        else
            im[i]._rank=i+1;
        if(ie[i].data==ie[i-1].data)
            ie[i]._rank=ie[i-1]._rank;
        else
            ie[i]._rank=i+1;
        if(ia[i].data==ia[i-1].data)
            ia[i]._rank=ia[i-1]._rank;
        else
            ia[i]._rank=i+1;
    }
    for(int i=0;i<M;++i)
    {
        int minc=-1,mine=-1,mina=-1,minm=-1;
        cin>>tar;
        for(int j=0;j<n;++j)
        {
            if(ic[j].id==tar)
                minc=ic[j]._rank;
            if(im[j].id==tar)
                minm=im[j]._rank;
            if(ie[j].id==tar)
                mine=ie[j]._rank;
            if(ia[j].id==tar)
                mina=ia[j]._rank;
        }
        if(mina+minc+minc+minm==-4)
            printf("N/A\n");
        else
            printmax(minc,minm,mine,mina);
    }
    return 0;
}
