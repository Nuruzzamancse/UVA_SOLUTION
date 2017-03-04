#include<bits/stdc++.h>

using namespace std;

int main()
{
    int ou, W, H, N;

    while(cin>>W>>H>>N)
    {
        if(W==0&&H==0&&N==0)
            break;
        int area = W*H;

        int board[505][505];

        for(int i=1; i<=H; i++)
            for(int j=1; j<=W; j++)
                board[i][j] = 0;

        int cnt=0;
        for(int i=1; i<=N; i++)
        {
            int X1,Y1,X2,Y2;
            cin>>X1>>Y1>>X2>>Y2;

            if(Y1>Y2)
                swap(Y1,Y2);
            if(X1>X2)
                swap(X1,X2);

            for(int i=Y1; i<=Y2; i++)
                for(int j=X1; j<=X2; j++)
                    if(!board[i][j]){
                        board[i][j] = 1;
                            cnt++;
                    }

            }

            area -=cnt;

            if(area)
            {
                if(area!=1)
                    cout<<"There are "<<area<<" empty spots."<<endl;
                if(area==1)
                    cout<<"There is one empty spot."<<endl;
            }
            else
                cout<<"There is no empty spots."<<endl;
    }
}