/*
    Name: Krishna Mohan
    Date: 4/9/2015
    Algorithm: Greedy
    Site: CodeChef
    Contest: TADELIVE
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
#define MOD 1000000007
#define INPUTFILE 1

const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;

bool compare(const pii &a, const pii &b)
{
    return (a.fi-a.se)>(b.fi-b.se);
}

int main()
{
    #ifndef INPUTFILE
        freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int n, x, y, a, b, ac, bc, mx;
    vector<pii> dat;
    cin>>n>>x>>y;
    fo(i, n)
    {
        cin>>a;
        dat.push_back(pii(a, 0));
    }
    fo(i, n)
    {
        cin>>dat[i].se;
    }
    sort(dat.begin(), dat.end(), compare);
    ac=bc=mx=0;    
    fo(i, n)
    {
        //cout<<dat[i].fi<<" "<<dat[i].se<<endl;   
        if(ac>=x)
        {   
            mx+=dat[i].se;
            bc++;
        }
        else if(bc>=y)
        {
            mx+=dat[i].fi;
            ac++;
        }
        else
        {
            if(dat[i].fi>dat[i].se)
            {
                mx+=dat[i].fi;
                ac++;
            }
            else
            {
                mx+=dat[i].se;
                bc++;
            }
        }
    }
    cout<<mx<<endl;
    return 0;
}
