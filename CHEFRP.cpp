/*
    Date: 5/10/2015
    Codechef: CHEFRP
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, tmp, f;
    ll ans;
    vector<int> dat;
    cin>>t;
    while(t--)
    {
        dat.clear(), ans=0, f=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>tmp;
            dat.push_back(tmp);
        }
        sort(dat.begin(), dat.end(), greater<int>());
        for(int i=0;i<n;i++)
        {
            if(dat[i]<2)
            {    
                f=1; 
                break;
            }
            else
            {
                if(i!=n-1)
                    ans+=dat[i];
                else
                    ans+=2;
            }
        }
        if(f)
            cout<<"-1"<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
