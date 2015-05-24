/*
    HackerEarth August Clash, 2014
    Status: Accepted
    Date: 8/16/2014
*/
//#include <bits/stdc++.h>
//
//#define MAX 100001
//
//using namespace std;
//
//int main()
//{
//    int t, n;
//    bitset<MAX> isPrime;
////    int count[MAX]={0}, n,temp, j;
////    //int mem[MAX][MAX];
////    map<int, int> dat;
//    vector<int> primes;
//    isPrime.flip();
//
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
//    cin>>t;
//    while(t--)
//    {
//        cin>>n;
//        for(int i=0;i<n;i++)
//        {
//            cout<<primes[i]<<" ";
//        }
//        cout<<endl;
//    }
//    //cout<<primes.size()<<endl;
//    return 0;
//}
