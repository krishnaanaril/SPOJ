#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string num;
    int t, sz, count;
    cin>>t;
    while(t--)
    {
        count=0;
        cin>>num;
        sz=num.size();
        for(int i=0;i<sz;i++)
        {
            if(num[i]=='4')
                count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
