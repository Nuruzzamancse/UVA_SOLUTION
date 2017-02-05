#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, cou;
    string key;
    cin>>n;
    getchar();
    getchar();
    for(i=0; i<n; i++)
    {
        map<string, int>m;
        cou= 0;
        while(1)
        {
            getline(cin, key);
            if(key[0] == '\0')break;
            m[key]++;
            cou++;
        }
        map<string, int>::iterator it;
        it = m.begin();
        while(it != m.end())
        {
            double result, num = it->second;
            result = (num/cou*1.0)*100.0;
            printf("%s %.4lf\n", (*it).first.data(), result);
            it++;
        }
        //getchar();
        if(i<n-1)
           printf("\n");

    }
    return 0;
}