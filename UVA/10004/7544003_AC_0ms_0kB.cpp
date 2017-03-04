#include<bits/stdc++.h>
using namespace std;

#define max 100000

vector<int> edges[max];

bool bfs(int n, int src)
{
    queue<int> q;

    q.push(src);

    int color[205] = {0},u, v, i;

    color[src] = 1;

    bool flag;

    while(!q.empty())
    {
        flag = true;
        u = q.front();
        for(i=0; i<edges[u].size(); i++)
        {
            int v = edges[u][i];

            if(color[u]==color[v])
            {
                flag = false;
                break;
            }

            if(!color[v])
            {
                if(color[u]==1)
                    color[v] = 2;
                else
                    color[v] = 1;
                q.push(v);
            }

        }
        q.pop();
    }
    return flag;

}

int main()
{
    int ou;
    int n, e, i, j;

    while(cin >> n)
    {

        if(n==0)
            break;
        cin>>e;
        for(i=1; i<=e; i++)
        {
            int x, y;

            cin >> x >> y;

            edges[x].push_back(y);
            edges[y].push_back(x);
        }


        if(bfs(n, 0))
            cout<<"BICOLORABLE."<<endl;
        else
            cout<<"NOT BICOLORABLE."<<endl;

        for(i=0; i<=e; i++)
        {

            edges[i].clear();
        }
    }


    return 0;
}
