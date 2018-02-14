#include <iostream>
#include <vector>


using namespace std;

class Edge
{
public:
    Edge(int f,int v,int c){From=f;VerAdj=v;cost=c;link=NULL;}
    int From;
    int VerAdj;
    int cost;
    Edge* link;
};

class Vertex
{
public:
    Vertex(int vn){VerName=vn;adjacent=NULL;}
    int VerName;
    int v;
    int f;
    Edge* adjacent;

};

void reset(bool* visited,int n)
{
    for(int i=0;i<=n;i++)
    {
        visited[i]=false;
    }
}

void DFS(bool* visited,Vertex** Head,int v,int n,vector<Edge*> path,vector< vector<Edge*> >* paths)
{
    visited[v]=true;
    Edge* p=Head[v]->adjacent;

    if(p==NULL) //没有子结点，说明是树的叶子结点，则保存path
    {
        paths->push_back(path);
        return;
    }

    while(p!=NULL)
    {
        if(!visited[p->VerAdj])
        {
            vector<Edge*> newPath=vector<Edge*>(path);
            newPath.push_back(p);  //加入路径
            DFS(visited,Head,p->VerAdj,n,newPath,paths);
        }
        p=p->link;
    }
}

/*class PathTag
{
public:
    PathTag(int s,int e){startAt=s;endAt=e;}
    int startAt;
    int endAt;
};*/

int main(void)
{
    int T;
    cin>>T;
    int n;
    cin>>n;

    Vertex* Head[n+1];

    for(int i=0;i<n+1;i++)
    {
        Head[i]=new Vertex(i);
    }

    for(int i=1;i<=n;i++)
    {
        int ui,si,vi,fi;
        cin>>ui>>si>>vi>>fi;
        Head[i]->v=vi;
        Head[i]->f=fi;
        Edge* e=new Edge(ui,i,si);
        e->link=Head[ui]->adjacent;
        Head[ui]->adjacent=e;
    }

    vector< vector<Edge*> > paths;

    bool visited[n+1];

    reset(visited,n);

    vector<Edge*> path;

    DFS(visited,Head,1,n,path,&paths);

    cout<<endl;

    vector< vector<Edge*> > subPath;  //处理分叉情况

    /*for(vector< vector<Edge*> >::iterator it=paths.begin(); it!=paths.end(); it++)
    {
        vector<Edge*> e=*it;
        for(vector<Edge*>::iterator i=e.begin(); i!=e.end(); i++)
        {
            cout<<(*i)->From<<" ";
        }
        cout<<(*(e.end()-1))->VerAdj;
        cout<<endl;
    }*/

    int sum=0;



    for(int k=1; k<=n; k++)
    {
        subPath.clear();
        for(vector< vector<Edge*> >::iterator it=paths.begin(); it!=paths.end(); it++)
        {
            vector<Edge*> e=*it;
            for(vector<Edge*>::iterator i=e.begin(); i!=e.end(); i++)
            {
                if((*i)->From==k)
                {
                    subPath.push_back(vector<Edge*>(i,e.end()));
                }
            }
        }

        int maxBenefit=0;

        for(vector< vector<Edge*> >::iterator it=subPath.begin();it!=subPath.end();it++)
        {
            int benefit=0;
            int lastCost=0;
            vector<Edge*>::iterator s,sNext,e;
            s=(*it).begin();
            //cout<<(*s)->From<<" "<<Head[(*s)->From]->VerName<<endl;
            sNext=s;
            e=(*it).end();
            while(s!=e)
            {
                if(s==sNext)
                {
                    Vertex* vt=Head[(*s)->From];
                    int b=vt->v-(vt->f-(*s)->cost)*(vt->f-(*s)->cost);
                    //cout<<"b: "<<b<<endl;
                    cout<<" b: "<<b<<" v: "<<vt->v<<" f: "<<vt->f<<" cost: "<<(*s)->cost<<" lastCost: "<<lastCost<<endl;
                    if(b<0)
                    {
                        sNext++;
                        if(sNext==e)
                            break;
                        lastCost+=(*s)->cost;
                    }else
                    {
                        benefit+=b;
                        s++;
                        sNext=s;
                        lastCost=0;
                    }
                }else
                {
                    Vertex* vt=Head[(*s)->From];
                    //cout<<" vt: "<<vt->VerName<<endl;
                    int b=vt->v-(vt->f-((*sNext)->cost+lastCost))*(vt->f-((*sNext)->cost+lastCost));
                    //cout<<"b: "<<b<<endl;
                    cout<<" b: "<<b<<" v: "<<vt->v<<" f: "<<vt->f<<" cost: "<<(*sNext)->cost<<" lastCost: "<<lastCost<<endl;
                    if(b<0)
                    {
                        lastCost+=(*sNext)->cost;
                        sNext++;
                        if(sNext==e)
                            break;
                    }else
                    {
                        benefit+=b;
                        sNext++;
                        s=sNext;
                        lastCost=0;
                    }
                }
            }

            if(benefit>maxBenefit)
                maxBenefit=benefit;
        }

        cout<<maxBenefit<<endl;
        sum+=maxBenefit;
    }

    cout<<sum;
}
