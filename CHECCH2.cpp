#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, sz, a, b;
    string str;
    cin>>t;
    while(t--)
    {
        a=b=0;
        cin>>str;
        sz=str.size();
        for(int i=0;i<sz;i+=2)
        {
            if(str[i]!='+') a++;
            if(str[i]!='-') b++;
        }
        for(int i=1;i<sz;i+=2)
        {
            if(str[i]!='-') a++;
            if(str[i]!='+') b++;
        }
        //cout<<a<<" : "<<b<<endl;
        cout<<min(a, b)<<endl;
    }
    return 0;
}
