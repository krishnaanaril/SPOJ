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
}
