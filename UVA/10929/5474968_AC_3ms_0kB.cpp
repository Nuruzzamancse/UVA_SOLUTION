#include<bits/stdc++.h>

using namespace std;

int main()
{
   char str[1500];

   while(true)
   {
       gets(str);

       int length = strlen(str);

       if(length==1&&str[0]=='0')
            break;
       int num1=0, num2=0;
       for(int i=0;i<length;i+=2)
       {

            num1 += str[i] - '0';
       }
       for(int i=1;i<length;i+=2)
       {

            num2 += str[i] - '0';
       }


       if((abs(num1-num2))%11==0)
            printf("%s is a multiple of 11.\n",str);
       else
            printf("%s is not a multiple of 11.\n",str);

   }

   return 0;
}