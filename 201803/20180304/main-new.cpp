#include <cstdio>
#include <climits>
#include <algorithm>

#define ALICE 1
#define BOB 2
#define EMPTY 0

#define NOT_FINISHED INT_MAX

using namespace std;

int chess[10];

int get_score()
{
    if ((chess[1] == ALICE && chess[2] == ALICE && chess[3] == ALICE) ||
        (chess[4] == ALICE && chess[5] == ALICE && chess[6] == ALICE) ||
        (chess[7] == ALICE && chess[8] == ALICE && chess[9] == ALICE) ||
        (chess[1] == ALICE && chess[4] == ALICE && chess[7] == ALICE) ||
        (chess[2] == ALICE && chess[5] == ALICE && chess[8] == ALICE) ||
        (chess[3] == ALICE && chess[6] == ALICE && chess[9] == ALICE) ||
        (chess[1] == ALICE && chess[5] == ALICE && chess[9] == ALICE) ||
        (chess[3] == ALICE && chess[5] == ALICE && chess[7] == ALICE))
    {
        int s = 0;
        for (int i = 1; i <= 9; i++)
        {
            if (chess[i] == EMPTY)
                s++;
        }
        return s + 1;
    }
    if ((chess[1] == BOB && chess[2] == BOB && chess[3] == BOB) ||
        (chess[4] == BOB && chess[5] == BOB && chess[6] == BOB) ||
        (chess[7] == BOB && chess[8] == BOB && chess[9] == BOB) ||
        (chess[1] == BOB && chess[4] == BOB && chess[7] == BOB) ||
        (chess[2] == BOB && chess[5] == BOB && chess[8] == BOB) ||
        (chess[3] == BOB && chess[6] == BOB && chess[9] == BOB) ||
        (chess[1] == BOB && chess[5] == BOB && chess[9] == BOB) ||
        (chess[3] == BOB && chess[5] == BOB && chess[7] == BOB))
    {
        int s = 0;
        for (int i = 1; i <= 9; i++)
        {
            if (chess[i] == EMPTY)
                s++;
        }
        return -(s + 1);
    }
    for (int i = 1; i <= 9; i++)
        if (chess[i] == EMPTY)
            return NOT_FINISHED;
    return 0;
}

int dfs(int turn)
{
    int score = get_score();
    if (score != NOT_FINISHED)
        return score;
    score = turn == ALICE ? INT_MIN : INT_MAX;
    for (int i = 1; i <= 9; i++)
    {
        if (chess[i] != EMPTY)
            continue;
        if (turn == ALICE)
        {
            chess[i] = ALICE;
            score = max(score, dfs(BOB));
        }
        else
        {
            chess[i] = BOB;
            score = min(score, dfs(ALICE));
        }
        chess[i] = EMPTY;
    }
    return score;
}

int main()
{
    int T;

    scanf("%d", &T);

    for (int k = 0; k < T; k++)
    {
        for (int i = 1; i <= 9; i++)
            scanf("%d", &chess[i]);
        printf("%d\n", dfs(ALICE));
    }
    return 0;
}
