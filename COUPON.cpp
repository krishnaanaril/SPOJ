#include <bits/stdc++.h>

using namespace std;

typedef vector<long long> vi;
typedef long long ll;

#define INF 1000000007

int main()
{
    int t, n, m;
    ll tmp;
    vector<vi> price, disc, dp;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        price.clear();
        disc.clear();
        dp.clear();
        price.resize(n);
        disc.resize(n);
        dp.resize(n);
        for(int i=0;i<n;i++)
        {
            price[i].resize(m);
            disc[i].resize(m);
            dp[i].resize(m);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%lld", &price[i][j]);
                //price[i].push_back(tmp);
                //dp[i].push_back(0LL);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%lld", &disc[i][j]);
                //disc[i].push_back(tmp);
            }
        }
        ll minVal = (ll)INF*INF, minPos=-1, currVal, currPos;
        for(int i=0;i<m;i++)
        {
            dp[0][i]=price[0][i];
            minVal=min(dp[0][i], minVal);
        }
        //printf("1. %lld\n", minVal);
        for(int i=1;i<n;i++)
        {
            currVal=(ll)INF*INF;
            for(int j=0;j<m;j++)
            {
                tmp = max(0LL, price[i][j]-disc[i-1][j]);
                dp[i][j]=dp[i-1][j]+tmp;
                dp[i][j]=min(dp[i-1][j]+tmp, minVal+price[i][j]);     
                currVal=min(currVal, dp[i][j]);                          
            }            
            minVal=currVal;
        }
        
        ll ans=(ll)INF*INF;
        for(int i=0;i<m;i++)
        {
            ans=min(ans, dp[n-1][i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
