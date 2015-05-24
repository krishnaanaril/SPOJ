#include <bits/stdc++.h>

using namespace std;

#define MAX 1001

int n, m, dat[MAX][MAX], q, x;

int binarySearch(int pos, int x, bool isRow)
{
    int beg, end, mid;
    if(isRow)
    {
        beg=0, end=m;       
        while(beg<=end)
        {
            mid=(beg+end)/2;
            if(dat[pos][mid]==x)
                return mid;            
            if(x<dat[pos][mid])
                end=mid-1;
            else
                beg=mid+1;
        }
    }
    else
    {
        beg=0, end=n;       
        while(beg<=end)
        {
            mid=(beg+end)/2;
            if(dat[mid][pos]==x)
                return mid;            
            if(x<dat[mid][pos])
                end=mid-1;
            else
                beg=mid+1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>dat[i][j];
        }
    }
    cin>>q;
    while(q--)
    {
        cin>>x;
        int r=binarySearch(0, x, true);
        int c=binarySearch(0, x, false);
    }
    return 0;
}
