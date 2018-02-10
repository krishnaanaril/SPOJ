/*
	Swamy Saranam

	Date	: 04/06/2017 11:01:44
	Author	: Krishna Mohan A M
	Problem	:
	Status	:
*/
#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FASTIO                ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define FOR(i,a,b)            for(int i=(a);i<(b);i++)
#define REP(i,n)		      FOR(i,0,n)
#define SORT(v)               sort((v).begin(),(v).end())
#define UN(v)                 SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)               memset(a,b,sizeof a)
#define pb                    push_back
#define x                     first
#define y                     second
#define endl                  "\n"
#define sendl                 " \n"

const int mod = 1000000007;
const int N = 1e4+5;
const int LN = 19;

vector<pii> graph[N];
int fen[N], t, n, depth[N], parent[LN][N];
int lca, a, b, c, dist[N];
string cmd;

void dfs(int u, int p, int c, int d){
      depth[u] = d;
      dist[u] = c;
      parent[0][u] = p;
      for(pii v : graph[u]){
            if(v.x==p)
                  continue;
            dfs(v.x, u, c+v.y, d+1);
      }
}

int LCA(int u, int v){
      if(depth[u] < depth[v])
            swap(u, v);
      int diff = depth[u] - depth[v];
      for(int i=0; i<LN; i++)
            if((diff>>i)&1)
                  u = parent[i][u];
      if(u==v)
            return u;
      for(int i=LN-1; i>=0; i--){
            if(parent[i][u] != parent[i][v]){
                  u = parent[i][u];
                  v = parent[i][v];
            }
      }
      return parent[0][u];
}

int find(int p, int t) {
      cout<<p<<" "<<t<<"\n";
	int i, stp;
	for(stp = 1; 1<<stp <= depth[p]; stp++);
      stp--;
	for(i = stp; i >= 0; i--)
		if(depth[p] - (1<<i) >= t)
			p = parent[i][p];
	return p;
}

int main()
{
      FASTIO
      cin>>t;
      while(t--){
            cin>>n;
            for(int i=1; i<=n; i++){
                  graph[i].clear();
                  for(int j=0; j<LN; j++)
                        parent[j][i] = -1;
            }
            for(int i=1; i<n; i++){
                  cin>>a>>b>>c;
                  graph[a].pb(pii(b, c));
                  graph[b].pb(pii(a, c));
            }
            dfs(1, -1, 0, 0);
            for(int i=1; i<LN; i++)
                  for(int j=1; j<=n; j++){
                        if(parent[i-1][j] != -1)
                              parent[i][j] = parent[i-1][parent[i-1][j]];
                  }
            while(true){
                  cin>>cmd;
                  if(cmd=="DONE")
                        break;
                  else if(cmd=="DIST"){
                        cin>>a>>b;
                        lca = LCA(a, b);
                        //cout<<a<<" "<<b<<" "<<lca<<"\n";
                        //cout<<dist[a]<<" "<<dist[b]<<" "<<dist[lca]<<"\n";
                        int dlr = dist[a]+dist[b]-2*dist[lca];
                        cout<<dlr<<"\n";
                  }
                  else if(cmd=="KTH"){
                        cin>>a>>b>>c;
                        lca = LCA(a, b);
                        // int dl = depth[a] - depth[lca]+1;
                        // int dr = depth[b] - depth[lca]+1;
                        // int tdist = dl+dr-1;
                        // c = min(tdist, c);
                        // //c = ((c-1)%tdist)+1;
                        // //cout<<a<<" "<<b<<" "<<dl<<" "<<dr<<" "<<c<<" "<<lca<<"\n";
                        if(depth[a]-depth[lca]+1 >= c)
                              cout<<find(a, depth[a]-c+1)<<"\n";
                        else
                              cout<<find(b, 2*depth[lca]+c-depth[a]-1)<<"\n";
                  }
            }
            if(t)
                  cout<<"\n";
      }
      return 0;
}
