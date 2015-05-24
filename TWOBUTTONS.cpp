/*
    Name: Krishna Mohan
    Date: 3//2015
    Algorithm:
    Site: Codeforces
    Contest: Round 295 Div 2
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

bitset<MAX> isVisited;

int bfs(int n, int m)
{
    int ans=0;
    queue<pi> q;
    isVisited.reset();
    q.push(pi(n, 0));
    while(true)
    {
        int curr=q.front().first;
        isVisited[curr]=1;
        if(curr==m)
            return q.front().second;
        ans=q.front().second;
        q.pop();
        //cout<<"Size: "<<q.size()<<endl;
        //cout<<"Curr: "<<curr<<endl;
        int next=curr-1;
        //cout<<"Next 1: "<<next<<endl;
        if(!isVisited[next] && next>0)
        {
            //cout<<"-1 = "<<next<<endl;
            q.push(pi(next,ans+1));
        }
        next=2*curr;
        //cout<<"Next 2: "<<next<<endl;
        if(!isVisited[next] && next<(2*m))
        {
            //c out<<"2* = "<<next<<endl;
            q.push(pi(next,ans+1));
        }
    }
}


int main()
{
    #ifndef INPUTFILE
        freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int n,m, ans=0;
    cin>>n>>m;
    cout<<bfs(n, m)<<endl;
    return 0;
}
