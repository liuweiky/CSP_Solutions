#include <iostream>

using namespace std;

class Edge
{
public:
    Edge(int v){VerAdj = v; link = NULL;}
    int VerAdj;
    Edge* link;
};

class Vertex
{
public:
    Vertex(int v){VerName = v; adjacent = NULL;}
    int VerName;
    Edge* adjacent;
};

void DFS(int v, Vertex** Head, int* visited);
void reset(int N, int* visited);
bool check(int N, int* visited);

int main(void)
{
    int N, M;
    cin>>N>>M;

    Vertex* Head[N];
    Vertex* Head_Reverse[N];

    for (int i = 0; i < N; i++)
    {
        Head[i] = new Vertex(i);
        Head_Reverse[i] = new Vertex(i);
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin>>a>>b;
        a--;
        b--;

        Edge* e, *link;

        e = Head[a]->adjacent;
        link = new Edge(b);
        link->link = e;
        Head[a]->adjacent = link;

        e = Head_Reverse[b]->adjacent;
        link = new Edge(a);
        link->link = e;
        Head_Reverse[b]->adjacent = link;
    }

    int visited[N];

    int count = 0;

    for (int i = 0; i < N; i++)
    {
        reset(N, visited);
        DFS(i, Head, visited);
        bool tag = check(N, visited);

        reset(N, visited);
        DFS(i, Head_Reverse, visited);
        bool tag_reverse = check(N, visited);

        if (tag || tag_reverse) count++;
    }

    cout<<count;
}

void DFS(int v, Vertex** Head, int* visited)
{
    //cout<<v<<endl;

    visited[v] = 1;

    Edge* p = Head[v]->adjacent;

    while (p != NULL)
    {
        if (visited[p->VerAdj] == 0)
        {
            DFS(p->VerAdj, Head, visited);
        }
        p=p->link;
    }
}

void reset(int N, int* visited)
{
    for (int i = 0; i < N; i++)
    {
        visited[i] = 0;
    }
}

bool check(int N, int* visited)
{
    for(int i = 0; i < N; i++)
    {
        if (!visited[i]) return false;
    }

    return true;
}
