///*
//    SPOJ: PTIME
//    Status: Accepted
//    Date: 8/15/2014
//*/
//
//#include <bits/stdc++.h>
//
//#define MAX 10050
//
//using namespace std;
//
//int main()
//{
//    bitset<MAX> isPrime;
//    int count[MAX]={0}, n,temp, j;
//    //int mem[MAX][MAX];
//    map<int, int> dat;
//    vector<int> primes;
//    /*
//        Generating Primes
//    */
//    isPrime.flip();
//    isPrime[0]=isPrime[1]=0;
//    for(int i=2;i<MAX;i+=2)
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
//
//    while(cin>>n)
//    {
//        dat.clear();
//        for(int i=2;i<=n;i++)
//        {
//            try
//            {
//                temp=i;
//                for(j=0;primes[j]<=n;j++)
//                {
//                    while(temp!=0 && temp%primes[j]==0 )
//                    {
//
//                        count[primes[j]]++;
//                        temp/=primes[j];
//                    }
//                }
//            }
//            catch(int e)
//            {
//                cout<<primes[j]<<endl;
//            }
//        }
//        bool first=true;
//        for(int i=0;i<MAX;i++)
//        {
//            if(count[i]!=0)
//            {
//                if(first)
//                {
//                    cout<<i<<"^"<<count[i];
//                    first=false;
//                }
//                else
//                {
//                    cout<<" * "<<i<<"^"<<count[i];
//                }
//            }
//        }
//        cout<<endl;
//    }
//    return 0;
//}
