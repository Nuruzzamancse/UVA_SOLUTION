#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    char input[35];

    cin>>test;

    getchar();
    getchar();

    while(test--)
    {
        map<string,int>mp;
        int cnt=0;
        while(gets(input))
        {
            if(input[0]=='\0')
            {
                break;
            }

            mp[input]++;
            //cout<<mp[input]<<endl;
            cnt++;
            //cout<<cnt<<endl;
        }

        map<string,int>::iterator it=mp.begin();

        while(it!=mp.end())
        {
            int nmb = mp[it->first];
            double number = (double)nmb;
            double ans = (number/cnt*1.0)*100.0;

            //cout<<mp[it->first]<<endl;

            char arra[40];

            string str = it->first;
            int i;
            for(i=0; str[i]; i++)
                arra[i]=str[i];
            arra[i]='\0';

            printf("%s %.4lf\n",arra,ans);
            //cout<<ans<<endl;

            it++;
        }

        if(test>0)
            cout<<endl;
    }
}