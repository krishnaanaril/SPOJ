///*
//    SPOJ: HISTOGRA
//    Status: Referred GeeksforGeeks, but no idea about the stacks...:(
//    Date: 8/22/2014
//*/
//
//#include <bits/stdc++.h>
//
//typedef long long ll;
//
//using namespace std;
//
//
//
////void print(stack<int> &s)
////{
////    if(s.empty())
////    {
////        cout << "";
////        return;
////    }
////    int x= s.top();
////    s.pop();
////    print(s);
////    s.push(x);
////    cout << dat[x] << " ";
//// }
//
//int main()
//{
//    ll n,temp, i;
//    vector<ll> dat;
//    stack<ll> stk;
//    ll maxarea, currarea;
//
//    while(cin>>n)
//    {
//        dat.clear();
//        if(n==0)
//        {
//            break;
//        }
//        for(ll i=0;i<n;i++)
//        {
//            cin>>temp;
//            dat.push_back(temp);
//        }
//        i=0;
//        maxarea=0;
//        while(i<n)
//        {
//            if(stk.empty() || dat[stk.top()]<=dat[i])
//            {
//                stk.push(i++);
//            }
//            else
//            {
//                temp=stk.top();
//                stk.pop();
//                currarea=dat[temp]*(stk.empty()?i:i-stk.top()-1);
////                cout<<"Val: "<<dat[temp]<<" i:"<<i<<" top: "<<(stk.empty()?i:i-stk.top()-1)<<" Area: "<<currarea<<endl;
////                cout<<"Stack: ";
////                print(stk);
////                cout<<endl;
//                if(currarea>maxarea)
//                {
//                    maxarea=currarea;
//                }
//            }
//        }
//        while(!stk.empty())
//        {
//            temp=stk.top();
//            stk.pop();
//            currarea=dat[temp]*(stk.empty()?i:i-stk.top()-1);
////            cout<<"Val: "<<dat[temp]<<" i:"<<i<<" top: "<<(stk.empty()?i:i-stk.top()-1)<<" Area: "<<currarea<<endl;
//            if(currarea>maxarea)
//            {
//                maxarea=currarea;
//            }
//        }
//        cout<<maxarea<<endl;
//    }
//    return 0;
//}
