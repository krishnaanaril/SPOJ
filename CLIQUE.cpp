/*
    Name: Krishna Mohan
    Date: 3/20/2015
    Algorithm: Greedy
    Site: Codeforces
    Contest: Practice - Clique Problem
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

const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;

bool comp(const pi &a, const pi &b)
{
    //cout<<(a.fi+a.se)<<"->"<<(b.fi+b.se)<<endl;
    return a.fi+a.se < b.fi+b.se;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t, x , w;
    vector<pi> dat;
    cin>>t;
    fo(i, t)
    {
        cin>>x>>w;
        dat.pb(make_pair(x, w));
    }
    sort(dat.begin(), dat.end(), comp);
    /*fo(i, dat.size())
    {
        cout<<dat[i].fi<<" "<<dat[i].se<<endl;
    }*/
    int last=0;
    int ans=1;
    re(i, 1, t)
    {
        if(dat[last].fi+dat[last].se <= dat[i].fi-dat[i].se)
        {
            //cout<<last<<"->"<<i<<endl;
            last=i;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
