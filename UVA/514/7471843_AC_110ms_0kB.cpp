#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test,cs=1;

    while(cin>>test&&test!=0)
    {


        int k;



        while(true)
        {

            int input;
            stack<int>stck,Rail;
            vector<int>vt;

            cin>>input;
            if(input==0)
            {
                cout<<endl;
                break;
            }

            for(int i=0; i<test; i++)
            {
                if(i>0)
                    cin>>input;
                vt.push_back(input);


            }

            bool flag=false;
            for(int i=test-1; i>=0; i--)
            {
                if(vt[i]==test)
                {
                    Rail.push(vt[i]);
                    flag = true;
                    continue;
                }
                if(flag)
                {
                    if((vt[i]+1)==Rail.top())
                    {
                        Rail.push(vt[i]);
                    }
                    else if((!stck.empty())&&((stck.top()+1)==Rail.top()))
                    {

                        while(!stck.empty()&&((stck.top()+1)==Rail.top()))
                        {
                            Rail.push(stck.top());
                            stck.pop();
                        }
                        stck.push(vt[i]);

                    }
                    else
                        stck.push(vt[i]);
                }
                else
                    stck.push(vt[i]);



            }

            while(!stck.empty())
            {
                if((stck.top()+1)==Rail.top())
                {
                    Rail.push(stck.top());
                    stck.pop();
                }
                else
                    break;
            }

            if(stck.empty())
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;


        }
    }
}