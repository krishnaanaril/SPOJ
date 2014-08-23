///*
//    SPOJ: CUBEFR
//    Status:
//    Date: 8/16/2014
//*/
//
//#include <bits/stdc++.h>
//
//#define  MAX 1000001
//
//using namespace std;
//
//int main()
//{
//    int loc[MAX], t, n, pos, temp;
//    bitset<MAX> isCFree;
//    isCFree.flip();
//    loc[1]=1;
//    pos=2;
//    for(int i=2;i<101;i++)
//    {
//        temp=i*i*i;
//        for(int j=temp;j<MAX;j+=temp)
//        {
//            isCFree[j]=0;
//        }
//    }
//    for(int i=2;i<MAX;i++)
//    {
//        if(isCFree[i])
//        {
//            loc[i]=pos++;
//        }
//    }
//    cin>>t;
//    for(int i=0;i<t;i++)
//    {
//        cin>>n;
//        if(isCFree[n])
//        {
//            cout<<"Case "<<(i+1)<<": "<<loc[n]<<endl;
//        }
//        else
//        {
//            cout<<"Case "<<(i+1)<<": "<<"Not Cube Free"<<endl;
//        }
//    }
//    return 0;
//}
