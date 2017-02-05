#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    scanf("%d",&test);

    int arra[3],  cas=1;


    while(test--)
    {
        for(int i=0;i<3;i++)
            scanf("%d",&arra[i]);
        sort(arra,arra+3);

        printf("Case %d: %d\n",cas++,arra[1]);

    }

    return 0;
}
