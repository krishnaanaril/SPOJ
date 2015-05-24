#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int dat[3];
    cin>>dat[0]>>dat[1]>>dat[2];
    cout<<max((dat[0]+dat[1]+dat[2]), max((dat[0]+dat[1]*dat[2]), max((dat[0]*dat[1]+dat[2]), max(((dat[0]+dat[1])*dat[2]), max((dat[0]*(dat[1]+dat[2])), (dat[0]*dat[1]*dat[2]))))))<<endl;
    return 0;
}
