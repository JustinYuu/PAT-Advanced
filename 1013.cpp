#include <iostream>
#include <algorithm>
using namespace std;

int N,M,K;
bool edge[1010][1010]={0};
bool vis[1010]={0};
void DFS(int root){
	vis[root]=true;
	for(int i=1;i<=N;i++){
		if(edge[root][i]&&vis[i]==false){
			DFS(i);
		}
	}
}
int DFStrav(){
	int g=0;
	for(int i=1;i<=N;i++){
		if(vis[i]==false){
			DFS(i);
			g++;
		}
	}
	return g;
}
int main(){
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;i++){
		int c1,c2;
		scanf("%d%d",&c1,&c2);
		edge[c1][c2]=edge[c2][c1]=true;
	}
	for(int i=0;i<K;i++){
		int temp;
		scanf("%d",&temp);
		vis[temp]=true;
		printf("%d\n",DFStrav()-1);
		fill(vis,vis+1010,0);
	}
	return 0;
}
