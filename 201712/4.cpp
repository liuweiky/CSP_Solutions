#include <iostream>
#include <vector>
#include <limits>
#include <math.h>

using namespace std;

class Edge
{
public:
    Edge(int t,int v,int c){isTinyPath=t;VerAdj=v;cost=c;link=NULL;}
    int cost;
    int VerAdj;
    int isTinyPath;
    Edge* link;
};

class Vertex
{
public:
    Vertex(int v){VerName=v;adjacent=NULL;}
    int VerName;
    Edge* adjacent;
};

int getCost(vector<Edge*> v)
{
    int c=0;
    for(vector<Edge*>::iterator it=v.begin();it!=v.end();it++)
    {
        c+=(*it)->cost;
    }
    return c;
}

int Dijkstra(int v,int n,Vertex** Head)
{
    bool visited[n];
    int dis[n];
    bool lastTiny[n];
    int lastCost[n];
    int path[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        dis[i]=INT_MAX;
        lastTiny[i]=false;
        lastCost[i]=0;
        path[i]=-1;
    }
    dis[v]=0;
    visited[v]=true;
    lastCost[v]=0;

    int u=v;

    for(int i=0;i<n-1;i++)
    {
        Edge* p=Head[u]->adjacent;
        while(p!=NULL)
        {
            int verAdj=p->VerAdj;
            int newDis;

            if(p->isTinyPath)
            {
                newDis=(sqrt(lastCost[u])+p->cost)*(sqrt(lastCost[u])+p->cost)+dis[u]-lastCost[u];  //新的贪心算法，先减去前一次平方，再加上新的平方
                lastTiny[verAdj]=true;
                lastCost[verAdj]=newDis-dis[u];
                if(dis[verAdj]>newDis)
                {

                    dis[verAdj]=newDis;
                    path[verAdj]=u;
                }
            }else
            {
                newDis=dis[u]+p->cost;
                lastTiny[verAdj]=false;
                lastCost[verAdj]=0;
                if(dis[verAdj]>newDis)
                {
                    dis[verAdj]=newDis;
                    path[verAdj]=u;
                }
            }

            p=p->link;
        }

        int minDis=INT_MAX;
        for(int j=0;j<n;j++)
        {
            if(!visited[j]&&dis[j]<minDis)
            {
                u=j;
                minDis=dis[j];
            }
        }

        visited[u]=true;
    }

    cout<<dis[n-1];
}

int main(void)
{
    int n,m;
    cin>>n>>m;

    Vertex* Head[n];

    for(int i=0;i<n;i++)
    {
        Head[i]=new Vertex(i);
    }

    for(int i=0;i<m;i++)
    {
        int t,a,b,c;
        cin>>t>>a>>b>>c;

        Edge* e=new Edge(t,b-1,c);

        e->link=Head[a-1]->adjacent;
        Head[a-1]->adjacent=e;

        e=new Edge(t,a-1,c);  //双向
        e->link=Head[b-1]->adjacent;
        Head[b-1]->adjacent=e;
    }

    Dijkstra(0,n,Head);

    return 0;

}
