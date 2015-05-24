/*
    SPOJ: GSS1 & GSS3
    Date: 3/9/2015
    Algorithm: Segment tree, reference zobayer's code
*/
#include <bits/stdc++.h>

using namespace std;

struct Tree{int sum, maxv, lval, rval;};
const int MAX=1<<16; // max value will be 50000 so given as 2^16  - 65536
int dat[MAX];
Tree tree[MAX<<1];

int max2(int a, int b, int c)
{
    return max(a, max(b, c)); 
}

void init(int node, int a, int b)
{
    if(a==b)
    {
        tree[node].sum=tree[node].maxv=tree[node].lval=tree[node].rval=dat[a];
        return;
    }    
    int m=(a+b)/2;
    init(2*node, a, m);
    init(2*node+1, m+1, b);
    tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;
    tree[node].maxv=max2(tree[2*node].maxv, tree[2*node].rval+tree[2*node+1].lval, tree[2*node+1].maxv);
    tree[node].lval=max(tree[2*node].lval, tree[2*node].sum+tree[2*node+1].lval);
    tree[node].rval=max(tree[2*node].rval+tree[2*node+1].sum, tree[2*node+1].rval);
}

void update(int node, int l, int r, int pos, int val)
{
    if(l==r && r==pos)
    {
        tree[node].sum=tree[node].maxv=tree[node].lval=tree[node].rval=val;
        return;
    }
    int m=(l+r)/2;
    if(pos<=m)
        update(2*node, l, m, pos, val);
    else 
        update(2*node+1, m+1, r, pos, val);
    tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;
    tree[node].maxv=max2(tree[2*node].maxv, tree[2*node].rval+tree[2*node+1].lval, tree[2*node+1].maxv);
    tree[node].lval=max(tree[2*node].lval, tree[2*node].sum+tree[2*node+1].lval);
    tree[node].rval=max(tree[2*node].rval+tree[2*node+1].sum, tree[2*node+1].rval);
}

void query(Tree &res, int node, int l, int r, int i, int j)
{
    if(l==i && r==j)
    {
        res=tree[node]; return;
    }
    int m=(l+r)/2;
    if(j<=m) query(res, 2*node, l, m, i, j);
    else if(i>m) query(res,2*node+1, m+1, r, i, j);
    else
    {
        Tree left, right;
        query(left, 2*node, l, m, i, m);
        query(right, 2*node+1, m+1, r, m+1, j);
        res.sum=left.sum+right.sum;
        res.maxv=max2(left.maxv, left.rval+right.lval, right.maxv);
        res.lval=max(left.lval, left.sum+right.lval);
        res.rval=max(left.rval+right.sum, right.rval);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, q, x, y;
    Tree res;
    //cin>>n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        //cin>>dat[i];
        scanf("%d", &dat[i]);
    }
    init(1, 0, n-1);
    //cin>>q;
    scanf("%d", &q);
    for(int i=0;i<q;i++)
    {
        //cin>>x>>y;
        scanf("%d%d", &x, &y);
        query(res, 1, 0, n-1, --x, --y);
        //cout<<res.maxv<<endl;
        printf("%d\n", res.maxv);
    }
    return 0;
}
