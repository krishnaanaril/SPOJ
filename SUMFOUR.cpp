/*
    Name: Krishna Mohan
    Date: 4/29/2015
    Algorithm: Binary Search
    Site: SPOJ
    Contest: SUMFOUR
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

int main()
{
    #ifndef INPUTFILE
        freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int n, ta, tb, tc, td, lim;
    ll ans=0;
    vector<int> a, b, c, d, ab, cd;
    pair<vi::iterator, vi::iterator> bounds;
    cin>>n;
    fo(i, n)
    {
        cin>>ta>>tb>>tc>>td;
        a.pb(ta);
        b.pb(tb);
        c.pb(tc);
        d.pb(td);
    }
    fo(i, n)
    {
        fo(j, n)
        {
            ab.pb(a[i]+b[j]);
            cd.pb(c[i]+d[j]);
        }
    }
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    lim=ab.size();
    //cout<<lim<<endl;
    /*fo(i, lim)
    {
        cout<<ab[i]<<" : "<<cd[i]<<endl;
    }*/
    fo(i, lim)
    {
        bounds=equal_range(cd.begin(), cd.end(), -1*ab[i]);       
        //cout<<(bounds.se-cd.begin())<<" "<<(bounds.fi-cd.begin())<<endl;
        ans+=(bounds.se - bounds.fi);
    }
    cout<<ans<<endl;
    return 0;
}
