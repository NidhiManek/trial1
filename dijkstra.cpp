#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define V 5

void dijkstra(int graph[V][V] , int s);
void path(int * p, int v);

int main()
{
    int i,j;
    int graph[V][V];
    cout<<"Enter adjacency matrix row wise: \n";
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            cin>>graph[i][j];
        }
    }
    int source;
    cout<<"Enter source vertex: ";
    cin>>source;
    dijkstra(graph,source);
}

void path(int* p, int v)
{
    if(p[v]==-1)
    {
        cout<<v<<" ";
        return;
    }
    path(p,p[v]);
    cout<<v<<" ";
}

void dijkstra(int graph[V][V] , int s)
{
    int d[V];
    int p[V];
    bool spt[V];
    int i;
    for(i=0;i<V;i++)
    {
        d[i]=INT_MAX;
        p[i]=-1;
        spt[i]=false;
    }
    d[s]=0;
    int Min;
    int Min_index;
    int u;
    for(int j=0;j<V-1;j++)
    {
        Min=INT_MAX;

        for(i=0;i<V;i++)
        {
            if(d[i]<=Min && spt[i]==false)
            {
                Min=d[i];
                Min_index=i;
            }
        }
        u=Min_index;
        spt[u]=true;
        for(i=0;i<V;i++)
        {
            if (spt[i]==false && graph[u][i]!=0 && d[u] + graph[u][i] < d[i])
            {
                p[i] = u;
                d[i] = d[u] + graph[u][i];
            }
        }
    }
    cout<<"\nVertex-->>distance from source-->>path from source: \n\n";
    for(i=0;i<V;i++)
    {
        cout<<" "<<i<<" -->> "<<d[i]<<" -->> ";
        path(p,i);
        cout<<"\n";
    }
}
