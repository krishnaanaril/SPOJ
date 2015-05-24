/*
    Name: Krishna Mohan
    Date: 3/14/2015
    Algorithm: Plain Math
    Site: Hacker Rank
    Contest: Closest Number
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;
typedef vector<pi> vpi;

// Basic macros
#define fi          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fo(i,n)     re(i,0,n)
#define rev(i,n,s)  for(int i=(n)-1;i>=s;--i)
#define repv(i,n,s) for(int i=(n);i>=s;--i)
#define fov(i,n)    rev(i,n,0)
#define pb          push_back
#define mp          make_pair
#define si(x)       (int)(x.size())
#define MAX 100
#define INF 1000000007
#define MOD 1000000007

ll bigMod(ll a, ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
            res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t, a, b, x, div, power, ans, a1, a2;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>x;
        if(b<0)
        {
            if(a==1)
                ans=1;
            else
                ans=0;

        }
        else
        {
            power = bigMod(a, b);
            div=power/x;
            a1=(div*x);
            a2=(div+1)*x;
            ans= (power-a1) < (a2-power)?a1:a2;
        }
        cout<<ans<<endl;
    }
    return 0;
}
