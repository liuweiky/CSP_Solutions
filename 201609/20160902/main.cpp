#include <cstdio>
#include <algorithm>

using namespace std;

bool seats[32][10];

int N;

int main()
{
    fill_n(&seats[0][0], 32 * 10, true);
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int cnt;
        scanf("%d", &cnt);
        bool has_sol = false;
        for (int i = 1; i <= 20 && !has_sol; i++)
        {
            int s = 0, empty_cnt = 0;
            for (int j = 1; j <= 5; j++)
            {
                if (seats[i][j])
                {
                    empty_cnt++;
                    if (empty_cnt == cnt)
                    {
                        for (int k = s + 1; k <= j; k++)
                        {
                            seats[i][k] = false;
                            /*if (k != s + 1)
                                printf(" ");*/
                            printf("%d ", (i - 1) * 5 + k);
                            //printf("(%d, %d)", i, k);
                        }
                        printf("\n");
                        has_sol = true;
                        break;
                    }
                }
                else
                {
                    s = j; empty_cnt = 0;
                }
            }
        }
        if (!has_sol)
        {
            int i = 1, j = 1;
            while (cnt > 0)
            {
                if (seats[i][j])
                {
                    cnt--;
                    seats[i][j] = false;
                    printf("%d ", (i - 1) * 5 + j);
                    //printf("(%d, %d)", i, j);
                    /*if (cnt != 0)
                        printf(" ");*/
                }
                j++;
                if (j > 5)
                {
                    i++;
                    j = 1;
                }
            }
            printf("\n");
        }
    }

    return 0;
}
