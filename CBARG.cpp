#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, curr, x;
    long long ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        //cout<<"N: "<<n<<endl;
        ans=curr=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x>curr)
                ans+=x-curr;
            curr=x;
        }
        cout<<ans<<endl;
    }
    return 0;
}
