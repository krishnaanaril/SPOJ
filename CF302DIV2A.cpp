#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int k, sz, cnt, i, mp[27];
    memset(mp, 0, sizeof(mp));
    string str;
    set<char> st;
    cin>>k>>str;
    sz=str.size();
    for(int i=0;i<sz;i++)
        st.insert(str[i]);
    if(k>st.size())
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        cnt=i=0;
        while(cnt<k)
        {
            //cout<<str[i]<<" : "<<mp[str[i]-'a']<<endl;
            if(mp[str[i]-'a']==0)
            {
                mp[str[i]-'a']++;
                if(cnt!=0)
                    cout<<endl;
                cout<<str[i++];                
                cnt++;
            }
            else
            {
                mp[str[i]-'a']++;
                cout<<str[i++];                
            }
        }
        while(i<sz)
            cout<<str[i++];
        cout<<endl;
    }
    return 0;
}
