#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    double t;
    scanf("%lf", &t);
    if (t <= 3500)
    {
        printf("%d", (int)t);
        return 0;
    }
    for (double s = 3501; s <= 120000; s++)
    {
        double a = s - 3500;

        double r = 0;
        r += max(min(1500.0, a), 0.0) * 0.03;
        r += max(min(3000.0, a - 1500.0), 0.0) * 0.1;
        r += max(min(4500.0, a - 4500.0), 0.0) * 0.2;
        r += max(min(35000.0 - 9000.0, a - 9000.0), 0.0) * 0.25;
        r += max(min(55000.0 - 35000.0, a - 35000.0), 0.0) * 0.3;
        r += max(min(80000.0 - 55000.0, a - 55000.0), 0.0) * 0.35;
        r += max((a - 80000.0), 0.0) * 0.45;
        if (s - r == t)
        {
            printf("%d", (int)s);
            return 0;
        }
    }
    return 0;
}
