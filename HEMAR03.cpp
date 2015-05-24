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
typedef pair<int,int> pii;
typedef vector<string> vs;
typedef vector<pii> vpii;

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

map<char, pii> dat;

void init()
{
    dat['.']=pii(1,1);
    dat[',']=pii(1,2);
    dat['?']=pii(1,3);
    dat['!']=pii(1,4);
    dat['1']=pii(1,5);
    
    dat['a']=pii(2,1);
    dat['b']=pii(2,2);
    dat['c']=pii(2,3);
    dat['2']=pii(2,4);
    
    dat['d']=pii(3,1);
    dat['e']=pii(3,2);
    dat['f']=pii(3,3);
    dat['3']=pii(3,4);
    
    dat['g']=pii(4,1);
    dat['h']=pii(4,2);
    dat['i']=pii(4,3);
    dat['4']=pii(4,4);
    
    dat['j']=pii(5,1);
    dat['k']=pii(5,2);
    dat['l']=pii(5,3);
    dat['5']=pii(5,4);
    
    dat['m']=pii(6,1);
    dat['n']=pii(6,2);
    dat['o']=pii(6,3);
    dat['6']=pii(6,4);
    
    dat['p']=pii(7,1);
    dat['q']=pii(7,2);
    dat['r']=pii(7,3);
    dat['s']=pii(7,4);
    dat['7']=pii(7,5);
    
    dat['t']=pii(8,1);
    dat['u']=pii(8,2);
    dat['v']=pii(8,3);
    dat['8']=pii(8,4);
    
    dat['w']=pii(9,1);
    dat['x']=pii(9,2);
    dat['y']=pii(9,3);
    dat['z']=pii(9,4);
    dat['9']=pii(9,5);
    
    dat['0']=pii(0,2);
    dat['_']=pii(0,1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    init();
    int t, sz, pre;
    string str;
    ll ans;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>str;
        sz=str.size();
        pre=1;
        for(int i=0;i<sz;i++)
        {
            if(dat[str[i]].first!=pre) 
            {   
                ans++;
                pre=dat[str[i]].first;
            }
            ans+=dat[str[i]].second;
            //cout<<ans<<" ";
        }
        //cout<<endl;
        cout<<ans<<endl;
    }   
    return 0;
}
