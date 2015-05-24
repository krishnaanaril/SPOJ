#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a;
    double x, y;
    cin>>m>>n>>a;
    x=max(m, n);
    y=min(m, n);
    unsigned long long ans=ceil(x/a)*ceil(y/a);
    cout<<ans<<endl;
    return 0;
}
