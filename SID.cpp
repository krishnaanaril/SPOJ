/*
    Same kind a problem as that of ORDERSET
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001

struct data
{
    char ch;
    int x, pos, hash;
};

data sortedQuery[MAX], query[MAX];
int tree[MAX], relPos[MAX], n, m;
bitset<MAX> isPresent;

bool cmp(const data &a, const data &b)
{
    return a.x==b.x? a.pos<b.pos: a.x<b.x;
}

void update(int idx, int val)
{
    while(idx<=MAX)
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
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;i++)
    {
        sortedQuery[i].ch='I';
        sortedQuery[i].pos=i+1;
        scanf("%d", &sortedQuery[i].x);
    }
    for(int i=n;i<n+m;i++)
    {
        scanf(" %c%d", &sortedQuery[i].ch, &sortedQuery[i].x);
        sortedQuery[i].pos=i+1;
    }
    int sz=n+m;
    sort(sortedQuery, sortedQuery+sz, cmp);
    /*for(int i=0;i<sz;i++)
    {
        printf("%c %d\n", sortedQuery[i].ch, sortedQuery[i].x);
    }*/
    int cnt=1, prev=sortedQuery[0].x;
    sortedQuery[0].hash=cnt;
    relPos[cnt]=sortedQuery[0].x;
    for(int i=1;i<=sz;i++)
    {
        if(prev!=sortedQuery[i].x)
        {
            prev=sortedQuery[i].x;
            cnt++;
            sortedQuery[i].hash=cnt;
            relPos[cnt]=sortedQuery[i].x;
        }
        else
            sortedQuery[i].hash=cnt;
    }
    for(int i=0;i<sz;i++)
    {
        query[sortedQuery[i].pos]=sortedQuery[i];
    }
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(query[i].ch=='I')
        {
            cnt++;
            update(query[i].hash, 1);   
        }
    }
    printf("Tree: ");
    for(int j=0;j<=sz;j++)
    {
        printf("%d ", tree[j]);
    }
    printf("\n");
    for(int i=n+1;i<=sz;i++)
    {
        printf("%c %d %d\n", query[i].ch, query[i].x, query[i].hash);
        switch(query[i].ch)
        {
            case 'I':
                
                break;
            case 'D':
                break;
            case 'S':
                printf("S: %d\n", read(query[i].hash-1));
                break;
        };
    }
    return 0;
}
