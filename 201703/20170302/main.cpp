#include <cstdio>

#define MAX_N 1024

using namespace std;

int id_pos[MAX_N];
int que[MAX_N];
int N, M;

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
        id_pos[i] = que[i] = i;

    for (int i = 0; i < M; i++)
    {
        int p, q;
        scanf("%d %d", &p, &q);

        int pos = id_pos[p];
        if (q > 0)
        {
            for (int j = 1; j <= q; j++)
            {
                int tid = que[pos + j];
                id_pos[tid]--;
                que[pos + j - 1] = tid;
            }
            que[pos + q] = p;
            id_pos[p] += q;
        }
        else
        {
            q = -q;
            for (int j = 1; j <= q; j++)
            {
                int tid = que[pos - j];
                id_pos[tid]++;
                que[pos - j + 1] = tid;
            }
            que[pos - q] = p;
            id_pos[p] -= q;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (i != 1)
            printf(" ");
        printf("%d", que[i]);
    }

    return 0;
}
