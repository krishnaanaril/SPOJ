/*
    Name: Krishna Mohan
    Date: //2015
    Algorithm:
    Site: Hacker Rank
    Contest: ZenHacks - Hypercode
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
#define MAX 100007
#define INF 1000000007
#define MOD 1000000007

ll mind(ll a, ll b)
{
    if(a<b)
        return a;
    else 
        return b;
}

ll findDist(int a, int b, int d)
{
    int n;
    ll sum=0;
    vi va, vb;
    while(a)
    {
        va.pb(a%d);
        a/=d;
    }
    while(b)
    {
        vb.pb(b%d);
        b/=d;
    }    
    while(va.size()!=vb.size())
    {
        if(va.size()<vb.size())
        {
            va.pb(0);
        }
        else
        {
            vb.pb(0);
        }
    }
    n=va.size();
    for(int i=0;i<n;i++)
    {
        sum+=abs(va[i]-vb[i]);
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, k, d, sz, temp, dig, min;
    ll sum, curr;
    vector<int> mkts;
    ll dist[MAX];
    cin>>t;
    while(t--)
    {
        ini(dist, INF);
        mkts.clear();
        sum=0;
        
        cin>>n>>d>>k;
        for(int i=0;i<k;i++)
        {
            dig=0;
            for(int j=0;j<d;j++)
            {
                cin>>temp;
                temp--;
                dig+=temp*pow(n, d-j-1);                
            }
            mkts.pb(dig);
            //cout<<dig<<endl;
        }
        //cout<<"fd: "<<findDist(2,0,2)<<endl;
        //sort(mkts.begin(), mkts.end());
        sz=pow(n, d);
        assert(sz<MAX);
        for(int j=0;j<k;j++)
        {
            sum=0;
            //cout<<"sz: "<<sz<<endl;
            for(int i=0;i<sz;i++)
            {
                curr=findDist(i, mkts[j], n);
                dist[i]=mind(dist[i], curr);
                //cout<<i<<" : "<<mkts[j]<<" : "<<d<<" : "<<curr<<" : "<<dist[i]<<endl;
                sum+=dist[i];
            }            
            cout<<sum<<endl;
        }
    }
    return 0;
}
