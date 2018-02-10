#include <bits/stdc++.h>

using namespace std;

const int N = 2e4+5;

typedef pair<int, int> pii;


struct classcomp {
      bool operator()(const pii &a, const pii &b){
            if(b.second==a.second)
                  return a.first < b.first;
            return a.second > b.second;
      }
};

bool cmp(const pii &a, const pii &b){
      if(b.second==a.second)
            return a.first < b.first;
      return a.second > b.second;
}

bool cmp2(const pii &a, const pii &b){
      return a.first < b.first;
}

bitset<N> visit;

vector<pii> dat, v;
set<pii> st;
vector<pii>::iterator pos;
pii tmp;
int t, m;

int main(){
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin>>t;
      while(t--){
            cin>>m;
            visit.reset();
            dat.clear();
            v.clear();
            for(int i=0; i<m; i++){
                  cin>>tmp.first>>tmp.second;
                  dat.push_back(tmp);
            }
            sort(dat.begin(), dat.end(), cmp);
            // for(pii it : dat){
            //       cout<<it.first<<" : "<<it.second<<"\n";
            // }
            v.push_back(dat[0]);
            for(int i=1; i<m; i++){
                  pos = upper_bound(v.begin(), v.end(), dat[i], cmp2);
                  if(pos!=v.end() && (*pos).first==dat[i].first){
                        // cout<<(*pos).first<<" : "<<(*pos).second<<" - ";
                        // cout<<dat[i].first<<" : "<<dat[i].second<<"\n";
                        pos++;
                  }
                  if(pos==v.end())
                        v.push_back(dat[i]);
                  else{
                        // cout<<(*pos).first<<" : "<<(*pos).second<<" - ";
                        // cout<<dat[i].first<<" : "<<dat[i].second<<"\n";
                        (*pos).first = dat[i].first;
                        (*pos).second = dat[i].second;
                  }
            }
            cout<<v.size()<<"\n";
      }
      return  0;
}
