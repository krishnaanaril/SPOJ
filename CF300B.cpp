#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> div, ans;
    div.push_back(1);
    int i=0, n, szd, cnt=0;
    while(true)
    {
        //cout<<div[i]<<endl;
        if(div[i]>1000000)
            break;
        div.push_back(div[i]*10);
        div.push_back(div[i]*10+1);
        i++;
    }
    sort(div.begin(), div.end(), greater<int>());
    szd = div.size();
    cin>>n;
    while(n)
    {
        for(i=0;i<szd;i++)
        {
            if(n/div[i] > 0)
                break;
        }
        n-=div[i];
        ans.push_back(div[i]);
    }
    cnt = ans.size();
    cout<<cnt<<endl;
    int sum=0;
    for(i=0;i<cnt;i++)
    {
        cout<<ans[i]<<" ";
        sum+=ans[i];
    }
    cout<<endl<<"Sum: "<<sum<<endl;
    return 0;
}
