#include<bits/stdc++.h>

using namespace std;

int main()
{

    int input;

    while(cin>>input&&input!=0){

    int arra1[input+3];

    for(int i=0;i<input;i++)
    {
        cin>>arra1[i];
    }

    sort(arra1,arra1+input);

    if(arra1[0]>0)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else if(arra1[input-1]<1322)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        bool flag = true;
        for(int i=0;i<input-1;i++)
        {
            if((arra1[i]+200)>=arra1[i+1])
                continue;
            else
                flag = false;


        }

        if(flag)
            cout<<"POSSIBLE"<<endl;
        else if(!flag)
            cout<<"IMPOSSIBLE"<<endl;
    }
    }

}