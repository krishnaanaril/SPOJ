#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    ll a, b, x1, x2, y1, y2, z1, z2;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        --a;
        x1=a/3;
        y1=a/5;
        z1=a/15;
        x1-=z1;
        y1-=z1;
        x2=b/3;
        y2=b/5;
        z2=b/15;
        x2-=z2;
        y2-=z2;
        cout<<(x2-x1)<<" "<<(y2-y1)<<" "<<(z2-z1)<<endl;
    }
    return 0;
}
