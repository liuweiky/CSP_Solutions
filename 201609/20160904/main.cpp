#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

#define MAX_N 10240

using namespace std;

struct edge_to
{
    int d, id;
};

struct edge
{
    int s, t, d;
};

vector<edge_to> graph[MAX_N];
int father[MAX_N];
int N, M;
bool edge_rebuild[MAX_N][MAX_N];
int dis[MAX_N];
bool vis[MAX_N];
int path[MAX_N];
int pathd[MAX_N];
int total_cost = 0;
vector <edge> edges;

int edge_cnt = 0;

int find_father(int a)
{
    int f = a;
    while (father[f] != f)
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

void dijkstra()
{
    fill_n(vis, MAX_N, false);
    fill_n(dis, MAX_N, INT_MAX);
    fill_n(path, MAX_N, -1);
    fill_n(pathd, MAX_N, 0);
    int u = 1;
    dis[u] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        vis[u] = true;
        int sz = graph[u].size();
        for (int j = 0; j < sz; j++)
        {
            edge_to& e = graph[u][j];
            if (!vis[e.id] && dis[e.id] > dis[u] + e.d)
            {
                dis[e.id] = dis[u] + e.d;
                path[e.id] = u;
                pathd[e.id] = e.d;
            }
            else if (!vis[e.id] && dis[e.id] == dis[u] + e.d && pathd[e.id] > e.d)
            {
                path[e.id] = u;
                pathd[e.id] = e.d;
            }
        }

        int min_dis = INT_MAX;
        int v = -1;

        for (int j = 2; j <= N; j++)
        {
            if (!vis[j] && dis[j] < min_dis)
            {
                min_dis = dis[j];
                v = j;
            }
        }

        if (v == -1)
            return;
        u = v;
    }
}

void gen_path(int id)
{
    while (path[id] != -1)
    {
        int n = path[id];
        if (!edge_rebuild[id][n])
        {
            edge_rebuild[id][n] = edge_rebuild[n][id] = true;
            int s = find_father(id);
            int t = find_father(n);
            if (s != t)
                un(s, t);
            total_cost += pathd[id];
            edge_cnt++;
        }
        else
            break;
        id = n;
    }
}

bool cmp (edge& e1, edge& e2)
{
    return e1.d < e2.d;
}

int main()
{
    for (int i = 0; i < MAX_N; i++)
        father[i] = i;

    fill_n(&edge_rebuild[0][0], MAX_N * MAX_N, false);

    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge_to e1, e2;
        e1.id = a; e1.d = c;
        e2.id = b; e2.d = c;
        graph[a].push_back(e2);
        graph[b].push_back(e1);
        edge e;
        e.s = a; e.t = b; e.d = c;
        edges.push_back(e);
    }

    dijkstra();

    for (int i = 2; i <= N; i++)
        gen_path(i);

    sort(edges.begin(), edges.end(), cmp);

    int p = 0;

    while (edge_cnt < N - 1)
    {
        edge& e = edges[p++];
        if (edge_rebuild[e.s][e.t])
            continue;
        int fs = find_father(e.s);
        int ft = find_father(e.t);
        if (fs == ft)
            continue;
        un(fs, ft);
        total_cost += e.d;
        edge_cnt++;
    }

    printf("%d", total_cost);

    return 0;
}
