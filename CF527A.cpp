/*
    Name: Krishna Mohan
    Date: 3//2015
    Algorithm: Ad-hoc
    Site: Codeforces
    Contest: Practice - 527 A
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

int main()
{
    ios_base::sync_with_stdio(0);
    ull a, b, x, y, m, ans=0;
    cin>>a>>b;
    if(b>a)
        swap(b, a);
    do
    {
        ans+=a/b;
        m=b;
        b=a%b;
        a=m;
    }
    while(b!=0);
    cout<<ans<<endl;
    return 0;
}
