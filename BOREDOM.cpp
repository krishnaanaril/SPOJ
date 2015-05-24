/*
    Name: Krishna Mohan
    Date: 4/3/2015
    Algorithm: Dynamic Programming
    Site: Codeforces
    Contest: 206 Div - 2 - Boredom
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
#define MAX 100008
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
    ll arr[MAX], dat[MAX], m[MAX], n;
    ini(m, 0);
    ini(arr, 0);
    cin>>n;
    fo(i,n)
    {
        cin>>dat[i];
        m[dat[i]]++;
    }
    arr[0]=0, arr[1]=m[1];
    re(i, 2, MAX)
    {
        arr[i]=max(arr[i-1], arr[i-2]+m[i]*i);
    }
    cout<<arr[MAX-1]<<endl;
    return 0;
}
