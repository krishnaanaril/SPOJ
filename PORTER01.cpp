#include <bits/stdc++.h>

using namespace std;

#define MAX 100005 
int n, q, dat[MAX], l, r, k;
long long ans[11][MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>dat[i];
    }
    for(int i=1;i<11;i++)
    {
        for(int j=1;(j<=i && j<=n);j++)
            ans[i][j]=dat[j-1];
        for(int j=i;j<=n;j++    )
            ans[i][j]=dat[j-1]+ans[i][j-i];
    }
    /*for(int i=1;i<10;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int i=0;i<q;i++)
    {
        cin>>l>>r>>k;
        int R=l+(((r-l)/k)*k);
        int L=l-k<0?0:l-k;
        //cout<<L<<" - "<<R<<endl;
        cout<<ans[k][R]-ans[k][L]<<endl;
    }
    return 0;
}
