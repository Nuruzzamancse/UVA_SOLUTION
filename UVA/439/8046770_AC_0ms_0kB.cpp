#include<bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define uu first
#define vv second
int fx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int fy[8] = {-1, 1, 1, -1, 2, -2, 2, -2};

int d[10][10],vis[10][100]; //d means destination from source.
int row=8,col=8;
void bfs(int sx,int sy) //Source node is in [sx][sy] cell.
{
	memset(vis,0,sizeof vis);
	vis[sx][sy]=1;
	queue<pii>q; //A queue containing STL pairs
	q.push(pii(sx,sy));
	while(!q.empty())
	{
		pii top=q.front(); q.pop();
		for(int k=0;k<8;k++)
		{
			int tx=top.uu+fx[k];
			int ty=top.vv+fy[k]; //Neighbor cell [tx][ty]
			if(tx>=0 and tx<row and ty>=0  and ty<col and vis[tx][ty]==0) //Check if the neighbor is valid and not visited before.
			{
				vis[tx][ty]=1;
				d[tx][ty]=d[top.uu][top.vv]+1;
				q.push(pii(tx,ty)); //Pushing a new pair in the queue
				//printf("%d\n",d[tx][ty]);
			}
		}
	}


}

int main()
{

    //int a, b;

    char a[5], b[5];
    int cs=1;

    //freopen("F.txt","w",stdout);
    while(scanf("%s",a)!=EOF)
    {
        memset(d,0,sizeof d);
        memset(vis,0,sizeof vis);



        int sx,sy;
         int dx,dy;

        sx = a[0]-96;
        sy = a[1]-48;

       bfs(sx-1,sy-1);

       cin>>b;

      dx = b[0]-96;
      dy = b[1]-48;


     printf("To get from %s to %s takes %d knight moves.\n",a,b,d[dx-1][dy-1]);

    }

}
