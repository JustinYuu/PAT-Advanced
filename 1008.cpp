#include <iostream>
#include<cstdio>
int main()
{
	int stay=0,t;
	int N,i,total=0;
	scanf("%d",&N);
	for(i=0;i<N;++i)
	{
		scanf("%d",&t);
		if(t==stay)
		{
			total+=5;
			continue;

		}
		if(t>stay)
			total+=(t-stay)*6+5;
		else
			total+=(stay-t)*4+5;
		stay=t;
	}
	printf("%d",total);
	return 0;
}
