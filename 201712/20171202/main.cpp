#include <cstdio>
#include <algorithm>

#define MAX_N 1024

using namespace std;

bool out[MAX_N];
int cnt;
int N, K;

int main()
{
    fill_n(out, MAX_N, false);
    scanf("%d %d", &N, &K);

    int ptr = 1, spk = 1;

    cnt = N;

    while (cnt != 1)
    {
        if (!out[ptr])
        {
            if (spk % K == 0 || spk % 10 == K)
            {
                out[ptr] = true;
                cnt--;
            }
            spk++;
        }
        ptr++;
        if (ptr > N)
            ptr = 1;
    }

    for (int i = 1; i <= N; i++)
        if (!out[i])
            printf("%d", i);

    return 0;
}
