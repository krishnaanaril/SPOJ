#include <bits/stdc++.h>

using namespace std;

#define MAX 100005
typedef long long ll;

int tree[MAX], strP[MAX], rstrP[MAX], mp[MAX];
string str[MAX], rstr[MAX];
ll ans;

void update(int idx, int val)
{
    idx++;
    while(idx<=MAX)
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

bool cmp1(int x, int y)
{
    return str[x] < str[y];
}

bool cmp2(int x, int y)
{
    return rstr[x] < rstr[y];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    //cout<<n<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
        //cout<<str[i]<<endl;
        rstr[i]=string(str[i].rbegin(), str[i].rend());
        strP[i]=rstrP[i]=i;
    }
    sort(strP, strP+n, cmp1);
    sort(rstrP, rstrP+n, cmp2);
    /*for(int i=0;i<n;i++)
    {
        cout<<str[strP[i]]<<" : "<<rstr[rstrP[i]]<<endl;
    }*/
    for(int i=0;i<n;i++)
    {
        mp[rstrP[i]]=i;
    }
    for(int i=0;i<n;i++)
    {
        update(i, 1);
    }
    ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=read(mp[strP[i]]);
        update(mp[strP[i]], -1);
    }
    cout<<ans<<endl;
    return 0;
}
