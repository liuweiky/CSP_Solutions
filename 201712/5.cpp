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

int main(void)
{
    int T;
    cin>>T;

    vector<int> answer;

    for(int z=0; z<T; z++)
    {
        int n;
        cin>>n;

        Vertex* Head[n+1];

        for(int i=0; i<n+1; i++)
        {
            Head[i]=new Vertex(i);
        }

        for(int i=1; i<=n; i++)
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

            /**动态规划算法，虽然是0分，但部分示例仍然正确，本人暂时无解*/

            for(vector< vector<Edge*> >::iterator it=subPath.begin(); it!=subPath.end(); it++)
            {


                vector<Edge*>::iterator s,p,e;
                s=(*it).begin();
                //cout<<(*s)->From<<" "<<Head[(*s)->From]->VerName<<endl;
                e=(*it).end();

                Vertex* vt=Head[(*s)->From];
                //cout<<(*s)->From;

                p=s;    //p保存前一次得到最大获利的迭代器，通过p可以获得前一起点

                int lastBestBenefit=vt->v-(vt->f-(*s)->cost)*(vt->f-(*s)->cost);;  //局部最大利益，初始化为起始边
                //cout<<lastBestBenefit<<endl;

                int lastCost=(*s)->cost;

                int benefit=0;  //一条路径搜索之后所得最大利益

                for(int i=1; i<e-s; i++)
                {
                    Vertex* vt=Head[(*(s+i))->From];
                    int x=vt->v-(vt->f-(*(s+i))->cost)*(vt->f-(*(s+i))->cost);  //只有新的边获得的最大利益
                    //cout<<"x: "<<x<<endl;
                    int newCost=lastCost+(*(s+i))->cost;    //在原来的基础之上延伸
                    //cout<<"newCost"<<newCost<<endl;
                    vt=Head[(*p)->From];    //在原来的基础之上延伸
                    int y=vt->v-(vt->f-newCost)*(vt->f-newCost);    //在原来的基础之上延伸
                    //cout<<"y: "<<y<<endl;
                    if(y>x) //延伸之后更大，下次可能继续延伸，因此p不变。
                    {
                        lastCost=newCost;
                        lastBestBenefit=y;
                    }
                    else    //延伸停止
                    {
                        lastCost=(*(s+i))->cost;
                        benefit+=lastBestBenefit;

                        if(x<0) //延伸停止，但是x,y都小于0，可能是到达尽头处，仍然没有获利，因此不再加入benefit
                            x=0;

                        lastBestBenefit=x;
                        p=s+i;
                    }
                }

                benefit+=lastBestBenefit;

                if(benefit>maxBenefit)
                    maxBenefit=benefit;
            }

            //cout<<">>>>>>>>>>>>"<<maxBenefit<<endl;
            sum+=maxBenefit;
        }

        answer.push_back(sum);
    }

   for(vector<int>::iterator it=answer.begin();it!=answer.end();it++)
   {
       cout<<(*it)%(long long)1e18<<endl;
   }


}
