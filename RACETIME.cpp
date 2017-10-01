/*
      Idea correct, but TLE
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
const int SQN = 500;

multiset<int> st[SQN];
multiset<int>::iterator it;
int dat[N], n, q, sn, a, b, x;
char ch;

void add(int pos, int val){
      auto itr = st[pos/sn].find(dat[pos]);
      if(itr!=st[pos/sn].end()){
          st[pos/sn].erase(itr);
      }
      st[pos/sn].insert(val);
      dat[pos] = val;
}

int getval(int l, int r, int val){
      int res = 0;

      while(l<=r && (l)%sn!=0){
            if(dat[l++]<=val)
                  res++;
      }
      // cout<<l<<": "<<res<<"\n";
      while(l+sn-1<=r){
            // cout<<l<<" - \n";
            it = st[l/sn].upper_bound(val);
            int diff = distance(st[l/sn].begin(), it);
            // cout<<"diff: "<<diff<<" "<<(*it)<<"\n";
            if(it !=st[l/sn].end() && *it==val)
                  diff++;
            res+=diff;
            l+=sn;
      }
      while(l<=r){
            if(dat[l++]<=val)
                  res++;
      }
      return res;
}

int main(){
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin>>n>>q;
      sn = sqrt(n);
      for(int i=0; i<=sn; i++)
            st[i].clear();
      for(int i=0; i<n; i++){
            cin>>dat[i];
            st[i/sn].insert(dat[i]);
      }
      // printval();
      for(int i=0; i<q; i++){
            cin>>ch;
            if(ch=='M'){
                  cin>>a>>x;
                  --a;
                  add(a, x);
            }
            else if(ch=='C'){
                  cin>>a>>b>>x;
                  --a;--b;
                  cout<<getval(a, b, x)<<"\n";
            }
      }
      return 0;
}
