#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m, n, cs=1;

    while(scanf("%d%d",&m,&n))
    {
        if(m==0&&n==0)
            break;
        char str[105][105],arra[105][105];

        getchar();


        for(int i=0;i<=m+1;i++)
            str[i][0] = '.';
        for(int i=0;i<=m+1;i++)
            str[i][n+1] = '.';
        for(int i=0;i<=n+1;i++)
            str[0][i] = '.';
        for(int i=0;i<=n+1;i++)
            str[m+1][i] = '.';

        for(int i=0;i<m;i++)
            gets(arra[i]);

        for(int i=0,k=1;i<m;i++,k++)
            for(int j=0,l=1;j<n;j++,l++)
        {
            str[k][l]=arra[i][j];
        }
        int count;
           for (int i=1;i<=m;i++)
          {
              for( int j=1;j<=n;j++)
              {
                   count=0;
                   if( str[i][j]!='*')
                   {
                       if(str[i-1][j-1]=='*') count++;
                       if(str[i][j-1]=='*') count++;
                       if(str[i+1][j-1]=='*') count++;
                       if(str[i+1][j]=='*') count++;
                       if(str[i+1][j+1]=='*') count++;
                       if(str[i][j+1]=='*') count++;
                       if(str[i-1][j+1]=='*') count++;
                       if(str[i-1][j]=='*') count++;
                       str[i][j]='0'+count;
                   }
              }
          }



        if(cs!=1)
            printf("\n");
        printf("Field #%d:\n",cs++);

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                printf("%c",str[i][j]);
            }
            printf("\n");
        }
    }
}