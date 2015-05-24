/*
    Codechef: CHEFD
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, temp, l, r, p, d, ch;
    vector<int> dat, del;
    set<int> two, three, five;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        if(temp%2==0)
        {
            two.insert(i);
        }
        if(temp%3==0)
        {
            three.insert(i);
        }
        if(temp%5==0)
        {
            five.insert(i);
        }
        dat.push_back(temp);
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>ch;
        switch(ch)
        {
            case 1:
                cin>>l>>r>>p;
                l--; r--;
                switch(p)
                {
                    case 2:
                        for(set<int>::iterator it=two.begin(); *it<=r && it!=two.end(); it++)
                        {
                            if(*it >=l  && *it <=r)
                            {
                                dat[*it]/=2;
                                if(dat[*it]%2 !=0)
                                {
                                    /*
                                        Do not work because of iterators...
                                    */
                                    //two.erase(*it);
                                    del.push_back(*it);
                                }
                                /*if(dat[*it]%3 == 0)
                                {
                                    three.insert(*it);
                                }
                                else if(dat[*it]%5 == 0)
                                {
                                    five.insert(*it);
                                }*/
                            }
                        }
                        for(int j=0;j<del.size();j++)
                        {
                            two.erase(del[j]);
                        }
                        del.clear();
                        break;
                    case 3:
                        for(set<int>::iterator it=three.begin(); *it<=r && it!=three.end(); it++)
                        {
                            if(*it >=l  && *it <=r)
                            {
                                dat[*it]/=3;
                                if(dat[*it]%3 !=0)
                                {
                                    //three.erase(*it);
                                    del.push_back(*it);
                                }
                                /*if(dat[*it]%2 == 0)
                                {
                                    two.insert(*it);
                                }
                                if(dat[*it]%5 == 0)
                                {
                                    five.insert(*it);
                                }*/
                            }
                        }
                        for(int j=0;j<del.size();j++)
                        {
                            three.erase(del[j]);
                        }
                        del.clear();
                        break;
                    case 5:
                        for(set<int>::iterator it=five.begin(); *it<=r && it!=five.end(); it++)
                        {
                            if(*it >=l  && *it <=r)
                            {
                                dat[*it]/=5;
                                if(dat[*it]%5 !=0)
                                {
                                    //five.erase(*it);
                                    del.push_back(*it);
                                }
                                /*if(dat[*it]%3 == 0)
                                {
                                    three.insert(*it);
                                }
                                if(dat[*it]%2 == 0)
                                {
                                    two.insert(*it);
                                }*/
                            }
                        }
                        for(int j=0;j<del.size();j++)
                        {
                            five.erase(del[j]);
                        }
                        del.clear();
                        break;
                };
                break;
            case 2:
                cin>>l>>d;
                l--;
                two.erase(l);
                three.erase(l);
                five.erase(l);
                dat[l]=d;
                if(d%2==0)
                {
                    two.insert(l);
                }
                if(d%3==0)
                {
                    three.insert(l);
                }
                if(d%5==0)
                {
                    five.insert(l);
                }
                break;
        };
    }
    for(int i=0;i<n;i++)
    {
        cout<<dat[i]<<" "; 
    }
    cout<<endl;
    return 0;
}
