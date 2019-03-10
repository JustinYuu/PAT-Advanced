#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1001;
int dp[maxn][maxn];
char S[maxn];

int main()
{
    scanf("%[^\n]",&S);
    int len = strlen(S);
    int ans = 1;
    fill(dp[0],dp[0]+maxn*maxn,0);
    for(int i=0;i<len;++i)
    {
        dp[i][i]=1;
        if(i<len-1)
        {
            if(S[i]==S[i+1])
            {
                dp[i][i+1]=1;
                ans=2;
            }
        }
    }
    for(int i=3;i<=len;++i)
    {
        for(int j=0;j+i-1<len;++j)
        {
            int k=i+j-1;
            if(S[j]==S[k]&&dp[j+1][k-1]==1)
            {
                dp[j][k]=1;
                ans = i;
            }
        }
    }
    cout<<ans;
    return 0;
}
