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

    int numberOfComponent(int N)
    {
        int mx = -1;
        for(int i=0;i<N;i++)
        if(mx<rootSize[findSet(i)])
          mx = rootSize[findSet(i)];
        return mx;
    }

};

int main()
{
    int C,R;

    //freopen ("myfile.txt","w",stdout);

    while(cin>>C>>R)
    {
        if(C==0&&R==0)
            break;
        cin.ignore();
        map<string,int>mp;
        string str;

        UnionFind uf(C+1);

        int N=C+1;

        int k=1;
        while(C--)
        {
            cin>>str;

            mp[str]=k++;

        }



        while(R--)
        {
            string a, b;

            cin>>a>>b;

            //cout<<a<<' '<<b<<endl;
            //cout<<mp[a]<<' '<<mp[b]<<endl;

            int i = mp[a];
            int j = mp[b];

            uf.UnionSet(i,j);


        }

        //cout<<uf.NumberOfDifferentGraph()<<endl;

        //cout<<uf.numberOfComponent(N)<<endl;
        //stdout<<uf.numberOfComponent(N)<<endl;


        printf ("%d\n",uf.numberOfComponent(N));


        cin.ignore();


    }
    //fclose (stdout);

    return 0;
}