#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

int dat[MAX], tmp[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    int n, q, p, ans=0, x, y;
    cin>>n>>q;
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
        ans%=2;
    }
    for(int i=0;i<=n;i++)
            cout<<tmp[i]<<" ";
        cout<<endl;
    for(int i=0;i<q;i++)
    {
        cin>>x>>y;
        ans^=1;
        cout<<ans<<endl;
    }
    return 0;
}
