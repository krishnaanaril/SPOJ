#include <bits/stdc++.h>

using namespace std;

#define MAX 2048

typedef long long ll;

int tree[MAX][MAX], n;


ll getSumy(int x, int y)
{
    ll sum=0;
    while(y>0)
    {
        sum+=tree[x][y];
        y-=y&-y;
    }
    return sum;
}

void updatey(int x, int y, int val)
{
    while(y<=n+9)
    {
        tree[x][y]+=val;
        y+=y&-y;
    }
}

ll getSum(int x, int y)
{
    ll sum=0;
    while(x>0)
    {
        sum+=getSumy(x, y);
        x-=x&-x;
    }
    return sum;
}

void update(int x, int y, int val)
{
    while(x<=n+9)
    {
        updatey(x, y, val);
        x+=x&-x;
    }
}

/*
void update(int x,int y,int val,int max)
{
    while(x<=max)
    {
        int ty = y;
        while(ty <= max)
        {
            tree[x][ty] += val;
            ty += (ty & -ty);
        }
        x += (x & -x);
    }
}

ll getSum(int x,int y)
{
    ll sum = 0;
    while( x )
    {
        int ty = y;
        while( ty )
        {
            sum += tree[x][ty];
            ty -= (ty & -ty);
        }
        x -= (x & -x);
    }
    return sum;
}
*/
int main()
{
    //ios_base::sync_with_stdio(0);
    int t, x1, x2, y1, y2,  val;
    char str[50];
    //cin>>t;
    scanf("%d", &t);
    while(t--)
    {
        memset(tree,0,sizeof tree);
        //cin>>n;
        scanf("%d", &n);
        while(true)
        {
            //cin>>str;
            scanf("%s", str);
            //printf("%s\n", str);
            if(strcmp(str,"END")==0)
                break;
            else if(strcmp(str,"SET")==0)
            {   
                //cout<<"Updating"<<endl;             
                //cin>>x1>>y1>>val;
                scanf("%d%d%d", &x1, &y1, &val);
                ll p_val = getSum(x1+1, y1+1)+getSum(x1, y1)-getSum(x1+1, y1)-getSum(x1, y1+1); 
                update(x1+1, y1+1, val-p_val);
                //cout<<"Updated"<<endl;                     
            }
            else if(strcmp(str,"SUM")==0)
            {
                //cout<<"Summing up"<<endl;
                //cin>>x1>>y1>>x2>>y2;
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                //cout<<getSum(x2+1, y2+1)<<endl;
                //cout<<getSum(x1+1, y1+1)<<endl;
                //cout<<(getSum(x2+1, y2+1) - getSum(x1, y1))<<endl;
                ll sum = getSum(x2+1, y2+1)+getSum(x1, y1) - getSum(x1, y2+1) - getSum(x2+1, y1);
                printf("%lld\n", sum);
                //cout<<"Got Sum."<<endl;
            }
        }
        printf("\n");
    }
    return 0;
}
