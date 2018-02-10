#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int sz, max=0;
    string str;
    cin>>str;
    sz=str.size();
    for(int i=1;i<sz;i++)
    {
        if(str[i]>str[max])
            max=i;
    }
    for(int i=max, j=0;j<sz;i++,j++)
    {   
        cout<<str[i%sz];
    }
    cout<<endl;
    return 0;
}
