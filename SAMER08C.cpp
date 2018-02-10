/*
    Name: Krishna Mohan
    Date: 2/28/2015
    Algorithm:
    Site: SPOJ
    Contest:    SAMRE08C
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
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

ll solve(vll dat)
{
    
    int sz=dat.size();
    for(int i=1;i<sz;i++)
    {
        if(i==1)
            dat[i]=max(dat[i-1], dat[i]);
        else
            dat[i]=max(dat[i-1], dat[i]+dat[i-2]);
    }
    return dat[sz-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    vll a, b;
    int m, n, x;
    while(true)
    {
        cin>>m>>n;
        if(m==0 && n==0) break;
        b.clear();
        for(int i=0;i<m;i++)
        {
            a.clear();
            for(int j=0;j<n;j++)
            {
                cin>>x;
                a.pb(x);
            }
            b.pb(solve(a));
        }
        cout<<solve(b)<<endl;
    } 
    return 0;
}
