#include <bits/stdc++.h>

using namespace std;

#define MAX 2001

char str[MAX];
int k, n, sz, beg, end;

inline bool isPalin(int b, int e)
{
    if(b==e)
        return true;
    else
    {
        while(b<e)
        {
            if(str[b]!=str[e])
                return false;
            b++;
            e--;
        }
        return true;
    }
}

int main()
{
    scanf("%s%d", str, &k);
    sz=strlen(str);
    n=sz/k;
    if(sz%k!=0)
    {
        printf("NO\n");
    }   
    else
    {
        beg=0; end=n-1;
        int f=0;
        while(beg<sz)
        {
            //printf("->%d  %d\n", beg, end);
            if(!isPalin(beg, end))
            {
                f=1;
                break;
            }
            beg=end+1;
            end+=n;
        }       
        if(!f)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
