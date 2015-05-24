/*
    Name: Krishna Mohan
    Date: 3//2015
    Algorithm:
    Site:
    Contest:
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

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
#define MOD 1000003
#define INPUTFILE 1

const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;

inline ull getSq(ull num)
{
    return (num*num)%MOD;
}

int main()
{
    #ifndef INPUTFILE
        freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int t;
    ull n, l, r, k;
    ull sum;
    cin>>t;
    while(t--)
    {
        cin>>n>>l>>r;
        k=r-l+1;
        sum=k;
        ull tsum=0;
        if(n>1)
        {
            tsum+=(((n-1)*getSq(k)))%MOD;
            //cout<<"1: "<<(((n-1)*getSq(k)))%MOD<<endl;
            tsum%=MOD;
            tsum+=((((n-1)*(2+(n-2)*2)*k)%MOD)/2)%MOD;
            //cout<<"2: "<<((((n-1)*(2+(n-2)*2)*k)%MOD)/2)%MOD<<endl;
            tsum%=MOD;
        }
        if(n>2)
        {
            ull t1=((((n-2)*(n-1))%MOD)/2);
            //cout<<"3: "<<t1<<endl;
            ull t2=((((((n-2)*(n-1))%MOD)*(2*n-3))%MOD)/6);
            //cout<<"4: "<<t2<<endl;
            tsum+=((t1+t2))%MOD;
            tsum%=MOD;
        }
        //cout<<"tsum: "<<tsum<<endl;
        sum = (sum + (tsum/2))%MOD;
        cout<<sum<<endl;
    }
    return 0;
}
