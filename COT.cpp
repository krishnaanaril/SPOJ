/*
	Swamy Saranam

	Date	: 13/01/2018 12:34:56
	Author	: Krishna Mohan A M
	Problem	:
	Status	:
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pll;

#define FASTIO                ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b)            for(int i=(a);i<(b);i++)
#define REP(i,n)              FOR(i,0,n)
#define SORT(v)               sort((v).begin(),(v).end())
#define UN(v)                 SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)               memset(a,b,sizeof a)
#define PB                    push_back
#define F                     first
#define S                     second

const int MOD = 1000000007;
const int N = 2e5+5;
const int LOGN = 20;
int n, m, a, b, k, sz, depth[N], parent[LOGN][N];
vector<int> graph[N];
vector<int> val;
map<int, int> mp, rmp;
map<int, int>::iterator it;

struct Node{
      int cnt;
      Node *left, *right;
      Node(int cnt, Node *left, Node *right): cnt(cnt), left(left), right(right){

      }
      Node* insert(int l, int r, int w);
};

Node *base = new Node(0, NULL, NULL);
Node *root[N];

Node* Node::insert(int l, int r, int w){
      if(l<=w && w<     r){
            if(l+1==r){
                  return new Node(this->cnt+1, base, base);
            }
            int mid = (l+r)>>1;
            return new Node(this->cnt+1, this->left->insert(l, mid, w), this->right->insert(mid, r, w));
      }
      //out of range and we can make use of previous tree
      return this;
}

void dfs(int u, int p){
      parent[0][u] = p;
      depth[u] = (p==-1? 0 : depth[p]+1);
      root[u] = (p==-1 ? base : root[p])->insert(0, sz, mp[val[u]]);
      REP(i, graph[u].size()){
            int v = graph[u][i];
            if(v==p)
                  continue;
            dfs(v, u);
      }
}

inline int LCA(int u, int v){
      if(depth[u]< depth[v])
            swap(u, v);
      int diff = depth[u] - depth[v];
      REP(i, LOGN){
            if((diff>>i)&1)
                  u = parent[i][u];
      }
      if(u!=v){
            for(int i=LOGN-1; i>=0; i--){
                  if(parent[i][u] != parent[i][v]){
                        u = parent[i][u];
                        v = parent[i][v];
                  }
            }
            u = parent[0][u];
      }
      return u;
}

int query(Node *a, Node *b, Node *c, Node *d, int l, int r, int cur){
      if(l+1==r)
            return l;
      int sum = a->left->cnt + b->left->cnt - c->left->cnt - d->left->cnt;
      int mid = (l+r)>>1;
      if(sum>=cur)
            return query(a->left, b->left, c->left, d->left, l, mid, cur);
      return query(a->right, b->right, c->right, d->right, mid, r, cur-sum);
}

int main()
{
      FASTIO
      CL(parent, -1);
      base->left = base->right = base;
      cin>>n>>m;
      REP(i, n){
            cin>>a;
            val.PB(a);
            mp[a] = 1;
      }
      sz = 0;
      for(it= mp.begin(); it!=mp.end(); it++){
            mp[it->F] = sz;
            rmp[sz] = it->F;
            sz++;
      }
      // cout<<sz<<"\n";
      REP(i, n-1){
            cin>>a>>b;
            --a; --b;
            graph[a].PB(b);
            graph[b].PB(a);
      }
      dfs(0, -1);
      REP(i, LOGN){
            REP(j, n){
                  if(parent[i][j] != -1){
                        parent[i+1][j] = parent[i][parent[i][j]];
                  }
            }
      }
      REP(i, m){
            cin>>a>>b>>k;
            --a; --b;
            int lca = LCA(a, b);
            int pos = query(root[a], root[b], root[lca], (parent[0][lca]==-1 ? base : root[parent[0][lca]]), 0, sz, k);
            cout<<rmp[pos]<<"\n";
      }
      return 0;
}
