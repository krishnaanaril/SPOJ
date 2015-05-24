#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll toggleCount(vector<int> &finAns, vector<int> dat, int n, int k)
{
    ll tc=0, cnt=0;
    finAns.clear();
    int prev=dat[0];
    finAns.push_back(prev);
    for(int i=1;i<n;i++)
    {
        if(dat[i]==prev)
        {
            cnt++;
            if(cnt==k)
            {
                tc++;
                if(i<(n-1) && dat[i+1]==(prev^1) && i>1 && finAns[i-2]!=(prev^1))
                {
                    //cout<<i<<" : "<<finAns[i];
                    finAns[i-1]^=1;
                    //cout<<" : "<<finAns[i-1]<<endl;
                    finAns.push_back(dat[i]);
                }
                else
                {
                    prev^=1;
                    finAns.push_back(prev);
                }
                cnt=0;
            }
            else
                finAns.push_back(dat[i]);
        }
        else
        {
            cnt=0;
            prev^=1;
            finAns.push_back(prev);
        }
    }
    return tc;
}

inline void printArray(vector<int> dat, int n)
{
    //cout<<"Array: ";
    for(int i=0;i<n;i++)
    {
        cout<<dat[i];
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, k;
    ll atc, btc;
    vector<int> dat, aAns, bAns;
    string str;
    cin>>t;
    while(t--)
    {
        dat.clear(); aAns.clear(); bAns.clear();
        cin>>n>>k>>str;
        for(int i=0;i<n;i++)
        {
            dat.push_back(str[i]-'0');
        }
        //printArray(dat, n);
        atc=toggleCount(aAns, dat, n, k);
        reverse(dat.begin(), dat.end());
        //printArray(dat, n);
        btc=toggleCount(bAns, dat, n, k);
        //cout<<min(atc, btc)<<endl;
        //cout<<atc<<" : "<<btc<<endl;
        /*printArray(aAns, n);
        reverse(bAns.begin(), bAns.end());
        printArray(bAns, n);*/
        if(atc<=btc)
        {
            cout<<atc<<endl;
            printArray(aAns, n);
        }
        else
        {
            reverse(bAns.begin(), bAns.end());
            cout<<btc<<endl;
            printArray(bAns, n);
        }
    }
    return 0;
}
