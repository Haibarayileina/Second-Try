#include <iostream>
#include <climits>

using namespace std;

const int maxsize=1e4+2;
typedef struct arc
{
    int vexnode;
    int weight;
    arc*next;
}arc;
arc *vex[maxsize];

int vexnum,arcnum;
int dist[maxsize];/*因为用int所以需要避免与INT_MAX相加，以免爆掉int变成负数*/
int visited[maxsize]={0};

void debug();

int main()
{
    int t;/*编号*/
    cin>>vexnum>>arcnum>>t;
    int i,j;
    for(i=1;i<=vexnum;i++)
        {
            dist[i]=INT_MAX;
            vex[i]=NULL;
        }
    int p,q,temp;
    arc *e=NULL,*f=NULL;
    for(i=1;i<=arcnum;i++)
        {
            cin>>p>>q>>temp;
            f=vex[p];
            bool flag=0;
            while(f)
                {
                    if(f->vexnode==q)
                        {
                            flag=1;
                            if(temp<(f->weight))
                                {
                                    f->weight=temp;
                                }
                            break;
                        }
                    f=f->next;
                }
            if(!flag)
                {
                    e=new arc;
                    e->vexnode=q;
                    e->weight=temp;
                    e->next=vex[p];
                    vex[p]=e;
                }
        }
        visited[t]=1;
        f=vex[t];
        while(f)
            {
                dist[f->vexnode]=f->weight;
                f=f->next;
            }
        dist[t]=0;
        int k,minsize;
        for(i=1;i<vexnum;i++)
            {
                minsize=INT_MAX;
                for(j=1;j<=vexnum;j++)
                    {
                        if(visited[j]==0&&(dist[j]<minsize))
                            {
                                minsize=dist[j];
                                k=j;
                            }
                    }
                visited[k]=1;
                f=vex[k];
                while(f)
                    {
                        int a=f->vexnode;
                        int s=f->weight;
                        if(visited[a]==0)
                            {
                            if(minsize+s<dist[a])
                                {
                                    dist[a]=minsize+s;
                                }
                            }
                        f=f->next;
                    }
            }
            for(i=1;i<=vexnum;i++)
                {
                    cout<<dist[i]<<" ";
                }
            debug();
            return 0;
}
void debug()
{
    int i;
    arc *p=NULL;
    cout<<endl;
    for(i=1;i<=vexnum;i++)
        {
            p=vex[i];
            cout<<i<<"->";
            while(p)
                {
                    cout<<p->vexnode<<" "<<p->weight<<"->";
                    p=p->next;
                }
            cout<<endl;
        }
}
