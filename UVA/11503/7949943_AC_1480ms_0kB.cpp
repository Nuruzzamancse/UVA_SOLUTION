#include<bits/stdc++.h>

using namespace std;

class UnionFind
{

    vector<int>p, Rank, rootSize;
    int numberofDisjointSet;

public:
    UnionFind(int N)
    {
        //cout<<N<<endl;
        numberofDisjointSet = N-1;
        Rank.assign(N,0);
        p.assign(N,0);
        rootSize.assign(N,1);

        for(int i=0; i<N; i++)
            p[i] = i;
    }
    int findSet(int i)
    {
        return (p[i]==i)? i: p[i] = findSet(p[i]);
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i)==findSet(j);
    }

    void UnionSet(int i,int j)
    {
        if(!isSameSet(i,j))
        {
            int x = findSet(i);
            int y = findSet(j);

            if(Rank[x]>Rank[y])
            {
                p[y] = x;
                rootSize[x]+=rootSize[y];
            }
            else
            {
                p[x] = y;
                rootSize[y]+=rootSize[x];

                if(Rank[x]==Rank[y])
                    Rank[y]++;
            }

            numberofDisjointSet--;

            //cout<<numberofDisjointSet<<endl;
        }
    }

    int NumberOfDifferentGraph()
    {
        return numberofDisjointSet;
    }

    int numberOfComponent(int i)
    {
        return rootSize[findSet(i)];
    }

};

int main()
{
    int t,cn;

    cin >> t;

    while(t--)
    {
        cin >> cn;
        UnionFind uf(2*cn+1);
        getchar();

        map<string,int>mp;
        int k=1;
        while(cn--)
        {


            string  a, b;

            cin>>a>>b;

            if(mp.find(a)==mp.end())
                mp[a]=k++;
            if(mp.find(b)==mp.end())
                mp[b]=k++;

            uf.UnionSet(mp[a], mp[b]);

            int rs = max(uf.numberOfComponent(mp[a]),uf.numberOfComponent(mp[b]));

            cout<<rs<<endl;




        }

    }
}