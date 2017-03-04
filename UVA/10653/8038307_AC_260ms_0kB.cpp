#include<bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define uu first
#define vv second
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int cell[1005][1005]; //cell[x][y] যদি -১ হয় তাহলে সেলটা ব্লক
int d[1005][1005],vis[1005][1005]; //d means destination from source.
int row,col;
void bfs(int sx,int sy) //Source node is in [sx][sy] cell.
{
	memset(vis,0,sizeof vis);
	vis[sx][sy]=1;
	queue<pii>q; //A queue containing STL pairs
	q.push(pii(sx,sy));
	while(!q.empty())
	{
		pii top=q.front(); q.pop();
		for(int k=0;k<4;k++)
		{
			int tx=top.uu+fx[k];
			int ty=top.vv+fy[k]; //Neighbor cell [tx][ty]
			if(tx>=0 and tx<row and ty>=0 and ty<col and cell[tx][ty]!=-1 and vis[tx][ty]==0) //Check if the neighbor is valid and not visited before.
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

    while(scanf("%d %d",&row,&col)&&(row!=0&&col!=0))
    {
        memset(d,0,sizeof d);
        for(int i=0;i<row;i++)
        {

            for(int j=0;j<col;j++){
                cell[i][j]=1;

            }

        }


        int Number_of_Row;
        scanf("%d",&Number_of_Row);

        for(int i=0;i<Number_of_Row;i++)
        {

                int RN, NB;

                scanf("%d %d",&RN,&NB);

                while(NB--)
                {
                    int B;

                    scanf("%d",&B);

                    cell[RN][B] = -1;
                }

        }

        int sx,sy;
        scanf("%d %d",&sx,&sy);

       bfs(sx,sy);

        int dx,dy;
        scanf("%d %d",&dx,&dy);



        printf("%d\n",d[dx][dy]);

    }

}