<<<<<<< HEAD
/*
	Swamy Saranam

	Date	: 08/12/2017 11:11:54
	Author	: Krishna Mohan A M
	Problem	: http://www.spoj.com/problems/ORDERSET/
	Status	:
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

#define FASTIO                ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define FOR(i,a,b)            for(int i=(a);i<(b);i++)
#define REP(i,n)              FOR(i,0,n)
#define SORT(v)               sort((v).begin(),(v).end())
#define UN(v)                 SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)               memset(a,b,sizeof a)
#define pb                    push_back
#define x                     first
#define y                     second
#define endl                  "\n"
#define sendl                 " \n"

const int mod = 1000000007;

indexed_set s;
int q, a;
char ch;

int main()
{
      FASTIO
      cin>>q;
      while(q--){
            cin>>ch>>a;
            switch (ch) {
                  case 'I': s.insert(a);
                        break;
                  case 'D': s.erase(a);
                        break;
                  case 'K':
                        if(end(s)==s.find_by_order(a-1))
                              cout<<"invalid\n";
                        else
                              cout<<(*s.find_by_order(a-1))<<"\n";
                        break;
                  case 'C': cout<<s.order_of_key(a)<<"\n";
                        break;
            }
      }
      return 0;
=======
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
>>>>>>> 6381d1d0b50ccadb35504d86f1153b1ca4cc4a29
}
