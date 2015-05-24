#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    ll t, n, s, cnt, sum, diff;
    cin>>t;
    while(t--)
    {
        cnt=0;
        cin>>n>>s;
        sum=n*(n+1)/2;
        diff=sum-s;
        int j=n;
        while(diff>0)
        {
            diff-=(j-1);
            j--;
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
