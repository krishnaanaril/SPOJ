/*
    Name: Krishna Mohan
    Date: 4/6/2015
    Algorithm: DP
    Site: Codechef
    Contest: Practice - Easy - AEHASH
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
#define INPUTFILE 1

const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;

int dp[55][55][1024];

ull fun(int a, int e, int v)
{
    if(v<0) return 0;
    if(dp[a][e][v] != -1)
        return dp[a][e][v];
    if((a+e)<=1)
        return dp[a][e][v]=(a<=v);
    ull ans=0;
    int t=(a+e)/2;
    fo(i, t+1)
    {
        if((i<=a) && ((t-i)<=e))
        {
            ans+=(fun(i, t-i, v-a)*fun(a-i, e-(t-i), v-a));
            ans%=MOD;
        }
    }
    return dp[a][e][v]=ans;
}

int main()
{
    #ifndef INPUTFILE
        freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int t, a, e, v;
    ull ans=0;
    ini(dp, -1);
    cin>>t;
    while(t--)
    {
        cin>>a>>e>>v;
        ans= (fun(a, e, v) - fun(a, e, v-1) + MOD)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
