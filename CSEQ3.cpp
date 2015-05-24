#include <bits/stdc++.h>

using namespace std;

#define MAX 105
#define MOD 1000003

typedef unsigned long long ull;

int main()
{
    int t, n, l, r, dat[MAX][MAX], cnt;
    ull arr[MAX];
    cin>>t;
    while(t--)
    {
        cin>>n>>l>>r;
        /*cnt=0;
        for(int i=0;i<MAX;i++)
            dat[0][i]=0;
        int len=1;
        for(int i=1;i<=n;i++)
        {
            int m=0;
            for(int k=0;k<len;k++)
            {
                
                for(int j=l, jc=0;j<=r;j++)
                {
                    if(j>=dat[i-1][k]%10)
                    {
                        dat[i][m]=dat[i-1][k]*10+j;
                        cout<<dat[i][m]<<endl;
                        cnt++;
                        m++;
                        jc++;
                    }
                    //cout<<j<<" count: "<<jc<<endl;
                }
            }
            len=m;
            cout<<"Length "<<i<<" count:"<<m<<endl;
        }
        cout<<"Ans 1: "<<cnt<<endl;*/
        ull k=r-l+1;
        ull sum=k;
        for(int i=0;i<k;i++)
            arr[i]=i+1;
        
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<k;j++)
            {
                arr[j]+=arr[j-1];
            }
            /*for(int j=0;j<k;j++)
            {
                cout<<arr[j]<<" "; 
            }
            cout<<endl;
            cout<<"count: "<<arr[k-1]<<endl;
            cout<<"Sum: "<<sum<<endl;*/
            sum=(sum+arr[k-1])%MOD;
        }      
        cout<<sum<<endl; 
    }
    return 0;    
}
