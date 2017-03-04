#include<bits/stdc++.h>

using namespace std;

class UnionFind
{

    vector<int>p, Rank, rootSize;
    int numberofDisjointSet;

    set<int>DiffParent;

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

            if(Rank[x]>Rank[y]){
                p[y] = x;
                DiffParent.insert(p[y]);
            }
            else
            {
                p[x] = y;
                DiffParent.insert(p[x]);
                if(Rank[x]==Rank[y])
                    Rank[y]++;
            }

            numberofDisjointSet--;
        }
    }

    int SetNum()
    {
        return numberofDisjointSet;
    }

};

int main()
{
    int t, n, m, a, b, temp;
    char cn, ch, k;
    string str;

    map<char, int> mp;

    for(ch = 'A', k = 1; ch <= 'Z'; ch++, k++)
        mp[ch] = k;

    cin >> t;
    //cout << "t =  " << t << endl;

    getchar();

    while(t--)
    {
        cin >> cn;
        //cout << "cn = " << cn << endl;
        n = mp[cn];
        UnionFind uf(n+1);
        getchar();
        while(getline(cin, str))
        {
            //cout << "str = " << str << endl;

            if(!str.size()) break;

            a = mp[str[0]];
            b = mp[str[1]];

            uf.UnionSet(a, b);
        }

        int mx = 0;

        /*for(int i=1; i<=n; i++)
            mx =max(mx, uf.Sizeof_set(i));*/

        mx = uf.SetNum();

        cout << mx << endl;
        if(t) cout << endl;
    }
    return 0;
}