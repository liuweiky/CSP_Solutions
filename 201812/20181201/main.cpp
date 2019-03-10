#include <cstdio>

using namespace std;

int r, y, g;
int n;

int main()
{
    scanf("%d %d %d", &r, &y, &g);
    scanf("%d", &n);

    long long total = 0;

    for (int i = 0; i < n; i++)
    {
        int k, t;
        scanf("%d %d", &k, &t);
        if (k == 0)
            total += t;
        else if (k == 1)
            total += t;
        else if (k == 2)
            total += (t + r);
    }

    printf("%lld", total);

    return 0;
}
