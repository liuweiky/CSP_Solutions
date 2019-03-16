#include <cstdio>

using namespace std;

int main()
{
    int total = 0;
    int bonus = 1;

    int t;
    scanf("%d", &t);

    while (t != 0)
    {
        if (t == 1)
        {
            bonus = 1;
            total += bonus;
        }
        else if (t == 2)
        {
            if (bonus == 1)
                bonus = 2;
            else
                bonus += 2;
            total += bonus;
        }
        scanf("%d", &t);
    }

    printf("%d", total);
    return 0;
}
