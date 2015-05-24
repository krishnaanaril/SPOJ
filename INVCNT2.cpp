/*
    Inversion Count using BIT
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define MAX 200001

int dat[MAX], tmp[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, p, ans;
    cin>>t;
    while(t--)
    {
        ans=p=0;
        memset(tmp, 0, sizeof(tmp));
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>dat[i];
        for(int i=0;i<=n;i++)
            cout<<tmp[i]<<" ";
        cout<<endl;
        for(int i=1;i<=n;i++)
        {
            p=0;
            for(int j=dat[i];j; j=(j & (j-1)))
                p+=tmp[j];
            for(int j=dat[i];j<=n; j=(j|(j-1))+1)
                ++tmp[j];
            ans = (ans+i-p-1);
            cout<<"Ans: "<<ans<<endl;
            //ans%=2;
        }
        for(int i=0;i<=n;i++)
            cout<<tmp[i]<<" ";
        cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}
