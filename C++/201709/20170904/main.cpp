#include <stdio.h>
#include <string.h>

using namespace std;

int graph1[1001][1001];
int graph2[1001][1001];
int N, M;
int visit1[1001], visit2[1001], visit[1001];

void dfs(int v, int visited[1001], int graph[1001][1001]);
bool check();
void init(int a, int b, int c);

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        graph1[s][t] = 1;
        graph2[t][s] = 1;
    }

    int count = 0;

    for (int i = 1; i <= N; i++)
    {
        init(1, 1, 1);
        dfs(i, visit1, graph1);
        if (check())
            count ++;
        else
        {
            init(0, 1, 1);
            dfs(i, visit2, graph2);
            if (check())
                count++;
        }
    }

    printf("%d", count);

    return 0;
}

void dfs(int v, int visited[1001], int graph[1001][1001])
{
    visited[v] = 1;
    for (int i = 1; i <= N; i++)
        if (visited[i] == 0 && graph[v][i] == 1)
            dfs(i, visited, graph);
}

bool check()
{
    for (int i = 1; i <= N; i++)
        visit[i] = visit1[i] + visit2[i];
    for (int i = 1; i <= N; i++)
        if (visit[i] == 0)
            return false;
    return true;
}

void init(int a, int b, int c)
{
    if (a == 1)
        memset(visit1, 0, sizeof(visit1));
    if (b == 1)
        memset(visit2, 0, sizeof(visit2));
    if (c == 1)
        memset(visit, 0, sizeof(visit));
}
