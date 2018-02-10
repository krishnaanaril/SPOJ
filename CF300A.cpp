/*
    Name: Krishna Mohan
    Date: 4/26/2015
    Algorithm:
    Site: Codeforces
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
    string a = "CODEFORCES", b;
    
    cin>>b;
    int sza = a.size(), szb = b.size(), f=0;
    if(szb>sza)
    {             
        rep(i, 0, sza)
        {
            //cout<<a.substr(0, i+1)<<" , "<<a.substr(i+1)<<endl;
            /*int posa = b.find(a.substr(0, i+1));
            int posb = b.find(a.substr(i+1));*/
            //cout<<b.substr(0, i)<<" + "<<b.substr(szb-(sza-i))<<endl;
            if(b.substr(0, i)+b.substr(szb-(sza-i))==a)
            {
                f=1;
                break;
            }
            //cout<<abc<<endl;
            /*if(posa!=string::npos && posb!=string::npos && posa+i<posb)
            {
                f=1;
                break;
            } */   
        }
    }
    if(f==1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    //}
    return 0;
}