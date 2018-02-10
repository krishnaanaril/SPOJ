#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull gcd(ull a, ull b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t, f=0;
    ull a, b, tmp;
    cin>>t;
    while(t--)
    {
        f=0;
        cin>>a>>b;
        tmp=gcd(a, b);
        if(tmp==1LL && b!=1LL)
            f=1;
        else
        {
            while(b!=1LL)
            {
                tmp=gcd(a, b);
                if(tmp==1LL)
                {
                    //cout<<b<<endl;
                    f=1;
                    break;
                }
                b/=tmp;
            }
        }
        if(f)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}
