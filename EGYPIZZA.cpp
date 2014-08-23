///*
//    SPOJ: EGYPIZZA
//    Status: Accepted. Solved without referring..:D
//    Date: 8/23/2014
//*/
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main()
//{
//    int n, q, h, q3, count;
//    string temp;
//    q=h=q3=count=0;
//
//    cin>>n;
//    for(int i=0;i<n;i++)
//    {
//        cin>>temp;
//        if(temp== "3/4"){
//            q3++;
//        }
//        else if(temp=="1/4")
//        {
//            q++;
//        }
//        else if(temp=="1/2")
//        {
//            h++;
//        }
//    }
//    cout<<q3<<" "<<q<<" "<<h<<endl;
//    count+=q3;
//    count+=h&1?(h/2)+1:(h/2);
//    q-=q3;
//    if(h&1)
//    {
//        q-=2;
//    }
//    if(q>0)
//    {
//      count+=(q/4)+1;
//    }
//    cout<<count+1<<endl;
//    return 0;
//}
