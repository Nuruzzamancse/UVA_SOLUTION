#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


#define INF 10000000
int main()
{
    int V, E, s, u, v, w;

    //freopen("fucking.txt","wt",stdout);


    int VE,dst;

    while(scanf("%d %d",&VE,&dst)==2)
    {

        vector<vii> AdjList;
        AdjList.assign(100000,vii());
        vi cost;
        for(int i=0; i<VE; i++)
        {
            int a;
            scanf("%d",&a);
            cost.push_back(a);

        }
        map<int,int>mp;
        vector<int>vt;

        getchar();

        int i,liftno;

        bool flag=false;



        for(i=0; i<VE; i++)
        {
            int inpt;

            stringstream ss;
            ss.clear();
            string s2;
            getline(cin,s2);


            ss<<s2;

            ss>>inpt;

            liftno = i*100;

            int j=1;

            while(j<=i)
            {
                if(flag&&mp[liftno+inpt-j*100]>=1)
                {
                    int k=liftno+inpt-j*100;

                    if(k==0)
                    {
                        AdjList[liftno+inpt-j*100].push_back(ii(liftno+inpt,0));
                        AdjList[liftno+inpt].push_back(ii(liftno+inpt-j*100,0));
                        //cout<<liftno+inpt-j*100<<' '<<liftno+inpt<<endl;

                    }else{
                    AdjList[liftno+inpt-j*100].push_back(ii(liftno+inpt,60));
                    AdjList[liftno+inpt].push_back(ii(liftno+inpt-j*100,60));
                    }
                    //cout<<liftno+inpt-j*100<<' '<<liftno+inpt<<endl;
                }
                j++;
            }




            vt.push_back(liftno+inpt);

            int u;
            while(ss>>u)
            {

                vt.push_back(liftno+u);

                j=1;

                while(j<=i)
                {

                    if(flag&&mp[liftno+u-j*100]>=1)
                    {
                        int k=liftno+u-j*100;

                        if(k==0)
                        {
                            AdjList[liftno+u-j*100].push_back(ii(liftno+u,0));
                            AdjList[liftno+u].push_back(ii(liftno+u-j*100,0));
                            //cout<<liftno+u-j*100<<' '<<liftno+u<<endl;
                        }
                        else{
                        AdjList[liftno+u-j*100].push_back(ii(liftno+u,60));
                        AdjList[liftno+u].push_back(ii(liftno+u-j*100,60));
                        //cout<<liftno+u-j*100<<' '<<liftno+u<<endl;
                        }




                    }
                    j++;
                }

                AdjList[liftno+inpt].push_back(ii(liftno+u,(u-inpt)*cost[i]));
                AdjList[liftno+u].push_back(ii(liftno+inpt,(u-inpt)*cost[i]));

                //cout<<liftno+inpt<<' '<<liftno+u<<endl;

                inpt = u;

            }
            flag = true;
            int sz = vt.size();

            for(int i=0; i<sz; i++)
                mp[vt[i]]++;
            vt.clear();

        }

        /*cout<<AdjList[100].size()<<endl;
        for(int i=0;i<AdjList[100].size();i++)
        {
            ii k = AdjList[100][i];
            cout<<k.first<<' '<<k.second<<endl;
        }*/

        vi dist(100000,INF);
        dist[0] = 0;
        dist[100]=0;
        dist[200]=0;
        dist[300]=0;
        dist[400]=0;

        priority_queue< ii, vector<ii>, greater<ii> > pq;

        pq.push(ii(0, 0));
        pq.push(ii(0, 100));
        pq.push(ii(0, 200));
        pq.push(ii(0, 300));
        pq.push(ii(0, 400));

        while(!pq.empty())
        {
            bool flag = false;

            ii front = pq.top();
            pq.pop();

            int d = front.first, u = front.second;


            for (int j = 0; j < (int)AdjList[u].size(); j++)
            {
                ii v = AdjList[u][j];
                //cout<<"--------"<<u<<' '<<v.first<<' '<<v.second<<endl;



                if (dist[u] + v.second < dist[v.first])
                {

                    dist[v.first] = dist[u]+v.second;

                    pq.push(ii(dist[v.first], v.first));



                }


            }

        }




        long long int rs = INF;

        //cout<<dist[103]<<endl;
        //cout<<dist[3]<<endl;
        //cout<<dist[203]<<endl;


        for(int i=0; i<5; i++)
            if(rs>dist[i*100+dst])
                rs = dist[i*100+dst];

        if(rs==INF)
            printf("IMPOSSIBLE\n");
        else
            printf("%lld\n",rs);

    }

    return 0;
}