#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if(!b)
        return a;
    return gcd(b, a%b);
}

int main()
{
    int t, a, b, c, g;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b>>c;
        g=gcd(a, b);
        if(c%g==0)
        {
            printf("Case %d: Yes\n", i);
        }
        else
            printf("Case %d: No\n", i);
    }
    return 0;
}
