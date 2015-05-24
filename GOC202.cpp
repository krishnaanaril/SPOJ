#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef unsigned long long ull;

int main()
{
    int t, n, sq, tmp;
    ull sum, tmp2;
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>n;
        sq=sqrt(n);
        for(int i=2;i<=sq;i++)
        {
            tmp=n/i;
            if(n%i==0)
            {
                tmp2=(tmp*i)%MOD;
                sum = (sum+tmp2)%MOD;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
