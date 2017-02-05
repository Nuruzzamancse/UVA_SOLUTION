#include<bits/stdc++.h>
using namespace std;

#define max 25

vector<int> edges[max];

map<string,int>mp;

map<int,string>mp1;

void printpath(int s2, int s1,int parent[])
{
    if(s2 == s1) return;
    printpath(parent[s2], s1, parent);
    cout << mp1[parent[s2]] << " " << mp1[s2] << endl;
}

void bfs(int src,int ds,int parent[])
{
    queue<int> q;

    bool flag = false;

    q.push(src);

    int visited[105] = {0}, level[105]= {0}, u, v, i;

    visited[src] = 1;

    level[src] = 0;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(i=0; i<edges[u].size(); i++)
        {
            int v = edges[u][i];
            if(!visited[v])
            {
                level[v] = level[u] + 1;
                parent[v] = u;
                visited[v] = 1;
                q.push(v);
            }
        }

    }

    printf("%2d to %2d: %d\n",src,ds,level[ds]);

}

int main()
{
    int n, e, i, j,cs=0;

    int x, y;

    int cnt=0;
    while(scanf("%d",&x)!=EOF)
    {


        cnt++;

        for(int j=0; j<x; j++)
        {
            scanf("%d",&y);
            edges[cnt].push_back(y);
            edges[y].push_back(cnt);

        }


        if(cnt==19)
        {
            printf("Test Set #%d\n",++cs);

            int  parent[105];

            int k;
            scanf("%d",&k);

            int src, dst;

            while(k--)
            {

                scanf("%d %d",&src,&dst);
                bfs(src,dst,parent);
            }
            for(int i=1; i<=20; i++)
                edges[i].clear();

            printf("\n");
            cnt=0;
        }

    }

    return 0;
}