#include <cstdio>
#include <algorithm>

#define MAX_N 102400

using namespace std;

int nums[MAX_N];
long long C[MAX_N];

int N, M;

int low_bit(int x)
{
    return x & (-x);
}

void update(int idx, int delta)
{
    nums[idx] += delta;

    for (int i = idx; i <= N; i += low_bit(i))
        C[i] += delta;
}

long long get_sum(int idx)
{
    long long sum = 0;

    for (int i = idx; i > 0; i -= low_bit(i))
        sum += C[i];

    return sum;
}

int main()
{
    fill_n(nums, MAX_N, 0);
    fill_n(C, MAX_N, 0);

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
    {
        int x;
        scanf("%d", &x);
        update(i, x);
    }

    for (int i = 0; i < M; i++)
    {
        int opt, l, r, v;
        scanf("%d", &opt);

        if (opt == 1)
        {
            scanf("%d %d %d", &l, &r, &v);
            if (v == 1)
                continue;
            for (int p = l; p <= r; p++)
            {
                if (nums[p] >= v && nums[p] % v == 0)
                    update(p, -(nums[p] - nums[p] / v));
            }
        }
        else
        {
            scanf("%d %d", &l, &r);
            printf("%lld\n", get_sum(r) - get_sum(l - 1));
        }
    }

    return 0;
}
