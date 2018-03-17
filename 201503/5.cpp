#include <iostream>
#include <vector>

using namespace std;

class ft
{
public:
    ft(int a, int b){f = a; t = b;}
    int f;
    int t;
};

class Edge
{
public:
    Edge(int v, int c){VerAdj = v; cost = c; next = NULL;}
    int VerAdj;
    Edge* next;
    int cost;
};

class Vertex
{
public:
    Vertex(int v){VerName = v; adj = NULL;}
    int VerName;
    Edge* adj;
    int price;
};

int minCost;
int stop;

void reset(int* visited, int n)
{
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
        minCost = 0;
        stop = 0;
    }
}

void DFS(Vertex** Head, int* visited, int n, int f, int t, int pprice, int pcost)
{

    //cout <<f<<"\t pprice"<<pprice<<"\t"<<pcost<<endl;
    visited[f] = 1;

    if (stop)
    {
        return;
    }

    if (f == t)
    {
        minCost = pcost;
        stop = 1;
        return;
    }

    Edge* e = Head[f]->adj;
    while (e != NULL)
    {
        if(!visited[e->VerAdj])
        {
            int tmpPrice;

            if (Head[f]->price < pprice)
                tmpPrice = Head[f]->price;
            else tmpPrice = pprice;
            int tmpCost = pcost + e->cost * tmpPrice;

            DFS(Head, visited, n,e->VerAdj, t, tmpPrice, tmpCost);
        }

        e = e->next;
    }
}

int main(void)
{
    int n, m;
    cin >> n >>m;

    Vertex* Head[n + 1];

    for (int i = 1; i <= n; i++)
    {
        Head[i] = new Vertex(i);

        int p;
        cin >> p;

        Head[i]->price = p;
    }

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, e;
        cin >> u >> v >>e;

        Edge* edg;
        Vertex* ve;

        edg = new Edge(v, e);
        ve = Head[u];
        edg->next = ve->adj;
        ve->adj = edg;

        edg = new Edge(u, e);
        ve = Head[v];
        edg->next = ve->adj;
        ve->adj = edg;
    }

    int visited[n + 1];

    vector<ft> ftvec;
    vector<int> ans;

    for (int i = 0; i < m; i++)
    {
        int f, t;
        cin >> f >> t;

        ftvec.push_back(ft(f, t));

        /*reset(visited, n);

        DFS(Head, visited, n, f, t, INT_MAX, 0);*/

    }

    for (int i = 0; i < ftvec.size(); i++)
    {
        reset(visited, n);
        DFS(Head, visited, n, ftvec[i].f, ftvec[i].t, INT_MAX, 0);
        ans.push_back(minCost);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
}
