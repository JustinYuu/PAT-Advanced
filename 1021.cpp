#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=10010;
vector<int> arc[maxn];
bool vis[maxn];
int N,depth[maxn],maxdepth=-1,layer[maxn];
int BFS(int root){
	queue<int> q;
	fill(layer,layer+maxn,0);
	q.push(root);
	vis[root]=true;
	layer[root]=1;
	int tdepth=0,count=0;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		count++;
		int len=arc[t].size();
		tdepth=max(tdepth,layer[t]);
		for(int i=0;i<len;i++){
			if(vis[arc[t][i]]==false){
				q.push(arc[t][i]);
				layer[arc[t][i]]=layer[t]+1;
				vis[arc[t][i]]=true;
			}
		}
	}
	if(count<N) return -1;
	else return tdepth;
}
int calcomponent(int root){
	fill(vis,vis+maxn,0);
	int count=0;
	for(int i=1;i<=N;i++){
		if(vis[i]==false){
			BFS(i);
			count++;
		}
	}
	return count;
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<N;i++){
		int v1,v2;
		scanf("%d%d",&v1,&v2);
		arc[v1].push_back(v2);
		arc[v2].push_back(v1);
	}
	for(int i=1;i<=N;i++){
		fill(vis,vis+maxn,0);
		depth[i]=BFS(i);
		if(depth[i]==-1){
			printf("Error: %d components",calcomponent(i));
			return 0;
		}
		maxdepth=max(depth[i],maxdepth);
	}
	for(int i=1;i<=N;i++){
		if(depth[i]==maxdepth){
			printf("%d\n",i);
		}
	}
	return 0;
}
