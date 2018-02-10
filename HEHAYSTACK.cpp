/*
    Name: Krishna Mohan
    Date: 3/2/2015
    Algorithm:
    Site: Hackerearth
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

#define d 256
#define NMOD 101

string text, pat;
int szt, szp;

bool isFoundPattern()
{
    int p[26], t[26], f=1;
    ini(p, 0);
    ini(t, 0);
    fo(i, szp)
    {
        p[pat[i]-'a']++;
        t[text[i]-'a']++;
    }
    re(i, szp, szt)
    {
        f=1;
        fo(j, 26)
        {
            if(p[j]!=t[j])
            {
                f=0; break;
            }
        }
        if(f)
            return true;
        t[text[i]-'a']++;
        t[text[i-szp]-'a']--;
    }
    f=1;
    fo(j, 26)
    {
        if(p[j]!=t[j])
        {
            f=0; break;
        }
    }
    if(f)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>pat>>text;
        szp=pat.size();
        szt=text.size();
        if(isFoundPattern())
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
