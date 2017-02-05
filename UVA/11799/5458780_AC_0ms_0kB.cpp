#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    scanf("%d",&test);
    int cas=1;
    while(test--)
    {
       int N, a, max = -1;

       scanf("%d",&N);

       for(int i=0;i<N;i++)
       {
           scanf("%d",&a);

           if(max<a)
            max = a;
       }

       printf("Case %d: %d\n",cas++,max);

    }

    return 0;
}
