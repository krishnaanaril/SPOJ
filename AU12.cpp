///*
//    SPOJ: AU12
//    Status: Accepted. On Second attempt.
//    Date: 8/21/2014
//*/
//
//#include <bits/stdc++.h>
//
//#define LIM 1000001000
//#define MAX 40000
//
//typedef long long ll;
//
//using namespace std;
//
//int main()
//{
//    vector<ll> primes;
//    bitset<MAX> isPrime;
//    int t, flag;
//    ll n;
//
//    isPrime.flip();
//    isPrime[0]=isPrime[1]=0;
//    for(int i=4;i<MAX;i+=2)
//    {
//        isPrime[i]=0;
//    }
//    primes.push_back(2);
//    for(int i=3;i<MAX;i+=2)
//    {
//        if(isPrime[i])
//        {
//            primes.push_back(i);
//            for(int j=2*i;j<MAX;j+=i)
//            {
//                isPrime[j]=0;
//            }
//        }
//    }
//    cin>>t;
//    while(t--)
//    {
//        cin>>n;
//
//        for(ll i=n+1;i<LIM;i++)
//        {
//            flag=0;
//            for(ll j=0;primes[j]<=sqrt(i);j++)
//            {
//                if(i%primes[j]==0)
//                {
//                    flag=1;
//                    break;
//                }
//            }
//            if(flag==0)
//            {
//                cout<<i<<endl;
//                break;
//            }
//        }
//    }
//    return 0;
//}
