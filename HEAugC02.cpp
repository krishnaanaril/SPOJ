//    #include <bits/stdc++.h>
//
//    typedef unsigned long long ull;
//
//    using namespace std;
//
//    ull com(ull a, ull b)
//    {
//        return (a*(a-1)*(a-2))/6;
//    }
//
//    int main()
//    {
//        int tc, t;
//        ull n, temp;
//        int primes[10]={0};
//        cin>>tc;
//        while(tc--)
//        {
//            cin>>n;
//            temp=n;
//            int isPrime[10]={0};
//            while(temp!=0)
//            {
//                t=temp%10;
//                if(t==2||t==3||t==5||t==7)
//                {
//                    if(isPrime[t]==0)
//                    {
//                        isPrime[t]=1;
//                        primes[t]++;
//                    }
//                }
//                temp/=10;
//            }
//        }
//        ull ans=0;
//        if(primes[2]>=3)
//        {
//            ans+=com(primes[2],3);
//        }
//        if(primes[3]>=3)
//        {
//            ans+=com(primes[3],3);
//        }
//        if(primes[5]>=3)
//        {
//            ans+=com(primes[5],3);
//        }
//        if(primes[7]>=3)
//        {
//            ans+=com(primes[7],3);
//        }
//        cout<<ans<<endl;
//        return 0;
//    }
