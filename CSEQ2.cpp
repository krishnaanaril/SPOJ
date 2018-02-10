#include <bits/stdc++.h>

using namespace std;

#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fo(i,n)     re(i,0,n)
#define MOD 1000003

typedef unsigned long long ull;

int main()
{
    int t, n, l, r, k;
    ull sum, tsum;
    cin>>t;
    while(t--)
    {
        cin>>n>>l>>r;
        //cout<<n<<" : "<<l<<" : "<<r<<endl;
        k=r-l+1;
        sum=tsum=0;
        fo(i, n)
        {
            if(i==0)
                sum+=k;
            else
            {
                tsum=((1LL)*(k+i-1)*(k+i)/2)%MOD;
                //cout<<"tsum: "<<tsum<<endl;
                sum = (sum+ tsum)%MOD;
            }
            //cout<<"i: "<<i<<endl;
        }
        cout<<sum<<endl;
    }
    return 0;
}
