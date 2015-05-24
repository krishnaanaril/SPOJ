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

char* Modify(char a[51], int n,int i, int j)
{
    //cout<<a<<i<<j<<endl;
    char c[51];
    fo(k, n)
        c[k]=a[k];
    char temp=c[i];
    for(int k=i+1;k<=j;k++)
    {
        c[k-1]=c[k];
    }
    c[j]=temp;
    //cout<<"C: "<<c<<endl;
    return c;
}

int main()
{
    #ifndef INPUTFILE
        freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int t, n;
    char a[51], *b, ans[51];
    cin>>t;
    while(t--)
    {
        cin>>n;
        fo(i, n)
        {
            cin>>a[i];
        }
        cout<<a<<endl;
        fo(i, n)
        {
            fo(j, n)
            {
                b=Modify(a, n, i, j);
                fo(k, n)
                    cout<<b[i];
                cout<<endl;
            }
        }
    }
    return 0;
}
