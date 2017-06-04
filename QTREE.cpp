#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define ROOT 0


typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

const int N = 1e5+5;
const int LOGN = 20;

int t, n, a, b, c;
int depth[N], subsz[N], dat[N]; //dat corresponds to baseArray
int parent[LOGN][N], otherEnd[N];
int segTree[4*N], qTree[4*N];
int chainNo, chainHead[N], posInBase[N], chainInd[N], ptr;
vpi graph[N];
vi indexx[N];

/*
  Building Segment Tree for chains
*/
void build(int node, int l, int r){
  if(l==r-1){
        segTree[node] = dat[l];
        return;
  }
  int mid = (l+r)>>1;
  build(2*node, l, mid);
  build(2*node+1, mid, r);
  segTree[node] = max(segTree[2*node], segTree[2*node+1]);
}

void update_tree(int node, int l, int r, int pos, int val){
  if(l>pos || r<=pos)
        return;
  if(l==pos && l==r-1){
        segTree[node] = val;
        return;
  }
  int mid = (l+r)>>1;
  if(pos < mid)
        update_tree(2*node, l, mid, pos, val);
  else
        update_tree(2*node+1, mid, r, pos, val);
  segTree[node] = max(segTree[2*node], segTree[2*node+1]);
}

/*
 * query_tree:
 * Given ql and qr, it will return the maximum value in the range [ql,qr)
 */
void query_tree(int node, int l, int r, int ql, int qr){
  if(l>=qr || r <=ql){
        qTree[node] = -1;
        return ;
  }
  if(l>=ql && r<=qr){
        qTree[node] = segTree[node];
        return;
  }
  int mid = (l+r)>>1;
  query_tree(2*node, l, mid, ql, qr);
  query_tree(2*node+1, mid, r, ql, qr);
  qTree[node] = max(qTree[2*node], qTree[2*node+1]);
}

int query_up(int u, int v){
  if(u==v)
        return 0;
  int ans = -1, uchain, vchain = chainInd[v];
  while(true){
        uchain = chainInd[u];
        if(uchain == vchain){
              if(u==v)
                    break;
              query_tree(1, 0, ptr, posInBase[v]+1, posInBase[u]+1);
              ans = max(qTree[1], ans);
              break;
        }
        query_tree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]+1);
        ans = max(qTree[1], ans);
        u = chainHead[uchain];
        u = parent[0][u];
  }
  return ans;
}

int LCA(int u, int v){
  if(depth[u] < depth[v])
        swap(u, v);
  int diff = depth[u] - depth[v];
  for(int i=0; i<LOGN; i++){
        if((diff>>i)&1)
              u = parent[i][u];
  }
  if(u==v)
        return u;
  for(int i=LOGN-1; i>=0; i--){
        if(parent[i][u] != parent[i][v]){
              u = parent[i][u];
              v = parent[i][v];
        }
  }
  return parent[0][u];
}

void query(int u, int v){
  int lca = LCA(u, v);
  int ans = query_up(u, lca);
  int tmp = query_up(v, lca);
  ans =  max(ans, tmp);
  cout<<ans<<"\n";
}

/*
 * change:
 * We just need to find its position in segment tree and update it
 */
void change(int pos, int val){
  int u = otherEnd[pos];
  update_tree(1, 0, ptr, posInBase[u], val);
}

/*
  HL-Decomposition part
*/
void HLD(int node, int cost, int prev){
  if(chainHead[chainNo]==-1)
        chainHead[chainNo] = node;
  chainInd[node] = chainNo;
  posInBase[node] = ptr;
  dat[ptr++] = cost;

  int sc = -1, ncost;
  for(pii v : graph[node]){
        if(v.F==prev)
              continue;
        if(sc==-1 || subsz[sc] < subsz[v.F]){
              sc = v.F;
              ncost = v.S;
        }
  }

  if(sc != -1)
        HLD(sc, ncost, node);

  for(pii v : graph[node]){
        if(v.F==prev)
              continue;
        if(v.F==sc)
              continue;
        chainNo++;
        HLD(v.F, v.S, node);
  }
}

/*
  DFS is used to set parent of nodes, subtree size and depth of each node
*/
void dfs(int u, int prev, int dep= 0){
  parent[0][u] = prev;
  depth[u] = dep;
  subsz[u] = 1;
  int i=-1;
  for(pii v : graph[u]){
        i++;
        if(v.F==prev)
              continue;
        otherEnd[indexx[u][i]] = v.F;
        dfs(v.F, u, dep+1);
        subsz[u] += subsz[v.F];
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin>>t;
  while(t--){
        ptr=0;
        cin>>n;
        for(int i=0; i<n; i++){
              graph[i].clear();
              indexx[i].clear();
              chainHead[i] = -1;
              for(int j=0; j<LOGN; j++)
                    parent[j][i] = -1;
        }
        for(int i=0; i<n-1; i++){
              cin>>a>>b>>c;
              --a; --b;
              indexx[a].push_back(i);
              indexx[b].push_back(i);
              graph[a].push_back(pii(b, c));
              graph[b].push_back(pii(a, c));
        }
        dfs(ROOT, -1);
        HLD(ROOT, -1, -1);
        build(1, 0, ptr);
        /*for(int i=0; i<10; i++)
              cout<<segTree[i]<<" ";
        cout<<"\n";*/
        for(int j=1; j<LOGN; j++){
              for(int i=0; i<n; i++)
                    if(parent[j-1][i] != -1)
                          parent[j][i] = parent[j-1][parent[j-1][i]];
        }
        while(true){
              string cmd;
              cin>>cmd;
              if(cmd=="DONE")
                    break;
              if(cmd=="QUERY"){
                    cin>>a>>b;
                    --a; --b;
                    query(a, b);
              }
              else if (cmd=="CHANGE"){
                    cin>>a>>b;
                    --a;
                    change(a, b);
              }
        }
  }
  return 0;
} 
