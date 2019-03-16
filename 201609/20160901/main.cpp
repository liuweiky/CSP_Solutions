#include <cstdio>
#include <algorithm>
#include <climits>

#define MAX_N 1024

using namespace std;

int nums[MAX_N];
int N;

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &nums[i]);

    int maxx = INT_MIN;

    for (int i = 2; i <= N; i++)
        maxx = max(maxx, abs(nums[i] - nums[i - 1]));

    printf("%d", maxx);

    return 0;
}
