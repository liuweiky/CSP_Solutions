#include <cstdio>
#include <vector>

using namespace std;

struct ball
{
    int pos, dir;
};

vector<ball> balls;

int N, L, T;

int main()
{
    scanf("%d %d %d", &N, &L, &T);

    for (int i = 0; i < N; i++)
    {
        ball b;
        scanf("%d", &b.pos);
        b.dir = 1;
        balls.push_back(b);
    }

    while (T--)
    {
        for (int i = 0; i < N; i++)
            if ((balls[i].pos == L && balls[i].dir == 1) || (balls[i].pos == 0 && balls[i].dir == -1))
                balls[i].dir = -balls[i].dir;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (balls[i].pos == balls[j].pos)
                {
                    balls[i].dir = -balls[i].dir;
                    balls[j].dir = -balls[j].dir;
                    break;
                }
            }
        }
        for (int i = 0; i < N; i++)
            balls[i].pos += balls[i].dir;

    }

    for (int i = 0; i < N; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", balls[i].pos);
    }

    return 0;
}
