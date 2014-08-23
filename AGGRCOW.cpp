///*
//    SPOJ: AGGRCOW
//    Status: Solved
//    Date: 8/17/2014
//
//    Easy one. But still Googled for solution.
//*/
//
//#include <bits/stdc++.h>
//
//typedef long long ll;
//
//#define MAX 100001
//
//using namespace std;
//
//ll dat[MAX], c, n;
//
//ll distCow(ll pos)
//{
//    ll placed=1;
//    ll lastPos=dat[0];
//    for(ll i=1;i<n;i++)
//    {
//        if(dat[i]-lastPos>=pos)
//        {
//            placed++;
//            if(placed==c)
//                return 1;
//            lastPos=dat[i];
//        }
//    }
//    return 0;
//}
//
//ll binarySearch()
//{
//    ll start=0, end=dat[n-1], mid;
//    while(start<end)
//    {
//        mid=(start+end)/2;
//        if(distCow(mid)==1)
//        {
//            start=mid+1;
//        }
//        else
//        {
//            end=mid;
//        }
//    }
//    return start-1;
//}
//
//int main()
//{
//    ll t;
//    cin>>t;
//    while(t--)
//    {
//        cin>>n>>c;
//        for(ll i=0;i<n;i++)
//        {
//            cin>>dat[i];
//        }
//        sort(dat,dat+n);
//        cout<<binarySearch()<<endl;
//    }
//    return 0;
//}
