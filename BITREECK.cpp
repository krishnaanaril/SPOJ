#include <bits/stdc++.h>

using namespace std;

#define MAX 100

int dat[MAX], tree[MAX], n;

void printBinary(int n)
{
    cout<<"Binary of "<<n<<" : ";
    while(n)
    {
        cout<<(n%2);
        n/=2;
    }
    cout<<endl;
}

void printTree()
{
    cout<<"Tree: ";
    for(int i=0;i<=n;i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
}

int getSum(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        cout<<"1->"<<idx<<" : "<<(idx&-idx)<<endl;
        idx-=(idx&-idx);
        cout<<"2->"<<idx<<" : "<<tree[idx]<<endl;
    }
    return sum;
}

void update(int val, int idx)
{
    //cout<<"In Update "<<idx<<endl;
    while(idx<=n)
    {
        tree[idx]+=val;
        idx+=(idx&-idx);
    }
}

int readSingle(int idx)
{
    int sum=tree[idx];
    if(idx>0)
    {
        int z=idx-(idx&-idx);
        idx--;
        while(idx!=z)
        {
            sum-=tree[idx];
            idx-=(idx&-idx);
        }
    }
    return sum;
}

int getGBit(int num)
{
    int ans=1;
    while(num>1)
    {
        ans<<=1;
        num>>=1;
        cout<<num<<" : "<<ans<<endl;
    }
    return ans;
}            



int main()
{
    ios_base::sync_with_stdio(0);
    n=6; 
    for(int i=1;i<=n;i++)
        cin>>dat[i];
    for(int i=1;i<=n;i++)
        cout<<dat[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        update(dat[i], i);
        cout<<"Inserting "<<dat[i]<<endl;
        printTree();
    }
    cout<<getSum(5)<<endl;
    /*cout<<getSum(1)<<endl;
    update(5, 2);
    cout<<getSum(2)<<endl;
    cout<<getSum(3)<<endl;
    cout<<getSum(4)<<endl;
    cout<<getSum(5)-getSum(4)<<" = "<<readSingle(5)<<endl;
    cout<<getGBit(13)<<endl;*/
    return 0;
}
