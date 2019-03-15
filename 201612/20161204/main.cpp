#include <cstdio>
#include <climits>
#include <algorithm>

#define MAX_N 1024

using namespace std;

int dp[MAX_N][MAX_N];
int sum[MAX_N];
int N;

int main()
{
    fill_n(&dp[0][0], MAX_N * MAX_N, INT_MAX);
    fill_n(sum, MAX_N, 0);
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        int x;
        scanf("%d", &x);
        sum[i] = sum[i - 1] + x;
        dp[i][i] = 0;
    }

    for (int len = 1; len <= N; len++)
    {
        for (int i = 1; i + len <= N; i++)
        {
            int j = i + len;
            for (int k = i; k + 1 <= j; k++)
                //dp[i][j] = min(dp[i][k] + dp[k + 1][j] + sum[k] - sum[i - 1] + sum[j] - sum[k], dp[i][j]);
                dp[i][j] = min(dp[i][k] + dp[k + 1][j] - sum[i - 1] + sum[j], dp[i][j]);
        }
    }

    printf("%d", dp[1][N]);

    return 0;
}
