#include <bits/stdc++.h>

using namespace std;

#define MAX 1001

int dat[MAX][MAX], tree[MAX][MAX];
int n, m, q, x, y;

void update(int n, int idx, int val)
{
    while(idx<=MAX)
    {
        tree[n][idx]+=val;
        idx+=idx&-idx;
    }
}

int read(int n, int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[n][idx];
        idx-=idx&-idx;
    }
    return sum;
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d", &dat[i][j]);
            if(dat[i][j])
                update(i, j, 1);
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%d ", tree[i][j]);
        }
        printf("\n");
    }*/
    //printf("TR->%d\n", read(1, 4));
    for(int i=1; i<=q;i++)
    {
        scanf("%d%d", &x, &y);
        if(dat[x][y])
        {
            update(x, y, -1);
        }
        else
        {
            update(x, y, 1);
        }
        dat[x][y]^=1;
        int maxVal=-1;
        for(int i=1;i<=n;i++)
        {
            //printf("->%d\n", read(i, m));
            maxVal=max(maxVal, read(i, m));
        }
        printf("%d\n", maxVal);
    }
    return 0;
}
