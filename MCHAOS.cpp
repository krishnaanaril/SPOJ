/*
    Caused TLE
*/
#include <bits/stdc++.h>

using namespace std;

#define MAX 26
#define MAXN 100005

typedef pair<string, string> pss;
typedef long long ll;
int tree[MAXN];

void update(int idx, int val)
{
    while(idx<=MAXN)
    {
        tree[idx]+=val;
        idx+=idx&-idx;
    }
}

ll read(int idx)
{
    ll sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=idx&-idx;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, sz;
    ll ans;
    string str, rstr;
    vector<pss> dat;
    vector<string> re;
    map<string, int> mp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        rstr=str;
        reverse(rstr.begin(), rstr.end());
        dat.push_back(pss(str, rstr));
        re.push_back(rstr);
        //mp[rstr]=i+1;
    } 
    sort(dat.begin(), dat.end());
    sort(re.begin(), re.end());
    for(int i=0;i<n;i++)
    {
        mp[re[i]]=i+1;
    }
    ans=0;
    for(int i=0;i<n;i++)
    {
        //cout<<dat[i].first<<" "<<dat[i].second<<" "<<mp[dat[i].second]<<endl;
        ans+=read(n)-read(mp[dat[i].second]);
        update(mp[dat[i].second],1);
        //cout<<read(n)-read(mp[dat[i].second])<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
