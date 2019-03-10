#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 60000

using namespace std;

struct edge
{
    int s, t, w;
};

int father[MAX_N];
int n, m, root;
vector<edge> edges;

int find_father(int a)
{
    int f = a;
    while (f != father[f])
        f = father[f];
    while (father[a] != f)
    {
        int x = a;
        father[a] = f;
        a = father[x];
    }
    return f;
}

void un(int i, int j)
{
    father[i] = j;
}

bool cmp(edge& e1, edge& e2)
{
    return e1.w < e2.w;
}

int main()
{
    for (int i = 0; i < MAX_N; i++)
        father[i] = i;
    scanf("%d %d %d", &n, &m, &root);
    for (int i = 0; i < m; i++)
    {
        edge e;
        scanf("%d %d %d", &e.s, &e.t, &e.w);
        edges.push_back(e);
    }

    sort(edges.begin(), edges.end(), cmp);

    int cnt = 0, eptr = 0, max_w = 0;

    while (cnt != n - 1)
    {
        int s = edges[eptr].s;
        int t = edges[eptr].t;
        int fs = find_father(s);
        int ft = find_father(t);
        if (fs != ft)
        {
            un(fs, ft);
            max_w = edges[eptr].w;
            cnt++;
        }
        eptr++;
    }

    printf("%d", max_w);

    return 0;
}
