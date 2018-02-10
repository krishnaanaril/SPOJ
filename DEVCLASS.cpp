/*
    Name: Krishna Mohan
    Date: 3/22/2015
    Algorithm:
    Site: CODECHEF
    Contest: MARCH LONG  - DEVCLASS
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
#define MAX 100007
#define INF INT_MAX
#define MOD 1000000007

const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;

int a[MAX];

int countChar(string str, char ch)
{
    int cnt=0, sz=str.size();
    for(int i=0;i<sz;i++)
        if(str[i]==ch)
            cnt++;
    return cnt;
}

int countCase0(string str, string t)
{
    int sz=str.size();
    int cnt=0;
    fo(i, sz)
    {
        if(str[i]!=t[i])
            cnt++;
    }
    return cnt/2;
}

int countCase1(string str, string t)
{
    int cntEq=0, cntNeq=0, ans=0, sz=str.size();
    fo(i, sz)
    {
        if(str[i]==t[0])
        {
            ans+=abs(i-2*cntEq);
            cntEq++;
        }    
        else
        {
            ans+=abs(i-(2*cntNeq+1));
            cntNeq++;
        }
    }
    //cout<<str<<"->"<<t<<"->"<<(ans/2)<<endl;
    return ans/2;
}

int countCase2(string str, string t)
{   
    int sz=str.size();
    int curr=0, ans=0;
    fo(i, sz)
    {
        if(str[i]!=t[i] && str[i]=='B' && t[i]=='G')
            a[i]=1;
        else if(str[i]!=t[i] && str[i]=='G' && t[i]=='B')
            a[i]=-1;
        else if(str[i]==t[i])
            a[i]=0;            
    }
    fo(i, sz)
    {
        curr+=a[i];
        ans+=abs(curr);
    }
    return ans;
}

int solveCase(string str, int type, char ch)
{
    //cout<<"Case: "<<ch<<endl;
    string t="";
    int sz=str.size();
    if(ch=='G')
    {
        fo(i, sz)
        {
            if(i&1)
                t+='B';
            else
                t+='G';
        }
    }
    else
    {
        fo(i, sz)
        {
            if(i&1)
                t+='G';
            else
                t+='B';
        }
    }
    if(countChar(str, 'G')!=countChar(t, 'G'))
        return INF;
    //cout<<str<<" : "<<t<<endl;
    if(type==0)
        return countCase0(str, t);
    return countCase2(str, t);
}

int solve(string str, int type)
{
    int res=min(solveCase(str, type, 'G'), solveCase(str, type, 'B'));
    if(res==INF)
        return -1;
    return res;
} 

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>n>>str;
        cout<<solve(str, n)<<endl;
    }
    return 0;
}
