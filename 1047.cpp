#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 2505;
const int N = 40005;
vector<int> stuList[M];
char name[N][5];

int getStuId(char name[]){
    int id = 0;
    for(int i = 0; i < 3; i++){
        id = id*26 + (name[i]-'A');
    }
    id = id*10 + name[3];

    return id;
}

bool cmp(int a, int b){
    return strcmp(name[a], name[b]) < 0;
}

int main(){

    int n,k;
    scanf("%d %d",&n, &k);

    int courseNum, courseId;
    for(int i = 0; i < n; i++){
        scanf("%s",name[i]);
        scanf("%d", &courseNum);
        for(int j = 0; j < courseNum; j++){
            scanf("%d", &courseId);
            stuList[courseId].push_back(i);
        }
    }

    for(int i = 1; i < k+1; i++){
        printf("%d %d\n", i, stuList[i].size());
        sort(stuList[i].begin(), stuList[i].end(), cmp);
        for(int j = 0; j < stuList[i].size(); j++){
            printf("%s\n",name[stuList[i][j]]);
        }
    }
    return 0;
}
