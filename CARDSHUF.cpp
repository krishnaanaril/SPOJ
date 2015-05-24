/*
    Name: Krishna Mohan
    Date: 3/12/2015
    Algorithm: Splay tree
    Site: Codechef
    Contest: CARDSHUF  JAN12  - long
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

class node
{
    public:
        //value, sum, rev
        int id, s, rev;
        // parent left and right
        node *p, *l, *r;
        // constructor
        node(int _id, node *_p)
        {
            id=_id;
            p=_p; 
            s=rev=1;
            l=r=0;       
        }    
};

void set_size(node *n)
{
    n->s=1;
    if(n->l) n->s+=n->l->s;
    if(n->r) n->s+=n->r->s;
}

int get_size(node *n)
{
    if(n==0)
        return 0;
    return n->s;
}

// for push down purposes
void resolve(node *n)
{
    if(n==0) return;
    if(n->rev==-1)
    {
        n->rev=1;
        if(n->l!=0) n->l->rev*=-1;
        if(n->r!=0) n->r->rev*=-1;
        swap(n->l, n->r);
    }
}

void rotate(node *n)
{
    node *p=n->p;
    node *g=p->p;
    resolve(p);
    resolve(g);
    resolve(n);
    if(g!=0)
    {
        if(g->l==p)
        {
            g->l=n;
        }
        else
        {
            g->r=n;
        }
        n->p=g;
    }
    else
        n->p=0;
    if(p->r==n)
    {
        p->r=n->l;
        if(n->l!=0)
            n->l->p=p;
        n->l=p;
    }    
    else
    {
        p->l=n->r;
        if(n->r!=0)
            n->r->p=p;
        n->r=p;
    }
    p->p=n;
    set_size(p);
    set_size(n);
}

void splay(node *n)
{
    while(1)
    {
        node *p=n->p;
        resolve(p);
        if(p==0) break;
        node *g=p->p;
        resolve(g);
        if(g==0) rotate(n);
        else if((g->l==p)==(p->l==n))
        {
            rotate(p);
            rotate(n);
        }
        else
        {
            rotate(n);
            rotate(n);
        }
    }
}

node* merge(node *n1, node *n2)
{
    if(n1==0) return n2;
    if(n2==0) return n1;
    resolve(n2);
    while(n2->l!=0)
    {
        n2=n2->l;
        resolve(n2);
    }
    splay(n2);
    n2->l=n1;
    n1->p=n2;
    set_size(n2);
    return n2;
}

node* detach(node *n, int k)
{
    if(k==0) return 0;
    if(k==n->s)
    {
        node *front =n;
        n=0;
        return front;
    }
    k++;
    resolve(n);
    int s1=get_size(n->l);
    while(s1+1!=k)
    {
        if(s1>=k) n=n->l;
        else
        {
            k-=s1+1;
            n=n->r;
        }
        resolve(n);
        s1=get_size(n->l);
    }
    splay(n);
    node *front =n->l;
    front->p=0;
    n->l=0;
    set_size(n);
    return front;
}

node* build(int n1, int n2)
{
    if(n1>n2) return 0;
    int k=(n1+n2)/2;
    node *n=new node(k,0);
    n->l=build(n1, k-1);
    n->r=build(k+1, n2);
    set_size(n);
    if(n->l) n->l->p=n;
    if(n->r) n->r->p=n;
    return n;
}

void print(node *n)
{
    if(n==0) return;
    resolve(n);
    print(n->l);
    cout<<n->id<<" ";
    print(n->r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, a, b, c;
    cin>>n>>m;
    node *root=build(1, n);
    fo(i, n)
    {
        cin>>a>>b>>c;
        node *top=detach(root, a);
        node *mid=detach(root, b);
        root=merge(top, root);
        top=detach(root, c);
        mid->rev*=-1;
        mid=merge(top, mid);
        root=merge(mid, root);
    }
    print(root);
    cout<<endl;
    return 0;
}
