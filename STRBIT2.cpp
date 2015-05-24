#include <bits/stdc++.h>

using namespace std;

int main()
{
    memset(st,-1,sizeof(st)); 
for(i=0; i < n ; i++) 
{ 
    if(st[i]!=-1) 
    { 
        j=ans-st[i]; 
        if(j&1 && s[i]=='R') 
            x='G'; 
        else if(j&1 && s[i]=='G') 
            x='R'; 
        else x=s[i]; 
    } 
    else 
        x=s[i]; 
    if(x=='R') 
    { 
        j=min(n-1,i+k-1); 
        while(st[j]==-1 && j>=i) 
        { 
            st[j]=ans; 
            j--; 
        } 
        ans++; 
    } 
} 
pi(ans); 
    return 0;
}
