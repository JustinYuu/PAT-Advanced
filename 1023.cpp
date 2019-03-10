#include <iostream>
#include <string.h>

int main(){
	char c,str[30];
	int a[30],index=0,freq[10]={0};
	scanf("%s",str);
	int len=strlen(str);
	for(int i=len-1;i>=0;i--){
		a[len-i-1]=str[i]-'0';
		freq[str[i]-'0']++;
	}
	int gain=0;
	for(int i=0;i<len;i++){
		int temp=2*a[i]+gain;
		a[i]=temp%10;
		gain=temp/10;
		freq[a[i]]--;
	}
	bool ans=true;
	if(gain!=0){
		a[len++]=gain;
		ans=false;
	}
	for(int i=0;i<10;i++){
		if(freq[i]!=0) ans=false;
	}
	ans?printf("Yes\n"):printf("No\n");
	for(int i=len-1;i>=0;i--)
		printf("%d",a[i]);
	return 0;
}
