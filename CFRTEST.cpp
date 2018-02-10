#include <bits/stdc++.h>

using namespace std;

#define MAX 51

int main()
{
    int t, n, x;
    set<int> dat;
    scanf("%d", &t);
    while(t--)
    {
        dat.clear();
        scanf("%d", &n);
        for(int i=0;i<n;i++)
        {
            scanf("%d", &x);
            dat.insert(x);
        }
        printf("%d\n", dat.size());
    }
    return 0;
}
