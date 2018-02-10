/*
    NICEDAY Code Kata
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX 100009

int tree[MAX];

void update(int idx, int val, int n)
{
    while(idx<=n)
    {
        tree[idx]=min(tree[idx], val);
        idx+=idx&-idx;
    }
}

int read(int idx)
{
    int curr = INT_MAX;
    while(idx>0)
    {
        curr=min(tree[idx], curr);
        idx-=idx&-idx;
    }
    return curr;
}

struct cand
{
    int first, second, third;
};

bool cmp(const cand &a, const cand &b)
{
    return (a.first==b.first)?((a.second==b.second)?(a.third<b.third):(a.second<b.second)):(a.first<b.first);
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        cand dat[n+9];
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d", &dat[i].first, &dat[i].second, &dat[i].third);
        }
        sort(dat, dat+n, cmp);
        fill(tree, tree+n+9, INT_MAX);
        int exc=0;
        for(int i=0;i<n;i++)
        {
            int curr = read(dat[i].second);
            if(curr>dat[i].third)
                exc++;
            update(dat[i].second, dat[i].third, n+9);
        }
        printf("%d\n", exc);
    }
    return 0;
}
