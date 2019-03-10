#include <cstdio>
#include <utility>
#include <algorithm>

#define MAX_N 2048

using namespace std;

pair<int, int> ph[MAX_N], pw[MAX_N];
int n;

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d %d", &ph[i].first, &ph[i].second);

    for (int i = 1; i <= n; i++)
        scanf("%d %d", &pw[i].first, &pw[i].second);

    long long t = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int left = max(ph[i].first, pw[j].first);
            int right = min(ph[i].second, pw[j].second);
            t += max(right - left, 0);
        }
    }

    printf("%lld", t);

    return 0;
}
