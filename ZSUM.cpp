/*
    Name: Krishna Mohan
    Date: 4/25/2015
    Algorithm: Maths
    Site: SPOJ  
    Contest: ZSUM
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

ll bigMod(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b&1)
            ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        //cout<<"b: "<<b<<"a: "<<a<<"ans: "<<ans<<endl;
        b>>=1;
    }
    return ans%MOD;
}

int main()
{
    #ifndef INPUTFILE
        freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    ll n, k, a, b, c, d, ans;
    /*while(true)
    {
        cin>>n>>k;
        cout<<bigMod(n, k)<<endl;
    }*/
    while(true)
    {
        cin>>n>>k;
        if(n==0 && k==0)
            break;
        a = bigMod(n-1, k);
        a = (2*a)%MOD;
        b  = bigMod(n, k);
        //ans = (a+b)%MOD;
        c = bigMod(n-1, n-1);
        c = (2*c)%MOD;
        //ans = (ans+c)%MOD;
        d = bigMod(n, n);
        //ans = (ans+d)%MOD;
        //cout<<"Test: "<<bigMod(5,5)<<endl; 
        cout<<a<<" : "<<b<<" : "<<c<<" : "<<d<<endl;     
        ans = (a+b+c+d)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
