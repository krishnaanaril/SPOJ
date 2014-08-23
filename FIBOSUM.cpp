///*
//    SPOJ: FIBOSUM
//    Status: Accepted
//    Date: 8/17/2014
//*/
//
//#include <bits/stdc++.h>
//
//#define MOD 1000000007
//
//typedef unsigned long long ll;
//
//using namespace std;
//
//ll SumFib(ll num)
//{
//    ll fib[2][2]={{1,1},{1,0}}, ans[2][2]={{1,0},{0,1}}, temp[2][2]={{0,0},{0,0}};
//    while(num)
//    {
//        if(num&1)
//        {
//            for(int i=0;i<2;i++)
//                for(int j=0;j<2;j++)
//                    temp[i][j]=0;
//
//            for(int i=0;i<2;i++)
//                for(int j=0;j<2;j++)
//                    for(int k=0;k<2;k++)
//                        temp[i][j]=(temp[i][j]+ans[i][k]*fib[k][j])%MOD;
//
//            for(int i=0;i<2;i++)
//                for(int j=0;j<2;j++)
//                        ans[i][j]=temp[i][j];
//        }
//
//        for(int i=0;i<2;i++)
//            for(int j=0;j<2;j++)
//                temp[i][j]=0;
//
//        for(int i=0;i<2;i++)
//            for(int j=0;j<2;j++)
//                for(int k=0;k<2;k++)
//                    temp[i][j]=(temp[i][j]+fib[i][k]*fib[k][j])%MOD;
//
//        for(int i=0;i<2;i++)
//            for(int j=0;j<2;j++)
//                    fib[i][j]=temp[i][j];
//
//        num=num>>1;
//    }
//    return (ans[0][1])%MOD;
//}
//
//int main()
//{
//    int t;
//    ll n,m;
//    cin>>t;
//    while(t--)
//    {
//        cin>>n>>m;
//        //cout<<SumFib(m)<<endl;
//        cout<<(SumFib(m+2)-SumFib(n+1)+MOD)%MOD<<endl;
//    }
//    return 0;
//}
