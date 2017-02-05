#include<bits/stdc++.h>

using namespace std;

int main()
{
    char input[25];

    while(cin>>input){

    bool flag_1=false,flag_2=false,flag_3=false,flag_4=false,flag_5=false,flag_6=false;
    for(int i=0;input[i];i++)
    {
        if((flag_1==false)&&(input[i]=='B'||input[i]=='F'||input[i]=='P'||input[i]=='V'))
        {
            flag_1=true;
            cout<<1;
           flag_2=false;flag_3=false;flag_4=false;flag_5=false;flag_6=false;


        }
        else if(!flag_2&&(input[i]=='C'||input[i]=='G'||input[i]=='J'||input[i]=='K'||input[i]=='Q'||input[i]=='S'||input[i]=='X'||input[i]=='Z')){
            cout<<2;
            flag_1=false,flag_2=true,flag_3=false,flag_4=false,flag_5=false,flag_6=false;
        }
        else if(!flag_3&&(input[i]=='D'||input[i]=='T')){
            cout<<3;
            flag_1=false,flag_2=false,flag_3=true,flag_4=false,flag_5=false,flag_6=false;
        }
        else if(!flag_4&&(input[i]=='L'))
        {
            cout<<4;
            flag_1=false,flag_2=false,flag_3=false,flag_4=true,flag_5=false,flag_6=false;
        }
        else if(!flag_5&&(input[i]=='M'||input[i]=='N'))
        {
            cout<<5;
            flag_1=false,flag_2=false,flag_3=false,flag_4=false,flag_5=true,flag_6=false;
        }
        else if(!flag_6&&input[i]=='R')
        {
            cout<<6;
            flag_1=false,flag_2=false,flag_3=false,flag_4=false,flag_5=false,flag_6=true;
        }
        else if((input[i]=='A'||input[i]=='E'||input[i]=='I'||input[i]=='O'||input[i]=='U'||input[i]=='H'||input[i]=='W'||input[i]=='Y'))
        {
            flag_1=false,flag_2=false,flag_3=false,flag_4=false,flag_5=false,flag_6=false;
            //cout<<"SHIT"<<endl;
        }
    }

    cout<<endl;

    }

    return 0;

}