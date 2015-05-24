/*
    Name: Krishna Mohan
    Date: 3//2015
    Algorithm:
    Site: Codechef
    Contest: April long
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
#define MAX 100001
#define INF 1000000007
#define MOD 1000000007
#define INPUTFILE 1

const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;

bitset<MAX> isTaken;

int main()
{
    #ifndef INPUTFILE
        freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int t, n, tmp, cnt;
    vi dat;
    cin>>t;
    while(t--)
    {
        dat.clear();
        cnt=0;
        cin>>n;
        isTaken.reset();
        fo(i, n)
        {
            cin>>tmp;
            dat.pb(tmp);
        }
        fo(i, n-1)
        {
            if(dat[i]!=dat[i+1])
            {
                if(!isTaken[i])
                {
                    isTaken[i]=1;
                    cnt++;
                }
                if(!isTaken[i+1])
                {
                    isTaken[i+1]=1;
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
