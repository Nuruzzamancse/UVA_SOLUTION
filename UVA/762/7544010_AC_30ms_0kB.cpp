#include<bits/stdc++.h>
using namespace std;

#define max 100000

vector<int> edges[max];

map<string,int>mp;

map<int,string>mp1;

void printpath(int s2, int s1,int parent[])
{
    if(s2 == s1) return;
    printpath(parent[s2], s1, parent);
    cout << mp1[parent[s2]] << " " << mp1[s2] << endl;
}

bool bfs(int src,int ds,int parent[])
{
    queue<int> q;

    bool flag = false;

    q.push(src);

    int visited[100005] = {0}, level[100005]= {0}, u, v, i;

    visited[src] = 1;

    level[src] = 0;

    while(!q.empty())
    {
        u = q.front();q.pop();
        if(ds==u)
        {
            flag = true;
            break;
        }
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

    return flag;


}

int main()
{
    int ou;

    int n, e, i, j,cs=0;

    while((scanf("%d",&n))!=EOF){


    int cnt=0;
    for(i=0; i<n; i++)
    {

        string x, y;
        cin>>x>>y;




        if(mp.find(x)==mp.end())
        {

            cnt++;
            mp[x]=cnt;
            mp1[mp[x]]=x;

        }
        if(mp.find(y)==mp.end())
        {
            cnt++;
            mp[y]=cnt;
            mp1[mp[y]]=y;

        }

        edges[mp[x]].push_back(mp[y]);
        edges[mp[y]].push_back(mp[x]);
    }

    int  parent[100005];

    string x, y;
    cin>>x>>y;


    if(mp.find(x)==mp.end())
    {
        cnt++;
        mp[x]=cnt;
    }
    if(mp.find(y)==mp.end())
    {
        cnt++;
        mp[y]=cnt;
    }

    if(cs>0)
        cout<<endl;
    cs++;

    if(bfs(mp[x],mp[y],parent)){
      printpath(mp[y],mp[x],parent);
    }
    else
        cout<<"No route"<<endl;



    for(int i=0;i<max;i++)
        edges[i].clear();

    mp.clear();
    mp1.clear();
    }

    return 0;
}