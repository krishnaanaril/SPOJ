///*
//    SPOJ: AFS
//    Status: Accepted. Intially WA due to int -> long long
//    Date: 8/16/2014
//*/
//
//#include <bits/stdc++.h>
//
//#define MAX 1000001
//
//using namespace std;
//
//int main()
//{
////    bitset<MAX> isPrime;
////    isPrime.flip();
////    isPrime[0]=isPrime[1]=0;
////    for(int i=4;i<MAX;i+=2)
////    {
////        isPrime[i]=0;
////    }
////    for(int i=3;i<MAX;i+=2)
////    {
////        if(isPrime[i])
////        {
////            for(int j=2*i;j<MAX;j+=i)
////            {
////                isPrime[j]=0;
////            }
////        }
////    }
//    long long dat[MAX];
//    int t, n;
//    std::fill(dat,dat+MAX,1);
//    dat[0]=dat[1]=0;
//    for(int i=2;i<MAX;i++)
//    {
//        dat[i]+=dat[i-1];
//        for(int j=2*i;j<MAX;j+=i)
//        {
//            dat[j]+=i;
//        }
//    }
//    cin>>t;
//    while(t--)
//    {
//        cin>>n;
//        cout<<dat[n]<<endl;
//    }
//    //cout<<dat[5]<<endl;
//    return 0;
//}
