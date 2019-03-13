#include <cstdio>
#include <algorithm>

#define MAX_N 1024

using namespace std;

int nums[MAX_N];
int lt[MAX_N];
int gt[MAX_N];
int N;

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &nums[i]);

    if (N == 1)
    {
        printf("%d", nums[1]);
        return 0;
    }

    sort(nums + 1, nums + N + 1);

    lt[1] = 0;

    for (int i = 2; i <= N; i++)
    {
        if (nums[i] > nums[i - 1])
            lt[i] = i - 1;
        else
            lt[i] = lt[i - 1];
    }

    gt[N] = 0;

    for (int i = N - 1; i >= 1; i--)
    {
        if (nums[i] < nums[i + 1])
            gt[i] = N - i;
        else
        {
            gt[i] = gt[i + 1];
        }
        if (lt[i] == gt[i])
        {
            printf("%d", nums[i]);
            return 0;
        }
    }

    printf("-1");

    return 0;
}
