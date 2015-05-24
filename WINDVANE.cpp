/*
    SPOJ: WINDVANE
    Status: Accepted
    Date: 8/15/2014
*/

#include <bits/stdc++.h>

#define MAX 1001

using namespace std;

int main()
{
    int m,n,c, x1, x2, y1, y2, dir, off;
    int dat[MAX][MAX];
    char ch, loc[]={'N','E','S','W'};
    map<char, int> revmap;
    revmap['N']=0;
    revmap['E']=1;
    revmap['S']=2;
    revmap['W']=3;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>ch;
            dat[i][j]=revmap[ch];
        }
    }
    cin>>c;
    while(c--)
    {
        //cout<<"In loop:"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 'C':
                cin>>x1>>y1>>x2>>y2>>dir;
                off=dir?3:1;
                for(int i=x1-1;i<x2;i++)
                {
                    for(int j=y1-1;j<y2;j++)
                    {
                        dat[i][j]=(dat[i][j]+off)%4;
                    }
                }
                break;
            case 'D':
                cin>>x1>>y1;
                cout<<loc[dat[x1-1][y1-1]]<<endl;
                break;
            default:
                break;
        }
//        for(int i=0;i<m;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                cout<<dat[i][j]<<" ";
//            }
//            cout<<endl;
//        }
    }
    return 0;
}
