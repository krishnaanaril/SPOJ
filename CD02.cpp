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

int main()
{
    ios_base::sync_with_stdio(0);
    int t, x, y, a, b, c;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        x=max(max(a, b),max(a,c));
        if(x==a)
            y=max(b, c);
        else if(x==b)
            y=max(a,c);
        else
            y=max(a, b);
        //cout<<x<<y<<endl;
        if(x==y)
        {
            cout<<(2*min(x, y))<<endl;
        }
        else if(y==0)
        {
            cout<<"1"<<endl;
        }
        else
        {
            cout<<(2*min(x, y)+1)<<endl;
        }
    }
    return 0;
}

