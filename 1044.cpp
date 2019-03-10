#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int sum[maxn];

int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d%d", &N, &M);
    int sumOfSubsequence = 100010;
    for(int i = 1; i<=N; i++)
    {
        scanf("%d", &sum[i]);
        sum[i] += sum[i-1];
    }
    int j;
    for(int i = 0; i<N; i++)
    {
        j = lower_bound(sum+i, sum+N, sum[i]+M)-sum;
        if(sum[j] - sum[i] == M)
        {
            sumOfSubsequence = M;
            break;
        }
        else if(sum[j] - sum[i] - M > 0 &&sum[j] - sum[i] < sumOfSubsequence)   sumOfSubsequence = sum[j] - sum[i];
    }
    for(int i = 0; i<N; i++)
    {
        j = lower_bound(sum+i, sum+N, sum[i]+M)-sum;
        if(sum[j] - sum[i] == sumOfSubsequence)
        {
            printf("%d-%d\n",i+1,j );
        }
    }

    return 0;
}
