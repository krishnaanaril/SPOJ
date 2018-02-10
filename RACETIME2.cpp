#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vv;

vv dat, bkts;
int n, q, a, b, x, tmp, sq;
vi cur;
char ch;

void add(int a, int x){
      int pos = a/sq;
      int indx = a%sq;
      // cout<<a<<" ** "<<pos<<" ** "<<indx<<"\n";
      bkts[pos] = dat[pos];
      bkts[pos][indx] = dat[pos][indx] = x;
      sort(bkts[pos].begin(), bkts[pos].end());
}

int getval(int a, int b, int x){
      int cnt = 0, beg = a/sq, en = b/sq;
      a%=sq; b%=sq;
      // cout<<beg<<" : "<<en<<" -- "<<a<<" : "<<b<<"\n";
      // printval();
      if(beg==en){
            for(int i=a; i<=b; i++){
                  cnt += (dat[beg][i]<=x);
            }
      }
      else{
            for(int i=a; i<dat[beg].size(); i++){
                  cnt += (dat[beg][i]<=x);
            }
            for(int i=0; i<=b; i++){
                  cnt += (dat[en][i]<=x);
            }
            for(int i=beg+1; i<en; i++){
                  cnt += upper_bound(bkts[i].begin(), bkts[i].end(), x) - bkts[i].begin();
            }
      }
      return cnt;
}

int main(){
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin>>n>>q;
      sq = n/sqrt(n);
      for(int i=0; i<n; i++){
            if(i!=0 && i%sq==0){
                  dat.push_back(cur);
                  sort(cur.begin(), cur.end());
                  bkts.push_back(cur);
                  cur.clear();
            }
            cin>>tmp;
            cur.push_back(tmp);
      }
      if(cur.size()>0){
            dat.push_back(cur);
            sort(cur.begin(), cur.end());
            bkts.push_back(cur);
            cur.clear();
      }
      // printval();
      for(int i=0; i<q; i++){
            cin>>ch;
            if(ch=='M'){
                  cin>>a>>x;
                  --a;
                  add(a, x);
                  // printval();
            }
            else if(ch=='C'){
                  cin>>a>>b>>x;
                  --a; --b;                  
                  cout<<getval(a, b, x)<<"\n";
            }
      }
      return 0;
}
