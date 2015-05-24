    /*
	    SPOJ: MAIN72
	    Status: Accepted
	    Date: 8/15/2014	
    */
    #include <bits/stdc++.h>

    #define MAX 1000001

    using namespace std;

    int main()
    {
    int list[MAX];
    bitset<MAX> sum;
    vector<int> dat;
    int temp, n, t;
    long curr, ans, max;
    cin>>t;
    while(t--)
    {
        sum.reset();
        dat.clear();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            dat.push_back(temp);
        }
        sum[0]=1;
        sum[dat[0]]=1;
        list[0]=0;
        list[1]=dat[0];
        curr=2;
        ans=dat[0];
        for(int i=1;i<n;i++)
        {
            max=curr;
            for(int j=0;j<max;j++)
            {
                if(sum[list[j]+dat[i]]==0)
                {
                    //cout<<"Now: "<<list[j]+dat[i]<<endl;
                    sum[list[j]+dat[i]]=1;
                    list[curr]=list[j]+dat[i];
                    ans+=list[j]+dat[i];
                    curr++;
                }
            }
        }
        // cout<<"Sum: ";
        // for(int i=0;i<curr;i++)
        // {
        // cout<<sum[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<curr;i++)
        // {
        // cout<<list[i]<<" ";
        // }
        // cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
    }



