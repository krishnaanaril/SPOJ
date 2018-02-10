/*
    Name: Krishna Mohan
    Date: //2015
    Algorithm:
    Site:
    Contest:
*/
#include<bits/stdc++.h>

#define MAX 100
#define INF 1000000007
#define MOD 1000000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, tmp, ans=0;
    cin>>n;
    while(n--)
    {
        cin>>tmp;
        ans^=tmp;
    }
    cout<<ans<<endl;;
    return 0;
}
