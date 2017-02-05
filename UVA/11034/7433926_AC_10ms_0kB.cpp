#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    cin>>test;

    while(test--)
    {
        int lengthFrerry, row;

        cin>>lengthFrerry>>row;

        lengthFrerry*=100;

        queue<int>qleft,qright;

        while(row--)
        {
            string position;
            int length;

            cin>>length>>position;
            if(position=="left")
                qleft.push(length);
            if(position=="right")
                qright.push(length);


        }

        int cnt=1;
        bool left=true,right=false;
        while(!qleft.empty()||!qright.empty())
        {



            int sum=0;
            int len=qleft.size();
            for(int i=0; i<len; i++)
            {
                int temp = qleft.front();

                if((sum+temp)<=lengthFrerry)
                {
                    sum+=temp;
                    qleft.pop();

                }
                else
                    break;
            }
            //cout<<"Left: "<<qleft.size()<<endl;

            if(!qright.empty()||!qleft.empty())
                cnt++;


            sum=0;
            len = qright.size();
            for(int i=0; i<len; i++)
            {
                int temp = qright.front();

                 if((sum+temp)<=lengthFrerry)
                {
                    sum+=temp;
                    qright.pop();

                }
                else
                    break;
            }

            //cout<<"Right :"<<qright.size()<<endl;

            if(!qleft.empty()||!qright.empty())
                cnt++;

        }

        cout<<cnt<<endl;
    }
}