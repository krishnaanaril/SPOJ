#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

//#define FASTIO          ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back
#define x               first
#define y               second
#define MAX             100005

const int mod = 1000000007;

int dat[20][MAX];
int n, q, a, b, tmp, t, len, k, ca;
vector<int> arr;
 
void init()
{
    memset(dat, 0, sizeof(dat));
    REP(i, n)
        dat[0][i] = arr[i];
        
    for(int j=1; j<=log2(n); j++)
        for(int i=0; i+pow(2, j-1)<n; i++)
            dat[j][i] = min(dat[j-1][i], dat[j-1][i+(int)pow(2, j-1)]);
            
}

int main()
{
    //FASTIO
    //cin>>t;
    scanf("%d", &t);
    while(t--)
    {        
        ca++;
        //cout<<"Scenario #"<<ca<<":"<<endl<<endl;
        printf("Scenario #%d:\n\n", ca);
        arr.clear();
        //cin>>n>>q;
        scanf("%d%d", &n, &q);
        REP(i, n)
        {
            //cin>>tmp;
            scanf("%d", &tmp);
            arr.pb(tmp);
        }
        init();
        REP(i, q)
        {
            //cin>>a>>b;
            scanf("%d%d", &a, &b);
            a--;
            b--;
            //cout<<a<<" "<<b<<endl;
            len = b-a+1;
            k = log2(len);
            //cout<<min(dat[k][a], dat[k][b+1-(int)pow(2, k)])<<endl<<endl;
            printf("%d\n\n", min(dat[k][a], dat[k][b+1-(int)pow(2, k)]));
        }
    }
    return 0;
}
