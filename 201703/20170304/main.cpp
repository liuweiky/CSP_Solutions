#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX_N 102400

using namespace std;

struct edge
{
    int s, t, d;
};

int N, M;
int father[MAX_N];
vector<edge> edges;

int find_father(int a)
{
    int f = a;
    while (f != father[f])
        f = father[f];

    while (father[a] != f)
    {
        int x = father[a];
        father[a] = f;
        a = x;
    }
    return f;
}

void un(int i, int j)
{
    father[i] = j;
}

bool cmp(edge& e1, edge& e2)
{
    return e1.d < e2.d;
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
        father[i] = i;

    for (int i = 0; i < M; i++)
    {
        edge e;
        scanf("%d %d %d", &e.s, &e.t, &e.d);
        edges.push_back(e);
    }

    sort(edges.begin(), edges.end(), cmp);

    int ptr = 0, ans;

    while (find_father(1) != find_father(N))
    {
        edge& e = edges[ptr++];
        int fs = find_father(e.s);
        int ft = find_father(e.t);
        if (fs != ft)
        {
            un(fs, ft);
            ans = e.d;
        }
    }

    printf("%d", ans);

    return 0;
}
