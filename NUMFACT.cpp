/*
    Codechef: NUMFACT
    Date: 1/21/2015
*/

#include <bits/stdc++.h>
#define MAX 1000007

using namespace std;

bitset<MAX> isPrime;

void init()
{
    isPrime.set();
    isPrime[0]=isPrime[1]=0;
    int lim=sqrt(MAX);
    for(int i=2;i<=lim;i++)
    {
        if(isPrime[i])
        {
            for(int j=2; i*j<MAX;j++)
            {
                isPrime[i*j]=0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, temp, lim;
    long long ans;
    init();
    vector<int> dat;
    map<int, int> pcount;
    //cout<<isPrime[8]<<" : "<<isPrime[13]<<endl;
    cin>>t;
    while(t--)
    {
        ans=1;
        dat.clear();
        pcount.clear();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            if(isPrime[temp])
            {
                pcount[temp]++;
            }
            else
            {
                lim=sqrt(temp);
                for(int j=2;j<=temp;j++)
                {
                    if(isPrime[j])
                    {
                        while(temp%j==0)
                        {
                            pcount[j]++;
                            temp/=j;
                            /*if(isPrime[temp])
                            {
                                pcount[temp]++;
                            } */                           
                        }
                    }
                }
            }
            dat.push_back(temp);
        }
        for(map<int, int>::iterator it=pcount.begin(); it!=pcount.end(); it++)
        {
            //cout<<it->first<<" : "<<it->second<<endl;
            ans*=(it->second+1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
