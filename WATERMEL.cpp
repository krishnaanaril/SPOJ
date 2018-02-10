#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    if(n!=2 && !(n&1))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
