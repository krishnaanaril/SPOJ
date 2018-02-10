/*
    Codechef: SMPAIR
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, temp, min1, min2;
    vector<int> dat;
    cin>>t;
    while(t--)
    {
        dat.clear();
        min1=min2=INT_MAX;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            if(temp<=min1)
            {
                min2=min1;
                min1=temp;
            }
            else if(temp<min2)
            {
                min2=temp;
            }
        }
        cout<<(min1+min2)<<endl;
    }
    return 0;
}
