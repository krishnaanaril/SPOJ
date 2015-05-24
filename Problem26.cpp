/*
    Name: Krishna Mohan
    Date: 3/21/2015
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

const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;

int main()
{
    ios_base::sync_with_stdio(0);
    int d=2, num, max=0, cnt;
    map<int, bool> dat;
    while(d<10)
    {
        num=1;
        cnt=0;
        dat.clear();
        while(dat[num]==0)
        {
            dat[num]==true;
            num=(num*10)%d;
            cnt++;
        }        
        if(cnt>max)
            max=cnt;
    }
    max--;
    cout<<max<<endl;
    return 0;
}
