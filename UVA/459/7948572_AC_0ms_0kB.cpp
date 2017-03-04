#include<bits/stdc++.h>

using namespace std;

class UnionFind
{

    vector<int>p, Rank, rootSize;
    int numberofDisjointSet;

public:
    UnionFind(int N)
    {
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
                p[y] = x;
            else
            {
                p[x] = y;

                if(Rank[x]==Rank[y])
                    Rank[y]++;
            }

            numberofDisjointSet--;
        }
    }

    int NumberOfDifferentGraph()
    {
        return numberofDisjointSet;
    }

};

int main()
{
    int test;

    cin>>test;
    cin.ignore();

    map<char,int>mp;

    for(char ch='A', k=1;ch<='Z';ch++,k++)
        mp[ch]=k;

    while(test--)
    {
        char ch;
        cin>>ch;
        cin.ignore();

        int n=mp[ch];

        UnionFind uf(n+1);

        string str;

        while(getline(cin,str))
        {
            if(!str.size())
                break;

            int a = mp[str[0]];
            int b = mp[str[1]];

            uf.UnionSet(a,b);
        }

        cout<<uf.NumberOfDifferentGraph()<<endl;

        if(test)
            cout<<endl;
    }

    return 0;
}