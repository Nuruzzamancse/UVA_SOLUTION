#include<bits/stdc++.h>

using namespace std;

int main()
{
    char ou,arra[100001];

    while((cin>>arra))
    {

       list<char>lst;

       list<char>::iterator it=lst.begin();

       for(int i=0;arra[i];i++)
       {
           if(arra[i]=='[')
            it = lst.begin();
           else if(arra[i]==']')
            it = lst.end();
           else
            lst.insert(it,arra[i]);
       }

       for(it=lst.begin();it!=lst.end();it++)
        cout<<*it;
       cout<<endl;
    }


}