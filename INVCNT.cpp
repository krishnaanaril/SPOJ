#include <bits/stdc++.h>

using namespace std;

#define MAX 200001
typedef long long ll;

int arr[MAX], tmp[MAX];

ll merge(int left, int mid, int right)
{
    ll count =0;
    int i=left, j=left, k=mid;
    while(j<=mid-1 && k<=right)
    {
        if(arr[j]<=arr[k])
        {
            tmp[i++]=arr[j++];
        }
        else
        {
            tmp[i++]=arr[k++];
            count+=(mid-j);
        }
    }
    while(j<=mid-1)
    {
        tmp[i++]=arr[j++];
    }
    while(k<=right)
    {
        tmp[i++]=arr[k++];
    }
    for(int i=left;i<=right;i++)
    {
        arr[i]=tmp[i];
    }
    return count;
}

ll mergeSort(int left, int right)
{
    ll count =0;
    int mid = (left+right)/2;
    if(right>left)
    {
        count = mergeSort(left, mid);
        count+= mergeSort(mid+1, right);
        count+= merge(left, mid+1, right);
    }
    return count;
}

void printArr(int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=0;i<n;i++)
            scanf("%d", &arr[i]);
        //printArr(n);
        printf("%lld\n", mergeSort(0, n-1));
        //printArr(n);
    }
    return 0;
}
