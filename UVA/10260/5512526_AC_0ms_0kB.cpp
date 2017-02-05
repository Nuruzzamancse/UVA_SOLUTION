#include<bits/stdc++.h>

using namespace std;

int main()
{
    char str[25];

    while(scanf("%s",str)!=EOF)
    {
        int len = strlen(str);
        char arr[20];

        int k=0;

        for(int i=0; str[i]; i++)
        {
            if(str[i]=='B'||str[i]=='F'||str[i]=='P'||str[i]=='V')
            {
                bool flag = false;
                if((i+1)<len)
                {
                    for( ;(str[i+1]=='B'||str[i+1]=='F'||str[i+1]=='P'||str[i+1]=='V')&&str[i+1]; i++)
                    {
                        flag = true;
                    }
                }


                arr[k++] = '1';
            }
            else if(str[i]=='C'||str[i]=='G'||str[i]=='J'||str[i]=='K'||str[i]=='Q'||str[i]=='S'||str[i]=='X'||str[i]=='Z')
            {
                bool flag = false;
                if((i+1)<len)
                {
                    for( ;(str[i+1]=='C'||str[i+1]=='G'||str[i+1]=='J'||str[i+1]=='K'||str[i+1]=='Q'||str[i+1]=='S'||str[i+1]=='X'||str[i+1]=='Z')&&str[i+1]; i++)
                    {
                        flag = true;

                    }
                }


                arr[k++] = '2';
            }
            else if(str[i]=='D'||str[i]=='T')
            {
                bool flag = false;
                if((i+1)<len)
                {
                    for(; (str[i+1]=='D'||str[i+1]=='T')&&str[i+1]; i++)
                    {
                        flag = true;
                    }
                }
                arr[k++] = '3';

            }
            else if(str[i]=='L')
            {
                bool flag = false;
                if((i+1)<len)
                {
                    for( ;(str[i+1]=='L')&&str[i+1]; i++)
                    {
                        flag = true;
                    }
                }


                arr[k++] = '4';
            }
            else if(str[i]=='M'||str[i]=='N')
            {
                bool flag = false;
                if((i+1)<len)
                {
                    for(; (str[i+1]=='M'||str[i+1]=='N')&&str[i+1]; i++)
                    {
                        flag = true;
                    }
                }

                arr[k++] = '5';

            }
            else if(str[i]=='R')
            {
                bool flag = false;
                if((i+1)<len)
                {
                    for(;(str[i+1]=='R')&&str[i+1]; i++)
                    {
                        flag = true;
                    }
                }

                arr[k++] = '6';
            }
        }

        arr[k] = '\0';

        printf("%s\n",arr);
    }
}