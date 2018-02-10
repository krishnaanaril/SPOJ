#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, sz, f;
    string n, ans;
    cin>>t;
    while(t--)
    {
        ans="";
        f=0;
        cin>>n;
        sz=n.size();
        if(n[0]>'5')
        {
            cout<<'3';
            for(int i=0;i<sz;i++)
            {
                cout<<'3';
            }
            cout<<endl;
            continue;
        }
        else if(n[0]<'3')
        {
            for(int i=0;i<sz;i++)
            {
                cout<<'3';
            }
            cout<<endl;
            continue;
        }
        else if(n[0]=='4')
        {
            cout<<'5';
            for(int i=1;i<sz;i++)
            {
                cout<<'3';
            }
            cout<<endl;
            continue;        
        }
        else if(n[0]=='5')
        {
            int i;
            for(i=1;i<sz;i++)
            {
                if(n[i]<'3')
                {
                    f=1; break;
                }
                if(n[i]<'5')
                {
                    f=2; break;
                }
            }
            if(f==0)
            {
                cout<<'3';
                for(int j=0;j<sz;j++)
                {
                    cout<<'3';
                }
                cout<<endl;
            }
            else if(f==1)
            {
                for(int j=0;j<i;j++)
                {
                    cout<<n[j];
                }
                for(int j=i;j<sz;j++)
                {
                    cout<<'3';
                }
                cout<<endl;
            }            
            else if(f==2)
            {
                for(int j=0;j<i;j++)
                {
                    cout<<n[j];
                }
                cout<<'5';
                for(int j=i+1;j<sz;j++)
                {
                    cout<<'3';
                }
                cout<<endl;
            }
        }
        else if(n[0]=='3')
        {
            int i;
            for(i=1;i<sz;i++)
            {
                if(n[i]<'3')
                {
                    f=1; break;
                }
                if(n[i]=='4')
                {
                    f=2; break;
                }
            }
            cout<<f<<endl;
            if(f==0)
            {                
                for(int j=0;j<sz-1;j++)
                {
                    cout<<n[i];
                }
                cout<<'5';
                cout<<endl;
            }
            else if(f==1)
            {
                for(int j=0;j<i;j++)
                {
                    cout<<n[j];
                }
                for(int j=i;j<sz;j++)
                {
                    cout<<'3';
                }
                cout<<endl;
            }            
            else if(f==2)
            {
                for(int j=0;j<i;j++)
                {
                    cout<<n[j];
                }
                cout<<'5';
                for(int j=i+1;j<sz;j++)
                {
                    cout<<'3';
                }
                cout<<endl;
            }                      
        }
    }
 
 
 
 
 
 
 
 
 
 
 
 
 
    return 0;
}
