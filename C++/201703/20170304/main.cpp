#include <stdio.h>
#include <limits.h>
#include <algorithm>

#define MAX_N 100001

using namespace std;

struct Edge {
    int ver_adj;
    int cost;
    Edge* link;
    Edge(int v, int c): ver_adj(v), cost(c) {}
};

struct Vertex {
    int ver_name;
    Edge* adjacent;
    Vertex(){}
    Vertex(int n): ver_name(n), adjacent(NULL){}
};

Vertex head[MAX_N];
int n ,m;
int visit[MAX_N];
int dis[MAX_N];

void dijkstra(int v);

int main()
{
    scanf("%d %d", &n, &m);
    fill(visit, visit + MAX_N, 0);      // fill: algorithm
    fill(dis, dis + MAX_N, INT_MAX);    // INT_MAX: limits.h
    for (int i = 1; i <= n; i++)
        head[i] = Vertex(i);
    for (int i = 0; i < m; i++)
    {
        int s, t, c;
        scanf("%d %d %d", &s, &t, &c);
        Edge* e = new Edge(t, c);
        e->link = head[s].adjacent;
        head[s].adjacent = e;

        e = new Edge(s, c);
        e->link = head[t].adjacent;
        head[t].adjacent = e;
    }
    dijkstra(1);
    printf("%d", dis[n]);
    return 0;
}

void dijkstra(int v)
{
    dis[v] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        visit[v] = 1;

        Edge* e = head[v].adjacent;

        while (e != NULL)
        {
            int t = e->ver_adj;
            if (visit[t] == 0 && dis[t] > max(dis[v], e->cost))
                dis[t] = max(dis[v], e->cost);
            e = e->link;
        }

        int u = -1, min_cost = INT_MAX;

        for (int j = 1; j <= n; j++)
            if (visit[j] == 0 && dis[j] < min_cost)
            {
                u = j;
                min_cost = dis[j];
            }
        v = u;
    }
}
