#include<bits/stdc++.h>

using namespace std;


vector<int>vt[1000];

bool bfs(int src, int ds)
{
    queue<int>q;

    int  color[1000]= {0};
    color[src]  =1;

    q.push(src);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();


        for(int i=0; i<vt[u].size(); i++)
        {
            int v=vt[u][i];

            if(!color[v])
            {
                if(color[u]==1)
                    color[v]=2;
                else
                    color[v]=1;
                q.push(v);
            }

            if(color[u]==color[v])
                return false;
            // printf("Here\n");
            //printf("Here\n");

        }

    }

    return true;
}

int main()
{
    int n,l;

    while(scanf("%d",&n)&&n!=0)
    {
        int mn=1000;
        int mx=-1;
        scanf("%d",&l);
        for(int i=0; i<l; i++)
        {
            int a, b;
            scanf("%d %d",&a,&b);
            vt[a].push_back(b);
            vt[b].push_back(a);

            int k = max(a,b);

            if(k>mx)
                mx = k;
        }

        //printf("%d\n",l);

        if(bfs(0,mx))
        {
            printf("BICOLORABLE.\n");
        }
        else
            printf("NOT BICOLORABLE.\n");

        for(int i=0; i<=n; i++)
            vt[i].clear();

    }
}