#include <cstdio>

#define MAX_N 1024

using namespace std;

int price[MAX_N];
int tmp[MAX_N];
int n;

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &price[i]);

    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            tmp[i] = (price[i] + price[i + 1]) / 2;
            continue;
        }
        if (i == n)
        {
            tmp[i] = (price[i] + price[i - 1]) / 2;
            continue;
        }
        tmp[i] = (price[i - 1] + price[i] + price[i + 1]) / 3;
    }

    for (int i = 1; i <= n; i++)
    {
        if (i != 1)
            printf(" ");
        printf("%d", tmp[i]);
    }

    return 0;
}
