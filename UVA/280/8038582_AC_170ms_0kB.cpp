#include<bits/stdc++.h>

using namespace std;

vector<int>graph[105];

int visited[105]= {0};
int V;
void dfs(int src)
{

    for(int i=0; i<graph[src].size(); i++)
    {
        if(!visited[graph[src][i]])
        {
            visited[graph[src][i]]=1;
            //path[graph[src][i]]=
            dfs(graph[src][i]);
        }

    }
}

int main()
{
    int n, tc, kk=1, v, u, q;
    string s;
    //freopen ("myfile.txt","w",stdout);
    while(cin>>n && n)
    {

        while(1)
        {
            cin>>u;
            if(!u) break;
            while(cin>>v && v)
                graph[u].push_back(v);
        }
        cin>>q;
        while(q--)
        {
            int src;
            cin>>src;


            memset(visited,0,sizeof(visited));
            dfs(src);
            vector<int>cnt;
            for(int i=1;i<=n;i++)
                if(!visited[i])
                    cnt.push_back(i);
            int cntl=cnt.size();
            cout<<cntl;
            for(int i=0;i<cntl;i++)
                cout<<" "<<cnt[i];
            cout<<"\n";
        }
        for(int i=1;i<=n;i++) graph[i].clear();
    }
return 0;
}