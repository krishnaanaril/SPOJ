/*

*/
#include <bits/stdc++.h>

using namespace std;

#define MAX 20001

int ans[MAX];

int main()
{
    int t, n, curr, pos, cnt, i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        memset(ans, -1, sizeof(ans));
        ans[2]=1;
        curr=2;
        pos=2;
        while(curr<=n)
        {
            int left = n-curr+1;
            left=curr%left+1;
            cnt=0;
            for(i=pos;;i++)
            {
                if(i>n) 
                    i=1;
                if(ans[i]==-1)
                    cnt++;
                if(cnt==left)
                    break;
            }
            ans[i]=curr;
            pos=i;
            curr++;
        }
        for(int i=1;i<=n;i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}
