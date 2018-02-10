#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, k, cnt=0;
    cin>>n>>k;
    if(n==1 || k>ceil(pow(n, 2)/2.0))
        cout<<"NO"<<endl;
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(cnt<k)
                {
                    if(i&1)
                    {
                        if(j&1)
                            cout<<"L", cnt++;
                        else
                            cout<<"S";
                    }
                    else
                    {
                        if(j&1)
                            cout<<"S";
                        else
                            cout<<"L", cnt++;
                    }
                }
                else
                {
                    cout<<"S";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
