#include <cstdio>
#include <algorithm>

#define MAX_N 512

using namespace std;

int yes[MAX_N];
int today[MAX_N];
bool vis[MAX_N][MAX_N][MAX_N];

int n;

bool flag = false;

void cal(int d)
{
    if (d == 3 && (yes[1] + yes[2]) / 2 != today[1])
        return;
    if (d > 3 && (yes[d - 1] + yes[d - 2] + yes[d - 3]) / 3 != today[d - 2])
        return;
    if (d >= 2)
    {
        if (vis[d][yes[d - 1]][yes[d - 2]])
            return;
        vis[d][yes[d - 1]][yes[d - 2]] = true;
    }
    if (d == n + 1 && (yes[n] + yes[n - 1]) / 2 == today[n])
    {
        for (int i = 1; i<= n; i++)
            printf("%d ", yes[i]);
        flag = true;
        return;
    }

    if (d == 1)
    {
        int max_p = 2 * today[1] + 1;
        for (int i = 1; i <= max_p; i++)
        {
            yes[1] = i;
            if (!flag)
                cal(2);
        }
        return;
    }

    int max_p = 3 * today[d] + 2 - yes[d - 1];
    for (int i = 1; i <= max_p; i++)
    {
        yes[d] = i;
        if (!flag)
            cal(d + 1);
    }

}

int main()
{
    fill_n(&vis[0][0][0], MAX_N * MAX_N * MAX_N, false);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &today[i]);
    if (n == 1)
    {
        printf("%d", today[1]);
        return 0;
    }
    cal(1);
    return 0;
}
