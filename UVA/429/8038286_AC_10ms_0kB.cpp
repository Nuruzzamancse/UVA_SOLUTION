#include<bits/stdc++.h>

using namespace std;

map<string,int>mp;
map<int,string>mp1;

vector<int>edges[1000];

bool diff(string a, string b)
{
    int len1 = a.size();
    int len2 = b.size();

    int cnt=0;

    if(len1==len2)
    {
        for(int i=0;a[i];i++)
            {
                if(a[i]!=b[i])
                    cnt++;
                if(cnt>1)
                    return false;
            }
    }
    else
        return false;

    return true;
}
int bfs(int src, int ds)
{
    queue<int>q;
    bool flag = false;

    q.push(src);

    int visited[100005] = {0}, level[10005]={0}, u,v,i;

    visited[src] = 1;
    level[src] = 0;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        if(u==ds)
            return level[u];

        for(i=0;i<edges[u].size();i++)
        {
            int v = edges[u][i];
            //cout<<v<<endl;

            if(!visited[v])
            {
                visited[v] = 1;
                level[v] = level[u] +1;
                q.push(v);

            }
        }

    }

}

int main()
{

    int n;
    cin>>n;

    cin.ignore();

    while(n--)
    {
        string word;

        int i=1;
        while(cin>>word)
        {
            if(word=="*")
                break;
            mp[word] = i++;
            mp1[i-1] = word;
            //cout<<mp1[i-1]<<endl;
            //cout<<mp[word]<<endl;
        }

        //cout<<"Yes"<<endl;

        for(int j=1;j<i-1;j++)
        {
            for(int k=j+1;k<i;k++)
            {
                if(diff(mp1[k],mp1[j]))
                {

                    edges[mp[mp1[j]]].push_back(mp[mp1[k]]);
                    edges[mp[mp1[k]]].push_back(mp[mp1[j]]);
                }
            }
        }

        string input;

        cin.ignore();

        while(getline(cin,input))
        {
            string starting="",ending="";
            int l;

            if(input.size()==0)
                break;


            for( l=0;input[l]!=' ';l++)
                starting +=input[l];
            l++;
            for(;l<input.size();l++)
                ending +=input[l];


            //cout<<starting<<" "<<ending<<endl;
            //cout<<mp[starting]<<" "<<mp[ending]<<endl;

            cout<<input<<" "<<bfs(mp[starting],mp[ending])<<endl;


        }

        if(n!=0)
            cout<<endl;
        mp.clear();
        mp1.clear();

        for(int i=0;i<1000;i++)
            edges[i].clear();
    }


    return 0;

}