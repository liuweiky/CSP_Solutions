#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>
#include <algorithm>

#define ALICE 1
#define BOB 2
#define EMPTY 0

#define TIE 1
#define WIN 2
#define NOT_FINISHED 0

using namespace std;

int chess[10];

int adfs();
int bdfs();

int check()
{
    if ((chess[1] == chess[2] && chess[2] == chess[3] && chess[1] != EMPTY) ||
        (chess[4] == chess[5] && chess[5] == chess[6] && chess[4] != EMPTY) ||
        (chess[7] == chess[8] && chess[8] == chess[9] && chess[7] != EMPTY) ||
        (chess[1] == chess[4] && chess[4] == chess[7] && chess[1] != EMPTY) ||
        (chess[2] == chess[5] && chess[5] == chess[8] && chess[2] != EMPTY) ||
        (chess[3] == chess[6] && chess[6] == chess[9] && chess[3] != EMPTY) ||
        (chess[1] == chess[5] && chess[5] == chess[9] && chess[1] != EMPTY) ||
        (chess[3] == chess[5] && chess[5] == chess[7] && chess[3] != EMPTY))
            return WIN;
    for (int i = 1; i <= 9; i++)
        if (chess[i] == EMPTY)
            return NOT_FINISHED;
    return TIE;
}

int get_ascore()
{
    int empty_count = 0;
    for (int i = 1; i <= 9; i++)
        if (chess[i] == EMPTY)
            empty_count++;
    return empty_count;
}

int get_bscore()
{
    int empty_count = 0;
    for (int i = 1; i <= 9; i++)
        if (chess[i] == EMPTY)
            empty_count++;
    return - empty_count;
}

// alice 只想获得很大的score
int adfs()  // 返回 alice 下棋的最好得分情况
{
    if (check() == WIN)    // 上次是bob下的，他赢了
        return get_bscore() - 1;
    else if (check() == TIE)
        return 0;
    int max_score = INT_MIN;    // 记录alice 自己能获得的score中最大的情况
    for (int i = 1; i <= 9; i++)
    {
        if (chess[i] == EMPTY)
        {
            chess[i] = ALICE;
            max_score = max(bdfs(), max_score);
            chess[i] = EMPTY;
        }
    }
    return max_score;
}

// bob 不让alice获得很大score
int bdfs()  // 返回 bob 落子后，使得 alice 得分最低
{
    if (check() == WIN)    // 上次是alice下的，她赢了
        return get_ascore() + 1;
    else if (check() == TIE)
        return 0;
    int min_score = INT_MAX;    // 记录alice能获得的score中最小的情况，不让alice获得很大score
    for (int i = 1; i <= 9; i++)
    {
        if (chess[i] == EMPTY)
        {
            chess[i] = BOB;
            min_score = min(adfs(), min_score); // 在 alice 得分中取最小得分
            chess[i] =  EMPTY;
        }
    }
    return min_score;
}

int main()
{
    int T;

    scanf("%d", &T);

    for (int k = 0; k < T; k++)
    {
        memset(chess, 0, 10);
        for (int i = 1; i <= 9; i++)
            scanf("%d", &chess[i]);
        printf("%d\n", adfs());
    }
    return 0;
}
