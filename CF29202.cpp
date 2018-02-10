#include <bits/stdc++.h>

using namespace std;

#define MAX 101

int b[MAX], g[MAX];

int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, x, y, g, tmp, lim, cnt=0;
    cin>>n>>m;
    g=gcd(n, m);
    cin>>x;
    for(int i=0;i<x;i++)
    {
        cin>>tmp;
        b[tmp%g]=1;   
    }
    cin>>y;
    for(int i=0;i<y;i++)
    {
        cin>>tmp;
        b[tmp%g]=1;
    }
    for(int i=0;i<g;i++)
    {
        if(!b[i])
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
} 
