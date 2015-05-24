#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

typedef long long ll;

ll bit1[MAX], bit2[MAX], n, c, l, r, val, ch;
ll sum;

void update(ll* bit, ll idx,ll val)
{
    while(idx<=n)
    {
        bit[idx]+=val;
        idx+=(idx&-idx);
    }
}

// range update for range query
void range_update(ll l, ll r, ll val)
{
    update(bit1, l, val);
    update(bit1, r+1, -val);
    update(bit2, l, val*(l-1));
    update(bit2, r+1, -val*r);
}

ll query2(ll* bit, ll idx)
{
    sum=0;
    while(idx>0)
    {
        sum+=bit[idx];
        idx-=(idx&-idx);
    }
    return sum;
}

ll query(ll idx)
{
    return (query2(bit1, idx)*idx - query2(bit2, idx));
}

ll range_query(ll l, ll r)
{
    return (query(r) - query(l-1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        memset(bit1, 0, sizeof(bit1));
        memset(bit2, 0, sizeof(bit2));
        cin>>n>>c;
        for(int i=0;i<c;i++)
        {
            cin>>ch;
            if(!ch)
            {
                cin>>l>>r>>val;
                range_update(l, r, val);
            }
            else
            {
                cin>>l>>r;
                ll ans = range_query(l, r);
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
