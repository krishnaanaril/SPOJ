/*
    Name: Krishna Mohan
    Date: 4/28/2015
    Algorithm: Dynamic Programing, Recursion
    Site: SPOJ
    Contest: RENT
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
#define MAX 10001
#define INF 1000000007
#define MOD 1000000007
#define INPUTFILE 1

const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;

int t, n, a, b, c, res, dp[MAX];
vector< pair<int, pi > > dat;

int latestNonConflict(int n)
{
    for(int j=n-1;j>=0;j--)
        if(dat[j].fi <= dat[n-1].se.fi)
            return j;
    return -1;
}

int maxRentRecur(int n)
{
    if(n==1) return dat[n-1].se.se;
    int l=latestNonConflict(n);
    int incl=dat[n-1].se.se, excl=0;
    if(l!=-1)
        incl+=maxRentRecur(l+1);
    excl+=maxRentRecur(n-1);
    return max(incl, excl);
}

int maxRentIter(int n)
{
    dp[0]=dat[0].se.se;
    for(int i=1;i<n;i++)
    {
        int incl=dat[i].se.se;
        int l=latestNonConflict(i);
        if(l!=-1)
            incl+=dp[l];
        dp[i]=max(incl, dp[i-1]);
    }
    return dp[n-1];
}

int main()
{
    #ifndef INPUTFILE
        freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        dat.clear();
        cin>>n;
        fo(i, n)
        {
            cin>>a>>b>>c;
            dat.pb(mp(b, mp(a, c)));
        }
        sort(dat.begin(), dat.end());        
        /*res=maxRentRecur(n);
        cout<<res<<endl;*/
        res=maxRentIter(n);
        cout<<res<<endl;
    }    
    return 0;
}
