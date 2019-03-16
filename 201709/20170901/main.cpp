#include <cstdio>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    int total = 0;

    total += 7 * (N / 50);
    N = N - 50 * (N / 50);
    total += 4 * (N / 30);
    N = N - 30 * (N / 30);
    total += N / 10;

    printf("%d", total);

    return 0;
}
