#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
int p[100004];

int main()
{

    int V,E,W,s,u,v,w,cs=1,t;

    vector<vii>AdjList;

    int test;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d %d %d %d",&V,&E,&s,&t);

        AdjList.assign(V+3,vii());

        while(E--)
        {
            scanf("%d %d %d",&u,&v,&w);


            AdjList[u].push_back(ii(v,w));
            AdjList[v].push_back(ii(u,w));
        }

        vi dist(V+5,INF);
        dist[s] = 0;

        priority_queue< ii, vector<ii>, greater<ii> > pq;

        pq.push(ii(0, s));

        while(!pq.empty())
        {

            ii front = pq.top();
            pq.pop();

            int d = front.first, u = front.second;
            if (d > dist[u]) continue;

            for (int j = 0; j < (int)AdjList[u].size(); j++)
            {
                ii v = AdjList[u][j];

                if (dist[u] + v.second < dist[v.first])
                {
                    dist[v.first] = dist[u] + v.second;

                    pq.push(ii(dist[v.first], v.first));
                }
            }

        }

        if(dist[t]==INF)
            printf("Case #%d: unreachable\n",cs++);
        else
            printf("Case #%d: %d\n",cs++,dist[t]);

    }

}