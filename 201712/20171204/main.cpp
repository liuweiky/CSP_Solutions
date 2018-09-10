#include <cstdio>
#include <algorithm>
#include <climits>
#include <cmath>

#define MAX_N 512
#define WIDE 0
#define NARROW 1

using namespace std;

// 0: cost, 1: width
int graph[MAX_N][MAX_N][2];
int N, M;

int visit[MAX_N];
int dis[MAX_N];
int prev_width[MAX_N];
int prev_cost[MAX_N];   // v 点前的narrow长度之平方

void dijkstra()
{
    int v = 1;
    dis[v] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        visit[v] = 1;

        for (int j = 2; j <= N; j++)
        {
            if (visit[j] == 0 && graph[v][j][0] > 0)
            {
                if (graph[v][j][1] == WIDE)
                {
                    if (dis[j] > dis[v] + graph[v][j][0])
                    {
                        dis[j] = dis[v] + graph[v][j][0];
                        prev_width[j] = WIDE;
                        prev_cost[j] = 0;
                    }
                }
                else
                {
                    if (prev_width[v] == NARROW)
                    {
                        int tmpd = dis[v] - prev_cost[v];
                        int t = (sqrt(prev_cost[v]) + graph[v][j][0]) * (sqrt(prev_cost[v]) + graph[v][j][0]);
                        tmpd += t;
                        if (dis[j] > tmpd)
                        {
                            dis[j] = tmpd;
                            prev_width[j] = NARROW;
                            prev_cost[j] = t;
                        }
                    }
                    else
                    {
                        if (dis[j] > dis[v] + graph[v][j][0] * graph[v][j][0])
                        {
                            dis[j] = dis[v] + graph[v][j][0] * graph[v][j][0];
                            prev_width[j] = NARROW;
                            prev_cost[j] = graph[v][j][0] * graph[v][j][0];
                        }
                    }
                }
            }
        }

        int min_dis = INT_MAX;
        for (int j = 2; j <= N; j++)
        {
            if (min_dis > dis[j] && visit[j] == 0)
            {
                min_dis = dis[j];
                v = j;
            }
        }
    }
}

int main()
{
    fill_n(&graph[0][0][0], MAX_N * MAX_N * 2, 0);
    fill_n(visit, MAX_N, 0);
    fill_n(dis, MAX_N, INT_MAX);
    fill_n(prev_width, MAX_N, WIDE);
    fill_n(prev_cost, MAX_N, 0);
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= M; i++)
    {
        int k, s, t, c;
        scanf("%d %d %d %d", &k, &s, &t, &c);
        graph[s][t][0] = graph[t][s][0] = c;
        graph[s][t][1] = graph[t][s][1] = k;
    }

    dijkstra();

    printf("%d", dis[N]);
    return 0;
}
