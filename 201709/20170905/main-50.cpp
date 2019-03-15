#include <cstdio>
#include <algorithm>

#define MAX_N 102400

using namespace std;

long long nums[MAX_N];
long long sums[MAX_N];

int N, M;

int main()
{
    fill_n(sums, MAX_N, 0);

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &nums[i]);
        sums[i] = nums[i] + sums[i - 1];
    }

    for (int i = 0; i < M; i++)
    {
        int opt, l, r;
        long long v;

        scanf("%d", &opt);

        if (opt == 1)
        {
            scanf("%d %d %lld", &l, &r, &v);
            for (int p = l; p <= r; p++)
            {
                if (nums[p] % v == 0)
                {
                    long long decr = nums[p] - nums[p] / v;
                    for (int j = p; j <= N; j++)
                        sums[j] -= decr;
                    nums[p] /= v;
                }
            }
        }
        else
        {
            scanf("%d %d", &l, &r);
            printf("%lld\n", sums[r] - sums[l - 1]);
        }
    }

    return 0;
}
