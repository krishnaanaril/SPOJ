///*
//    SPOJ: DCEPC11B
//    Status: Accepted
//    Date: 8/17/2014
//
//    Referred Internet to solve problem. N
//
//*/
//
//#include <bits/stdc++.h>
//
//typedef long long ll;
//
//using namespace std;
//
///*
//    Using Fermat's Theorem
//    a^-1=a^(p-2)modp
//*/
//ll fastExp(ll a, ll b, ll mod)
//{
//    ll res;
//    if(b==0)
//    {
//        return 1;
//    }
//    if(b==1)
//    {
//        return a;
//    }
//    res=fastExp(a, b>>1, mod)%mod;
//    if(b&1)
//    {
//        return (((res*res)%mod)*a)%mod;
//    }
//    else
//    {
//        return (res*res)%mod;
//    }
//}
//
//int main()
//{
//    /*
//        STL function for GCD
//    */
//    //cout<<__gcd(10,5)<<endl;
//    int t;
//    ll n, p, res;
//    cin>>t;
//    while(t--)
//    {
//        res=1;
//        cin>>n>>p;
//        if(n>=p)
//        {
//            cout<<"0"<<endl;
//            continue;
//        }
//        if(n==p-1)
//        {
//            /* Wilson's Theorem */
//            cout<<p-1<<endl;
//            continue;
//        }
//        for(int i=n+1;i<p-1;i++)
//        {
//            res=(res*i)%p;
//        }
//        res=fastExp(res, p-2, p);
//        cout<<res<<endl;
//    }
//    return 0;
//}
