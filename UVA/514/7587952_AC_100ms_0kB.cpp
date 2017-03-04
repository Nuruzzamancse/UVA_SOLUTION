#include<bits/stdc++.h>
using namespace std;
 stack<int>s, st;
int main()
{

    int n, in, count;

    while(cin>>n && n!=0){

        while(1){
        count = 0;
            cin>>in;
            s.push(in);

            if(in == 0)
                break;

            for(int i=1; i<n; i++){
                cin>>in;
                s.push(in);

            }

            for(int i=n; i>=1; i--){

                    int f = 1;

            if(!(st.empty())){
                if(i==st.top()){
                    f = 0;
                    st.pop();
                    count++;

                }
            }
            if(f == 1)
                while(!(s.empty())){
                if(i==s.top()){
                s.pop();
                    count++;
                    break;
                }

                else{
                    st.push(s.top());
                    s.pop();
                }
              }
            }

            if(count == n)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

        s = stack<int>();
        st = stack<int>();
        }
       cout<<endl;
    }


    return 0;
}