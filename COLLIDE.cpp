/*
    Codechef : Jan 2012 Cook off
    Date: 3/13/2015
    Problem: COLLIDE
    
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    map<char, int> dir;
    dir['U']=0;
    dir['D']=1;
    dir['R']=2;
    dir['L']=3;
    int dx[]={0, 0, 1, -1};
    int dy[]={1, -1, 0, 0};
    int t, n, xe, ye, xa, ya, dire, dira;
    char de, da;
    double time, best, timea;
    cin>>t;
    while(t--)
    {
        cin>>xe>>ye>>de;
        dire=dir[de];
        cin>>n;
        while(n--)
        {
            best=1e7;
            cin>>xa>>ya>>da;
            dira=dir[da];
            //cout<<dire<<" : "<<dira<<endl;
            if(dx[dire]==dx[dira])
            {
                //cout<<"Case 1"<<endl;
                if(xe!=xa)
                    continue;
                time=((double)ye-ya)/(dy[dira]-dy[dire]);
                if(time>=0)
                    best=min(best, time);
            }
            else if(dy[dire]==dy[dira])
            {
                //cout<<"Case 2"<<endl;
                if(ye!=ya)
                    continue;
                time=((double)xe-xa)/(dx[dira]-dx[dire]);
                if(time>=0)
                    best=min(best, time);
            }
            else
            {
                //cout<<"Case 3"<<endl;
                time=dx[dire]!=0? ((double)xa-xe)/dx[dire]:((double)ya-ye)/dy[dire];
                timea=dx[dira]!=0? ((double)xe-xa)/dx[dira]:((double)ye-ya)/dy[dira];
                if(time==timea && time>=0)
                    best=min(best, time);
            }
        }
        if(best==1e7)
            cout<<"SAFE"<<endl;
        else
            cout<<setprecision(1)<<fixed<<best<<endl;
    }
    return 0;
}
