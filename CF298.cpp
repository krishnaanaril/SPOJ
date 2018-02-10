/*
    Name: Krishna Mohan
    Date: 4/12/2015
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
    int n, d;
    //cin>>n;
    for(n=1;n<=5000;n++)
    {
        d=ceil(n/2.0);
        if(n==1)
            cout<<"1"<<endl<<"1"<<endl;
        else if(n==2)
            cout<<"1"<<endl<<"1"<<endl;
        else if(n==3)
            cout<<"2"<<endl<<"1 3"<<endl;
        else if(n==4)
            cout<<"3"<<endl<<"4 1 3"<<endl;
        else
        {
            //cout<<n<<endl;
            vector<int> dat;
            for(int i=1;i<=d;i++)
            {
                if(i==d && n&1!=0)
                {    
                    //cout<<i<<" ";
                    dat.push_back(i);
                }
                else           
                {    
                    //cout<<i<<" "<<(i+d)<<" ";
                    dat.push_back(i);
                    dat.push_back(i+d);           
                }
                
            }
            cout<<dat.size();
            if(n!=dat.size())
            {
                cout<<n<<"Haha"<<endl;
            }
            for(int i=0;i<dat.size()-1;i++)
            {
                if(dat[i+1]-dat[i]==1)
                {
                    cout<<n<<endl;
                    return 0;
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
