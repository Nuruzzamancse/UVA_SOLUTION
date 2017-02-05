#include<bits/stdc++.h>

using namespace std;

int main()
{
    char input1[105], input2[105], input[300];

    map<string,string>mp;

    char k,p;
    // scanf("%s %s",input1,input2);

    while(gets(input))
    {
        if(input[0]=='\0')
            break;
        int i=0,k=0,l=0;
        for(; input[i]; i++)
        {
            if(input[i]==' ')
                break;
            input1[k++] = input[i];
        }

        input1[k]='\0';

        for(i++; input[i]; i++)
            input2[l++] = input[i];
        input2[l]='\0';

        mp[input2] = input1;
        //cout<<input2<<' '<<input1<<endl;


    }

    char query[105];

    while(scanf("%s",query)!=EOF)
    {
        if(mp[query]=="")
            cout<<"eh"<<endl;
        else
            cout<<mp[query]<<endl;
    }

    return 0;

}