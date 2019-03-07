#include <cstdio>

using namespace std;

int r, y, g, round;
int n;

int main()
{
    scanf("%d %d %d", &r, &y, &g);
    scanf("%d", &n);

    round = r + y + g;

    long long tt_time = 0;

    for (int i = 0; i < n; i++)
    {
        int k, t;
        scanf("%d %d", &k, &t);
        if (k == 0)
        {
            tt_time += t;
            continue;
        }
        int tmp_time = tt_time % round;
        if (k == 1)
        {
            int offset = r - t;
            tmp_time += offset;
        }
        else if (k == 2)
        {
            int offset = (r + g + y) - t;
            tmp_time += offset;
        }
        else
        {
            int offset = (r + g) - t;
            tmp_time += offset;
        }
        tmp_time %= round;
        if (tmp_time < r)
            tt_time += (r - tmp_time);
        else if (tmp_time >= r && tmp_time < r + g);
        else
        {
            tt_time += (round - tmp_time + r);
        }
    }

    printf("%lld", tt_time);

    return 0;
}
