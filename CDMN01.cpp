/*
    Name: Krishna Mohan
    Date: //2015
    Algorithm:
    Site:
    Contest:
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
#define MAX 100001
#define INF 1000000007
#define MOD 1000000007

ll dat[MAX];

ll gcd(ll a, ll b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t, m;
    cin>>t>>m;
    fo(i, m)
    {
        cin>>dat[i];
    }
    if(m==1)
        cout<<dat[0]<<endl;
    else
    {
        ll ans=gcd(dat[0], dat[1]);
        re(i, 2, m)
        {
            ans=gcd(ans, dat[i]);
        }
        cout<<ans<<endl;
    }    
    return 0;
}
