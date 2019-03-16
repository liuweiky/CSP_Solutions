#include <cstdio>

#define MAX_N 1024

using namespace std;

int weights[MAX_N];
int N, K;

int main()
{
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
        scanf("%d", &weights[i]);

    int p = 0, cnt = 0;

    while (p < N)
    {
        int w = 0;
        while (p < N && w < K)
            w += weights[p++];
        cnt++;
    }

    printf("%d", cnt);

    return 0;
}
