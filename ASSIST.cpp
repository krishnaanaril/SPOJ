/*
    Couldn't solve it the first time, thought of asking the first N prime numbers
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX 34000
#define MAXN 5001

bitset<MAX> isLucky;
int ans[MAXN];

void init()
{
    int cnt, j=0;
    isLucky.set();
    isLucky[0]=isLucky[1]=false;
    for(int i=2;i<MAX;i++)
    {
        if(isLucky[i])
        {
            //printf("%d ", i);
            ans[j++]=i;
            cnt=0;
            for(int k=i+1;k<MAX;k++)
            {
                if(isLucky[k])
                {
                    cnt++;
                    if(cnt==i)
                    {
                        isLucky[k]=false;
                        cnt=0;
                    }
                }
            }
        }
    }
}

int main()
{
    init();
    int n;
    while(true)
    {
        scanf("%d", &n);
        if(n==0)
            break;
        printf("%d\n", ans[n-1]);
    }
    return 0;
}

