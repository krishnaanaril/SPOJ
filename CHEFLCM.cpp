/*
    Name: Krishna Mohan
    Date: 4/4/2015
    Algorithm: Maths
    Site: Codechef
    Contest: April long 2015
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
    int t, n, sq;
    ull sum;
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>n;
        sq=sqrt(n);
        rep(i, 2, sq)
        {
            if(n%i==0)
            {
                //cout<<i<<endl;
                sum+=i;
                if(i!=(n/i))
                {
                    //cout<<n/i<<endl;
                    sum+=(n/i);
                }
            }
        }
        sum+=1;
        if(n!=1)
            sum+=n;
        cout<<sum<<endl;
    }
    return 0;
}
