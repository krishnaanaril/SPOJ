///*
//    SPOJ: ETF
//    Status: Accepted. Reffered topcoder tuorial for prime numbers
//    Date: 8/23/2014
//*/
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int fi(int n)
//{
//    int res=n;
//    for(int i=2;i*i<=n;i++)
//    {
//        if(n%i==0)
//        {
//            res-=res/i;
//        }
//        while(n%i==0)
//        {
//            n/=i;
//        }
//    }
//    if(n>1)
//    {
//        res-=res/n;
//    }
//    return res;
//}
//
//int main()
//{
//    int t, n;
//    cin>>t;
//    while(t--)
//    {
//        cin>>n;
//        cout<<fi(n)<<endl;
//    }
//    return 0;
//}
