#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

#define LIM 10000001
#define MAX 100001

int fact[LIM];

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    ull temp, sum1=0, buf1=0, buf2=0, sum=0;
    vector<ull> dat;
    cin>>n>>m;
    fact[0]=1;
    for(int i=1;i<=m;i++)
    {
        fact[i]=(1LL*fact[i-1]*i)%m;
        //cout<<i<<", "<<fact[i]<<endl;
    }
    //cout<<fact[5]<<endl;
    for(int i=0;i<n;i++)
    {
        sum1=0;
        cin>>temp;
        int l=m<temp?m:temp;
        for(int j=1;j<=l;j++)
        {
            sum1+=((1LL*j*(fact[j]+j))%m);
            sum1%=m;
        }
        buf1=(temp*(temp+1)*(2*temp+1))/6;
        if(m<temp)
        {
            buf2=(m*(m+1)*(2*m+1))/6;
            buf1-=buf2;           
            sum1=(sum1+buf1)%m;
        }
        
        //cout<<"SUM1: "<<sum1<<endl;
        sum=(sum+sum1)%m;
    }
    cout<<sum<<endl;
    return 0;
}
