#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX 1000001

int n;
ll dat[MAX];

void update(int idx, int val)
{
    while(idx<=n)
    {
        //printf("%d ", idx);
        dat[idx]+=val;
        idx+=idx&-idx;
    }
    //printf("\n");
}

ll read(int idx)
{
    ll sum=0;
    while(idx>0)
    {
        sum+=dat[idx];
        idx-=idx&-idx;
    }
    return sum;
}

ll getSingle(int idx)
{
    ll sum=dat[idx];
    if(idx>0)
    {
        int z = idx-(idx&-idx);
        idx--;
        while(idx!=z)
        {
            sum-=dat[idx];
            idx-=idx&-idx;
        }
    }
    return sum;
}

int main()
{
    int m, c, u, v, k, p;
    char s;
    scanf("%d%d%d", &n, &m, &c);
    //printf("%d %d %d",n, m, c);
    /*for(int i=1;i<=n;i++)
    {
        update(i, c);
    }*/
    for(int i=1;i<=m;i++)
    {
        //s=getchar();
        scanf(" %c", &s);
        //printf("%c ..\n", s);
        if(s=='Q')
        {
            scanf("%d", &p);
            printf("%lld\n", read(p)+c);
            //cout<<read(p)-read(p-1)<<endl;
        }
        else
        {
            scanf("%d%d%d", &u, &v, &k);
            update(u, k);
            update(v+1, -k);
            /*for(int i=0;i<=n;i++)
            {
                printf("%lld ", dat[i]);
            }
            printf("\n");*/
        }
    }
    return 0;
}
