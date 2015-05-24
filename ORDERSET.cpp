/* Not Accepted due to timelimit..:(*/

#include <bits/stdc++.h>

using namespace std;

#define MAXQ 200009
#define MAX 1000000001

typedef pair<char, int> pci;

bitset<MAXQ> isPresent;
int tree[MAXQ];

void update(int idx, int val, int n)
{
    while(idx<=MAXQ)
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

int b_search(int k){

    int low = 0 , high = 200000 , mid;
    while(low < high){
        mid = (low + high)>>1;
        if(read(mid) >= k)
            high = mid;
        else
            low = mid+1;
    }
    return low;
}

int main()
{
    vector<pci> queries;
    int q;
    char ch;
    int x;
    set<int> xs;
    map<int, int> relPos, relRpos;
    scanf("%d", &q);
    for(int i=0;i<q;i++)
    {
        scanf(" %c %d", &ch, &x);
        //printf("%c %d\n", ch, x);
        if(ch!='K')
            xs.insert(x);
        queries.push_back(pci(ch, x));
    }
    int sz=xs.size(), key, beg, end, mid, curr;
    set<int>::iterator it =xs.begin();
    for(int i=1;it!=xs.end();i++, it++)
    {
        //printf("%d %d\n", *it, i);
        relPos[*it]=i;
        relRpos[i]=*it;
    }
    int len=0;
    for(int i=0;i<q;i++)
    {
        //printf("%c %d\n", queries[i].first, queries[i].second);        
        switch(queries[i].first)
        {
            case 'I':                
                if(!isPresent[relPos[queries[i].second]])
                {
                    //printf("Inserting...\n");
                    update(relPos[queries[i].second], 1, sz);
                    isPresent[relPos[queries[i].second]]=1;
                    len++;
                }
                break;
            case 'D':                
                if(isPresent[relPos[queries[i].second]])
                {
                    //printf("Deleting...\n");
                    update(relPos[queries[i].second], -1, sz);
                    isPresent[relPos[queries[i].second]]=0;
                    len--;
                }
                break;
            case 'K':
                //printf("Kth Smallest...\n");
                key = queries[i].second;
                //Doing binary Search
                if(len<key)
                    printf("invalid\n");
                else
                {
                    //printf("K1: %d\n",relRpos[b_search(queries[i].second)]);
                    beg=1; end=MAXQ;
                    while(beg<end)
                    {
                        mid=(beg+end)>>1;
                        curr=read(mid);
                        /*if(curr==key)
                        {
                            printf("K2: %d\n", relRpos[mid]);
                            break;
                        }*/
                        //printf("beg: %d %d %d curr: %d\n", beg, end, mid, curr);
                        if(curr>=key)
                        {
                            end=mid;
                        }
                        else
                        {
                            beg=mid+1;
                        }
                    }
                    printf("%d\n", relRpos[beg]);
                }
                break;
            case 'C':
                //printf("Counting...%d\n", relPos[queries[i].second]);
                printf("%d\n", read(relPos[queries[i].second]-1));
                break;
            default:
                //printf("Default...\n");
                break;            
        };
        /*printf("Tree: ");
        for(int j=0;j<=sz;j++)
        {
            printf("%d ", tree[j]);
        }
        printf("\n");*/
    }
    return 0;
}
