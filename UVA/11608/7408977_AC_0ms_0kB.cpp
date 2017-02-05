#include<bits/stdc++.h>

using namespace std;

int main()
{

    int input,cs=1;

    int arra1[15],arra2[15];

    while(cin>>input&&!(input<0))
    {
        cout<<"Case "<<cs++<<":"<<endl;
        int reamaing = input;

        for(int i=0; i<12; i++)
            cin>>arra1[i];
        for(int i=0; i<12; i++)
            cin>>arra2[i];

        if(reamaing>=arra2[0])
        {
            reamaing -=arra2[0];
            cout<<"No problem! :D"<<endl;
        }
        else
        {
            cout<<"No problem. :("<<endl;
        }

        for(int i=0; i<11; i++)
        {
            reamaing +=arra1[i];

            //cout<<"Remaing:"<<reamaing<<endl;

            if(reamaing>=arra2[i+1])
            {
                reamaing -=arra2[i+1];
                cout<<"No problem! :D"<<endl;
            }
            else
            {
              cout<<"No problem. :("<<endl;
            }
        }
    }

}