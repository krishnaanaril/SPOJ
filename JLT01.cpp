#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, sz, f;
    string str;
    map<char, int> pmap;
    set<int> st;
    cin>>t;
    while(t--)
    {
        f=0;
        pmap.clear();
        st.clear();
        cin>>str;
        sz=str.size();
        for(int i=0;i<sz;i++)
        {
            pmap[str[i]]++;
        }
        for(map<char, int>::iterator it=pmap.begin(); it!=pmap.end();it++)
        {
            if(it->second == sz-it->second)
            {
                cout<<"YES"<<endl; f=1;break; 
            }
        }    
        if(f==0)   
        {
            cout<<"NO"<<endl;
        } 
    }
    
    return 0;
}
