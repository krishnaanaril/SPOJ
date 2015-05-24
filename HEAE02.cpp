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

void multiply(ull F[2][2], ull M[2][2])
{
  ull x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  ull y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  ull z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  ull w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
 
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
 
void power(ull F[2][2], ull n)
{
  ull i;
  ull M[2][2] = {{1,1},{1,0}};
  ull res[2][2] = {{1,0},{0,1}};
 
  // n - 1 times multiply the matrix to {{1,0},{0,1}}
  /*for (i = 2; i <= n; i++)
      multiply(F, M);*/
  while(n)
  {
        if(n&1)
            multiply(res, F);
        multiply(F, F);
  }  
}

ull fib(ull n)
{
    ull F[2][2] = {{1,1},{1,0}};
    if (n == 0)
      return 0;
    power(F, n-1); 
    return F[0][0];
}

int main()
{
    #ifndef INPUTFILE
        freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int t;
    ull n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<fib(n)<<endl;
    }
    return 0;
}
