#include <cstdio>
#include <climits>
#include <algorithm>

#define MAX_N 1024

using namespace std;

int N;
int nums[MAX_N];

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &nums[i]);

    int min_d = INT_MAX;

    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            min_d = min(min_d, abs(nums[i] - nums[j]));

    printf("%d", min_d);

    return 0;
}
