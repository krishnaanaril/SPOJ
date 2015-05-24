#include <bits/stdc++.h>

using namespace std;

int t, n, k, resa, resb;
string binStr, stra, strb;

void fun(string &str, int &res)
{
    int cnt=0;
    res=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            cnt++;
        }
        else
        {
            if(str[i]==str[i-1])
                cnt++;
            else
                cnt=0;
            if(cnt>k)
            {
                res++;
                cnt=0;
                str[i]= str[i]=='1'? '0':'1';
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>binStr;
        stra = binStr;
        fun(stra, resa);
        strb = binStr;
        reverse(strb.begin(), strb.end());
        fun(strb, resb);
        //cout<<resa<<" : "<<stra<<" : "<<resb<<" : "<<strb<<endl;
        if(resa<resb)
        {
            cout<<resa<<endl<<stra<<endl;
        }
        else
        {
            cout<<resb<<endl<<strb<<endl;
        }
    }
    return 0;
}
