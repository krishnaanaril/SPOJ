/*
    HAYBALE using BIT
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001

int tree[MAX], dat[MAX], n, k, x, y;

void update(int idx, int val)
{
    while(idx<=n)
    {
        tree[idx]+=val;
        idx+=idx&-idx;
    }
}

int read(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=idx&-idx;
    }
    return sum;
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i=0;i<k;i++)
    {
        scanf("%d%d", &x, &y);
        update(x, 1);
        update(y+1, -1);
    }
    for(int i=0, j=0;i<=n;i++, j++)
    {
        //tree[i]=tree[i]+tree[i-1];
        //printf("%d ", tree[i]);
        dat[j]=read(i);
    }
    sort(dat, dat+n+1);
    /*for(int i=0;i<=n;i++)
        printf("%d ", dat[i]);
    printf("\n");*/
    printf("%d\n", dat[(n+1)/2]);
}
