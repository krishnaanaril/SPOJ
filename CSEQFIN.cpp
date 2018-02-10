/*
    Name: Krishna Mohan
    Date: 4/14/2015
    Algorithm: Combinatorics, bigMod
    Site: Codechef
    Contest: April Long  - CSEQ
    Remarks: Coudn't solve the problem during the contest, in the editorial solution is C(R-L+1+N, N)
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
typedef vector<pii> vpi;

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
#define MOD 1000003
#define INPUTFILE 1

const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;

ll fact[MOD+5];

inline void init()
{
    fact[0]=1;
    re(i, 1, MOD+5)
        fact[i]=(i*fact[i-1])%MOD;
}

inline ll bigMod(ll base, ll exp)
{
    ll res=1;
    while(exp)
    {
        if(exp&1)
            res = (res*base)%MOD;
        base = (base*base)%MOD;
        exp>>=1;
    }
    return res;
}

inline ll inv(ll num)
{
    return bigMod(num, MOD-2);
}

ll Lucas(ll num, ll den)
{
    if(den<0 || den>num)
        return 0;
    if(num==0)
        return 1;
    ll _num = num%MOD;
    ll _den = den%MOD;
    if(_den>_num)
        return 0;
    //return Lucas(num/MOD, den/MOD)*(fact[_num] * (inv(fact[_num])* inv(fact[_num-_den]) % MOD ) % MOD) % MOD;
    return Lucas(num / MOD, den / MOD) * (fact[_num] * (inv(fact[_den]) * inv(fact[_num - _den]) % MOD) % MOD) % MOD;
}

/*ll Lucas(ll n, ll m) {
if (m < 0 || m > n) return 0;
if (n == 0) return 1;
ll n_ = n % MOD, m_ = m % MOD;
if (m_ > n_) return 0;
return Lucas(n / MOD, m / MOD) * (fact[n_] * (inv(fact[m_]) * inv(fact[n_ - m_]) % MOD) % MOD) % MOD;
}*/

int main()
{
    #ifndef INPUTFILE
        freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    init();
    int t;
    ll n, l, r, ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>l>>r;
        //cout<<n<<l<<r<<endl;
        ans = (Lucas(r-l+1+n, n)-1+MOD)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
