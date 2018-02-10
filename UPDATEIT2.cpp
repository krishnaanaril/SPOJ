#include <bits/stdc++.h>

using namespace std;

#define MAX 100005

typedef long long ll;

ll tree[MAX], t, n, u;

ll sum;

void update(int idx, ll val)
{
    while(idx<=n)
    {
        tree[idx]+=val;
        idx+=(idx&-idx);
    }
}

void range_update(int l, int r, ll val)
{
    update(l, val);
    update(r+1, -val);
}

ll getSum(int idx)
{
    sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(idx&-idx);
    }
    return sum;
}

ll getSingle(int idx)
{
    ll sum=tree[idx];
    if(idx>0)
    {
        int f = idx-(idx&-idx);
        idx--;
        while(idx!=f)
        {
            sum-=tree[idx];
            idx-=(idx&-idx);
        }
    }
    return sum;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    ll l, r, val, q, v;
    scanf("%lld", &t);
    while(t--)
    {
        //memset(dat, 0, sizeof(dat));
        memset(tree, 0, sizeof(tree));
        //cin>>n>>u;
        scanf("%lld%lld", &n, &u);
        //cout<<"n & u :"<<n<<" - "<<u<<endl;
        for(int i=0;i<u;i++)
        {
            //cin>>l>>r>>val;
            scanf("%lld%lld%lld", &l, &r, &val);
            range_update(l+1, r+1, val);
        }  
        //cout<<"Updates done..."<<endl;
        //cin>>q;
        for(int i=0;i<n;i++)
            printf("%lld ", tree[i]);
        printf("\n");
        scanf("%lld", &q);     
        for(int i=0;i<q;i++)
        {
            //cin>>v;
            scanf("%lld", &v);
            //cout<<v<<" : ";
            //cout<<(getSum(v+1))<<endl;
            printf("%lld\n", getSum(v+1));
        }
    }
    return   0;
}
