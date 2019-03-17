#include <cstdio>

#define MAX_N 1024

using namespace std;

int nums[MAX_N];
int N;

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &nums[i]);

    int cnt = 0;

    for (int i = 2; i <= N - 1; i++)
    {
        if ((nums[i - 1] > nums[i] && nums[i] < nums[i + 1]) || (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]))
            cnt++;
    }

    printf("%d", cnt);

    return 0;
}
