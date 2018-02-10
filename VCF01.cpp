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

int main()
{
    ios_base::sync_with_stdio(0);
    string str;
    int b, w;
    b=w=0;
    fo(i,8)
    {
        cin>>str;
        fo(j,8)
        {
            switch(str[j])
            {
                case 'Q':
                    w+=9;
                    break;
                case 'R':
                    w+=5;
                    break;
                case 'B':
                    w+=3;
                    break;
                case 'N':
                    w+=3;
                    break;
                case 'P':
                    w+=1;
                    break;
                case 'q':
                    b+=9;
                    break;
                case 'r':
                    b+=5;
                    break;
                case 'b':
                    b+=3;
                    break;
                case 'n':
                    b+=3;
                    break;
                case 'p':
                    b+=1;
                    break;
            }
        }
    }
    //cout<<b<<" : "<<w<<endl;
    if(b<w)
    {
        cout<<"White"<<endl;
    }
    else if(b>w)
    {
        cout<<"Black"<<endl;
    }
    else
    {
        cout<<"Draw"<<endl;
    }
    return 0;
}
