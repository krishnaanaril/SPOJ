///*
//    SPOJ: NOSQ
//    Status: Finally Acceptd...:P
//
//    Date: 8/16/2014
//
//    *Browsed internet for solution
//*/
//#include <bits/stdc++.h>
//
//#define MAX 100001
//
//using namespace std;
//
//int main()
//{
//    int isSQFree[MAX]={0}, dat[MAX][10]={0};
//    int t, a, b, d, temp;
//    dat[0][0]=1;
//
//    for(int i=2;i<316;i++)
//    {
//        if(isSQFree[i]==0)
//        {
//            temp=i*i;
//            for(int j=temp;j<MAX;j+=temp)
//            {
//                isSQFree[j]=1;
//            }
//        }
//    }
//
//    for(int i=1;i<MAX;i++)
//    {
//        if(isSQFree[i]==0)
//        {
//            temp=i;
//            while(temp!=0)
//            {
//                dat[i][temp%10]=1;
//                temp/=10;
//            }
//            for(int j=0;j<10;j++)
//            {
//                dat[i][j]+=dat[i-1][j];
//            }
//        }
//        else
//        {
//            for(int j=0;j<10;j++)
//            {
//                dat[i][j]=dat[i-1][j];
//            }
//        }
//    }
//    cin>>t;
//    while(t--)
//    {
//        cin>>a>>b>>d;
//        cout<<dat[b][d]-dat[a-1][d]<<endl;
//    }
//    return 0;
//}
