/*
    Name: Krishna Mohan
    Date: 4/26/2015
    Algorithm: String
    Site: Codechef
    Contest: April Lunchtime - 2015  TICKETS5
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
#define INPUTFILE 1

const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;

int main()
{
    #ifndef INPUTFILE
        freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int t, sz, f=0;
    string str;
    cin>>t;
    //cout<<"t: "<<t<<endl;
    while(t--)
    {
        f=0;
        cin>>str;
        sz =str.size();
        //cout<<"sz: "<<sz<<" str: "<<str<<endl;
        if(sz==2)
        {
            if(str[0]==str[1])
                f=1;
        }
        else
        {
            fo(i, sz-2)
            {
                if(str[i] != str[i+2] || str[i]==str[i+1])
                {
                    //printf("%d %c %c %c\n", sz, str[i], str[i+1], str[i+2]);    
                    f=1;
                    break;
                }
            }
        }
        if(f==1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
