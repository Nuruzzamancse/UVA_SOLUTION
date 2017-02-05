#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    scanf("%d",&test);
    long long int a, b;
    while(test--)
    {

        scanf("%lld %lld",&a,&b);

        if(a<b)
            printf("<\n");
        else if(a>b)
            printf(">\n");
        else
            printf("=\n");


    }

    return 0;
}
