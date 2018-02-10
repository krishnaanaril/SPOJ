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
//#define MAX 100
#define INF 1000000007
#define MOD 1000000007

#define N 1000000
#define MAX (1+(1<<8)) // Why? :D
#define inf 0x7fffffff
 
int arr[N];
int tree[MAX]; 

/**
* Build and init tree
*/
void build_tree(int node, int a, int b) {
    if(a > b) return; // Out of range
    if(a == b) { // Leaf node
    tree[node] = arr[a]; // Init value
    return;
    }
    build_tree(node*2, a, (a+b)/2); // Init left child
    build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
    tree[node] = max(tree[node*2], tree[node*2+1]); // Init root value
}
 
/**
* Increment elements within range [i, j] with value value
*/
void update_tree(int node, int a, int b, int i, int j, int value) {
    if(a > b || a > j || b < i) // Current segment is not within range [i, j]
    return;
    if(a == b) { // Leaf node
        tree[node] += value;
        return;
    }
 
    update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child
     
    tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
} 

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, x, y;
    ini(arr, 0);
    cin>>n>>m;
	build_tree(1, 0, n-1);
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        update_tree(1, 0, n-1, x, y, 1); // Increment range [0, 6] by 5     
    }
    fo(i, n)
    {   
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    return 0;
}
