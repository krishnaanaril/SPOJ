#include <bits/stdc++.h>

using namespace std;

#define MAX 101
#define fo(i, n) for(int (i)=0;(i)<(n);(i)++)
#define foe(i, s, n) for(int (i)=(s);(i)<=(n);(i)++)

int main()
{
    ios_base::sync_with_stdio(0);
    bitset<MAX> isWin;
    isWin.reset();
    foe(i, 1, 6)
        isWin[i]=1;
    foe(i, 7, MAX-1)
        foe(j, 1, 6) 
        {
            if(!isWin[i-j])
            {
                isWin[i]=1;
                break;
            }    
        } 
    fo(i, 35)
        cout<<i<<" - > "<<isWin[i]<<endl;
    return 0;
}
