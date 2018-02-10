#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, sz, a, b, i;
    string str;
    char ch, och;
    cin>>t;
    while(t--)
    {
        a=b=0;
        cin>>str;
        sz=str.size();
        ch=str[0];
        och=(ch=='-')?'+':'-';
        //cout<<ch<<" : ";
        for(i=0;i<sz-1;i+=2)
        {
            if(str[i]!=ch)
            {
                a++; 
            }
            if(str[i+1]!=och) 
            {
                a++;
            }
        }
        if(i==(sz-1) && (ch != str[i])) a++;
        ch=str[sz-1];
        och=(ch=='-')?'+':'-';
        //cout<<ch<<" : "<<endl;
        for(i=sz-1;i>0;i-=2)
        {
            if(str[i]!=ch) 
            {
                b++; 
            }
            if(str[i-1]!=och) 
            {
                b++;
            }
        }
        if(i==0 && (ch != str[i])) b++;
        //cout<<a<<" : "<<b<<endl;
        cout<<min(a, b)<<endl;
    }
    return 0;
}
