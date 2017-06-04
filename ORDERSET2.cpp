/*
    Trying Nithinraj's Logic
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX 200009

int tree[MAX], relPos[MAX];
bitset<MAX> isPresent;

struct data
{
    char ch;
    int x, pos, hash;
};

bool cmp(const data &a, const data &b)
{
    return a.x == b.x? a.pos < b.pos: a.x < b.x;
}

void update(int idx, int val)
{
    while(idx<=MAX)
    {
        tree[idx]+=val;
        idx+=idx&-idx;
    }
}

int read(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=idx&-idx;
    }
    return sum;
}

data sortQuery[MAX], query[MAX];

int main()
{
    int q;
    scanf("%d", &q);
    for(int i=0;i<q;i++)
    {
        scanf(" %c%d", &sortQuery[i].ch, &sortQuery[i].x);
        sortQuery[i].pos=i+1;
    }
    sort(sortQuery, sortQuery+q, cmp);
    int cnt=1, prev=sortQuery[0].x, beg, mid, end;
    sortQuery[0].hash=cnt;
    relPos[cnt]=sortQuery[0].x;
    for(int i=1;i<q;i++)
    {
        if(sortQuery[i].x!=prev)
        {
            prev=sortQuery[i].x;
            cnt++;
            sortQuery[i].hash=cnt;
            relPos[cnt]=sortQuery[i].x;
        }
        else
            sortQuery[i].hash=cnt;
    }
    for(int i=0;i<q;i++)
    {
        query[sortQuery[i].pos]=sortQuery[i];
    }
    cnt=0;
    for(int i=1;i<=q;i++)
    {
        //printf("%c %d\n", query[i].ch, query[i].x);        
        switch(query[i].ch)
        {
            case 'I':
                if(!isPresent[query[i].hash])
                {
                    //printf("Inserting...\n");
                    update(query[i].hash, 1);1000000
                    isPresent[query[i].hash]=1;
                    cnt++;
                }
                break;
            case 'D':
                if(isPresent[query[i].hash])
                {
                    //printf("Deleting...\n");
                    update(query[i].hash, -1);
                    isPresent[query[i].hash]=0;
                    cnt--;
                }
                break;
            case 'K':
                //printf("Kth Smallest...%d %d\n", cnt, query[i].x);
                if(cnt < query[i].x)
                {
                    printf("invalid\n");
                }
                else
                {
                    beg=0; end=MAX;
                    while(beg<end)
                    {
                        mid=(beg+end)>>1;
                        if(read(mid)>=query[i].x)
                        {
                            end=mid;
                        }
                        else
                        {
                            beg=mid+1;
                        }
                    }
                    printf("%d\n", relPos[beg]);
                }
                break;
            case 'C':
                //printf("Counting...%d\n", query[i].hash);
                printf("%d\n", read(query[i].hash-1));
                break;    
        };
        /*printf("Tree: ");
        for(int j=0;j<=8;j++)
        {
            printf("%d ", tree[j]);
        }
        printf("\n");*/
    }
    return 0;
}
