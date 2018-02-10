/*
      Not solved
      http://www.spoj.com/problems/ADAJOBS/
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 3e6+5;
const int M = 30;

int trie[N][M], f[N];// au[N][M];
int q, ty, mxS = 1;
string st;
bitset<N> isEnd;

inline void add(string s){
      int v = 0;
      for(char ch : s){
            int pos = ch-'a';
            if(!trie[v][pos])gooutwithcrocodile
                  trie[v][pos] = mxS++;
            // au[v][pos] = trie[v][pos];
            if(v)
                  f[trie[v][pos]] = trie[f[v]][pos];
            v = trie[v][pos];
      }
      // cout<<"end of "<<s<<" : "<<(v)<<"\n";
      isEnd[v] = 1;
}

inline bool query(string s){
      int v = 0;
      // cout<<s<<":\n";
      for(char ch : s){
            int pos = ch-'a';
            // cout<<ch<<" : "<<v<<" : "<<pos<<" : "<<f[v]<<"\n";
            if(trie[v][pos])
                  v = trie[v][pos];
            else
                  v = trie[f[v]][pos];
            // cout<<ch<<" - "<<v<<"\n";
            if(isEnd[v])
                  return true;
      }
      return false;
}

int main(){
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin>>q;
      while(q--){
            cin>>ty>>st;
            if(ty)
                  if(query(st))
                        cout<<"YES\n";
                  else
                        cout<<"NO\n";
            else{
                  add(st);
            }
      }
      return 0;
}
