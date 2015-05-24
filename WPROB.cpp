/*
    Codechef Feb - lunch time
    Problem: WPROB
    Date: 2/23/2015
*/

#include <bits/stdc++.h>

using namespace std;

#define INF 1000000007

typedef long long ll;

const long long INF2=1000000000000000000ll;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, sz, c1, c2, c3;
    ll sum, ans;
    string str;
    char dat[6][3]={{'r','g','b'},{'r','b','g'},{'g','r','b'},{'g','b','r'},{'b','g','r'},{'b','r','g'}};
    cin>>t;
    while(t--)
    {
        cin>>str;
        sz=str.size();
        ans=INF2;
        for(int i=0;i<6;i++)
        {
            sum=c1=c2=c3=0;
            for(int j=0;j<sz;j++)
            {
                if(str[j] == dat[i][0])
                {
                    c1++;
                    sum+=c2+c3;
                }
                else if(str[j] == dat[i][1])
                {                    
                    c2++;
                    sum+=c3;
                }
                else if(str[j] == dat[i][2])
                {
                    c3++;                 
                }
            }
            ans=min(sum, ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
