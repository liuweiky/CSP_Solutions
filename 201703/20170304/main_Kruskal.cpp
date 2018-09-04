#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge
{
    int from, to, cost;
    Edge(int f, int t, int c): from(f), to(t), cost(c) {}
};

int father[100002];
int N, M;

vector<Edge*> edges;

int GetFather(int a)
{
    int b = a;
    while (true)
        if (father[a] == a)
            break;
        else
            a = father[a];

    while (true)
        if (father[b] == a)
            break;
        else {
            int c = b;
            b = father[b];
            father[c] = a;
        }
    return a;
}

bool cmp(Edge* e1, Edge* e2)
{
    return e1->cost < e2->cost;
}

void UnionSet(int a, int b)
{
    if (GetFather(a) != GetFather(b))
        father[GetFather(a)] = GetFather(b);
}


int main()
{

    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        int s, t, c;
        scanf("%d %d %d", &s, &t, &c);
        edges.push_back(new Edge(s, t, c));
    }

    for (int i = 0; i <= N; i++)
        father[i] = i;

    sort(edges.begin(), edges.end(), cmp);

    int index = 0;
    for (; index < M; index++)
    {
        Edge* e = edges[index];
        if (father[e->from] == father[e->to])
            continue;
        else
            UnionSet(e->from, e->to);
        if (GetFather(1) == GetFather(N))
            break;
    }

    printf("%d", index == M ? edges[M-1]->cost : edges[index]->cost);

    return 0;
}
