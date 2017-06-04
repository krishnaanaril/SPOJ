#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    cout<<"  /\\\n";
    for(int i=0;i<n;i++)
    {
        cout<<"  ||\n";
    }
    cout<<" /||\\\n";
    cout<<"/:||:\\\n";
    for(int i=0;i<n-1;i++)
    {
        cout<<"|:||:|\n";
    }
    cout<<"|/||\\|\n  **\n  **\n";
    return 0;
}
