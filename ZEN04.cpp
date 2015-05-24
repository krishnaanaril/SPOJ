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
#define MAX 100007
#define INF 1000000007
#define MOD 1000000007

ll maxv(ll a, ll b)
{
    return a>b?a:b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, left[MAX], right[MAX], dat[MAX], pos, ans=-1;
    stack<int> stk;
    cin>>n;
    ini(left, 0);
    ini(right, 0);
    for(int i=0;i<n;i++)
    {   
        cin>>dat[i];
    }
    stk.push(0);
    for(int i=1;i<n;i++)
    {   
        while(!stk.empty() && dat[i]>dat[stk.top()])
        {
            pos=stk.top();
            stk.pop();
            right[pos]=i+1;           
        }
        stk.push(i);
    }
    while(!stk.empty())
        stk.pop();
    stk.push(n-1);
    for(int i=n-2;i>=0;i--)
    {
        while(!stk.empty() && dat[i]>dat[stk.top()])
        {
            pos=stk.top();
            stk.pop();
            left[pos]=i+1;           
        }
        stk.push(i);
    }
    for(int i=0;i<n;i++)
    {
        cout<<left[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<right[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        ans=maxv(ans, (1LL)*left[i]*right[i]);       
        //cout<<right[i]<<" ";
    }
    //left[0]=right[0]=MAX;
    cout<<ans<<endl;
    //cout<<maxv(ans, (1LL)*left[0]*right[0])<<endl;
    return 0;
}
