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
#define MAX 100
#define INF 1000000007
#define MOD 1000000007

int solve(int a, int b)
{
    if(a==0 || b==0 || (a<2 && b<2))
        return 0;
    if(b>(2*a))
        return a;
    else
        return (b/2)+solve(min(b-(2*(b/2)), a-(b/2)), max(b-(2*(b/2)),a-(b/2)));
}

int solve2(int a, int b)
{
    int ans=0;
    if(a==0 || b==0 || (a<2 && b<2))
        return 0;
    rep(i, 2, b/2)
    {
        ans=max(ans, i+min(b-2*i, a-i));
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int a, b;
    cin>>a>>b;
    //cout<<solve(min(a, b), max(a, b))<<endl;
    cout<<min((a+b)/3, min(a,b))<<endl;
    return 0;
}
