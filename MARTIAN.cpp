/*
    Name: Krishna Mohan
    Date: 2/28/2015
    Algorithm:
    Site: SPOJ
    Contest:   MARTIAN 
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
#define MAX 501
#define INF 1000000007
#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(0);
    int m, n, y[MAX][MAX], b[MAX][MAX], i, j;
    ll sum;
    while(true)
    {
        sum=0;
        cin>>m>>n;
        if(m==0 && n==0) break;
        fo(i, m)
        {
            fo(j, n)
            {
                cin>>y[i][j];
                if(j>0) y[i][j]+=y[i][j-1];
                cout<<y[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        fo(i, m)
        {
            fo(j, n)
            {
                cin>>b[i][j];
                if(i>0) b[i][j]+=b[i-1][j];
                cout<<b[i][j]<<" "; 
            }
            cout<<endl;
        }
        cout<<endl;
        int i=0, j=0;
        while(i<m && j<n)
        {
            if(y[i][j]>=b[i][j])
            {
                sum+=y[i][j];
                cout<<y[i][j]<<" ";
                i++;
            }
            else
            {
                sum+=b[i][j];
                cout<<b[i][j]<<" ";
                j++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
