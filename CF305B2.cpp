#include <bits/stdc++.h>

using namespace std;

#define MAX 1001

int dat[MAX][MAX], ans[MAX];
int n, m, q, x, y;

inline int getCount(int x)
{
    int cnt,maxVal=-1;
    if(dat[x][1])
        cnt=1;
    else
        cnt=0;
    for(int i=2;i<=m;i++)
    {
        if(dat[x][i]&1)
            cnt++;
        else
        {
            maxVal=max(cnt, maxVal);
            cnt=0;
        }
    }
    maxVal=max(cnt, maxVal);
    return maxVal;
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d", &dat[i][j]);            
        }
        ans[i]=getCount(i);
    }
    /*for(int i=0;i<=n;i++)
        printf("%d ", ans[i]);
    printf("\n");*/
    for(int i=1; i<=q;i++)
    {
        scanf("%d%d", &x, &y);
        dat[x][y]^=1;
        ans[x]=getCount(x);
        int fin=-1;
        for(int j=1;j<=n;j++)
        {
            fin=max(ans[j], fin);
        }
        printf("%d\n", fin);  
    }
    return 0;
}
