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
#define MAX 100
#define INF 1000000007
#define MOD 1000000007

bool isFunny(string a)
{
    int sz=a.size();
    for(int i=1, j=sz-2;i<sz;i++, j--)
    {
        //cout<<a[i]<<" : "<<a[i-1]<<" : "<<a[j]<<" : "<<a[j+1]<<" = "<<abs(a[i]-a[i-1])<<" : "<<abs(a[j]-a[j+1])<<endl;
        if(abs(a[i]-a[i-1])!=abs(a[j]-a[j+1]))
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    string str;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>str;
        if(isFunny(str))
        {
            cout<<"Funny"<<endl;
        }
        else
        {
            cout<<"Not Funny"<<endl;
        }
    }
    return 0;
}
