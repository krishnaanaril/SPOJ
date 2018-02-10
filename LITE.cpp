#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

typedef long long ll;

int tree[MAX], n, m, ch;



int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>ch>>l>>r;;
        if(ch)
        {            
            cout<<getSum(l, r)
        }
    }
    return 0;
}
