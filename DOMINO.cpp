#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int m, n, a, b, ans;
    cin>>m>>n;
    a=max(m, n);
    b=min(m, n);
    ans=(a/2)*b;
    a%=2;
    ans+=(b/2)*a;
    cout<<ans<<endl;
    return 0;
}
