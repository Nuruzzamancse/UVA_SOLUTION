#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    cin>>test;

    while(test--)
    {
        int priority, position;

        deque<pair<int,int>>dQ;
        priority_queue<int>pQ;

        cin>>priority>>position;

        for(int i=0; i<priority; i++)
        {
            int prty;

            cin>>prty;

            dQ.push_back(make_pair(prty,i));
            pQ.push(prty);
        }

        int cnt=0;

        while(!dQ.empty())
        {
            if(dQ.front().first<pQ.top())
            {
                dQ.push_back(make_pair(dQ.front().first,dQ.front().second));

            }
            else
            {
                pQ.pop();

                cnt++;
                if(dQ.front().second==position)
                    break;
            }

            dQ.pop_front();
        }
        cout<<cnt<<endl;
    }

}