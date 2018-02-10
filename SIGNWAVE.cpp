#include <bits/stdc++.h>

using namespace std;

#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fo(i,n)     re(i,0,n)
#define rev(i,n,s)  for(int i=(n)-1;i>=s;--i)
#define repv(i,n,s) for(int i=(n);i>=s;--i)
#define fov(i,n)    rev(i,n,0)

#define MAXS 51
#define MAXK 101

long long S[MAXS][MAXK], C[MAXS][MAXK];
long long ans;
int main()
{
    ios_base::sync_with_stdio(0);
    S[1][1]=3;
    re(i, 2, MAXS)
    {
        S[i][1]=S[i-1][1]+pow(2,i-1);
        re(j, 2, MAXK)
            S[i][j]=S[i-1][j-1];
    }    
    re(i, 1, MAXS)
    {
        C[i][1]=pow(2, i);
    }
    fo(i, 10)
    {
        fo(j, 10)
        {
            cout<<S[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    fo(i, 10)
    {
        fo(j, 10)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
    
    int t, s, c, k;
    cin>>t;
    while(t--)
    {   
        cin>>s>>c>>k;
        ans=0;
        if(s!=0)
            ans+=S[s][k];
        if(c!=0)
        {    
            ans+=C[c][k];
            if(c>k && s>k)
                ans-=C[s-k][k];
        }
        cout<<"Ans: "<<ans<<endl;
    }
    return 0;
}
