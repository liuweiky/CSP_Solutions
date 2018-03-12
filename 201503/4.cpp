#include <iostream>

#define SWITCH 1
#define COM 0

using namespace std;

int maxDepth;

class Edge
{
public:
    Edge(int v){VerAdj = v; next = NULL;}
    Edge* next;
    int VerAdj;
};

class Vertex
{
public:
    Vertex(int t, int v){type = t; VerName = v; adj = NULL;}
    Edge* adj;
    int VerName;
    int type;
};

bool allVisited(bool* b, int mn)
{
    for (int i = 0; i < mn; i++)
        if (!b[i]) return false;
    return true;
}

bool reset(bool* b, int mn)
{
    for (int i = 0; i < mn; i++)
        b[i] = false;
}

void DFS(Vertex** Head, int u, int mn, bool* visited, int depth)
{
    //cout<<depth<<"  "<<maxDepth<<"  "<<u<<endl;
    if (depth > maxDepth) maxDepth = depth;
    visited[u] = true;
    Vertex* v = Head[u];
    Edge* e = v->adj;
    while (e != NULL)
    {
        int nextU = e->VerAdj;
        if (!visited[nextU])
        {
            DFS(Head, nextU, mn, visited, depth + 1);
        }
        e = e->next;
    }
}

int main(void)
{
    int n,m;
    cin>>n>>m;

    Vertex* Head[n+m];  //0 ~ n-1: Switches, n ~ m - 1: Coms

    for (int i = 0; i < n; i++) //Generate Switches
    {
        Head[i] = new Vertex(SWITCH, i);
    }

    for (int i = 0; i < m; i++)
    {
        Head[i + n] = new Vertex(COM, i);   //Generate Coms
    }

    for (int i = 1; i < n; i++)
    {
        int num;
        cin>>num;

        Vertex* v = Head[i];
        Edge* e = new Edge(num - 1);
        e->next = v->adj;
        v->adj = e;

        v = Head[num - 1];
        e = new Edge(i);
        e->next = v->adj;
        v->adj = e;
    }

    for (int i = 0; i < m; i++)
    {
        int num;
        cin>>num;

        Vertex* v = Head[i + n];
        Edge* e = new Edge(num - 1);
        e->next = v->adj;
        v->adj = e;

        v = Head[num - 1];
        e = new Edge(i + n);
        e->next = v->adj;
        v->adj = e;
    }

    bool visited[m + n];

    int d = 0;

    for (int i = n; i < m + n; i++)
    {
        maxDepth = 0;
        reset(visited, m + n);
        DFS(Head, 4, m + n, visited, 0);
        if (d < maxDepth) d = maxDepth;
    }

    cout<<d;

    /*for (int i = 0; i < m + n; i++)
    {
        cout<<i<<": ";
        Vertex* v = Head[i];
        Edge* e = v->adj;
        while (e != NULL)
        {
            cout<<e->VerAdj<<"->";
            e = e->next;
        }
        cout<<endl;
    }*/
}
