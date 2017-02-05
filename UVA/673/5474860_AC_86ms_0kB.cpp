#include<bits/stdc++.h>
#include<stack>

using namespace std;

int main()
{
    int test;

    scanf("%d",&test);

    getchar();

    while(test--)
    {
        char ch;

        stack<char>st;

        while(true)
        {
            scanf("%c",&ch);
            if(ch=='\n')
                break;

            if(!st.empty()&&((st.top()=='('&&ch==')')||(st.top()=='['&&ch==']')))
                st.pop();
            else
                st.push(ch);
        }

        if(st.empty())
            printf("Yes\n");
        else
            printf("No\n");

    }

    return 0;
}