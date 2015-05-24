#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, temp, max;
    map<int, int> dat;
    cin>>t;
    while(t--)
    {
        dat.clear();
        max=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            dat[temp]++;
        }
        for(map<int, int>::iterator it=dat.begin();it!=dat.end();it++)
        {
            if(it->second > max)
            {
                max=it->second;
            }
        }
        cout<<(n-max)<<endl;
    }    
    return 0;
}
