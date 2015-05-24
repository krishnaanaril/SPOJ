///*
//    SPOJ: TAP2013G
//    Status: Accepted. Onl when set was changed to vector
//    Date: 8/23/2014
//*/
//
//#include <bits/stdc++.h>
//
//typedef long long ll;
//
//using namespace std;
//
//int main()
//{
//    int s;
//    ll temp, count=0;
//    vector<ll> q, n;
//    cin>>s;
//    for(ll i=0;i<s;i++)
//    {
//        cin>>temp;
//        q.push_back(temp);
//    }
//    for(ll i=0;i<s;i++)
//    {
//        cin>>temp;
//        n.push_back(temp);
//    }
//
//    sort(q.begin(), q.end());
//    sort(n.begin(), n.end());
//    //set<ll>::iterator it1=q.begin(), it2=n.begin();
//    ll i=0, j=0;
//    while(i<s && j<s)
//    {
//        //cout<<"it1: "<<*it1<<" it2: "<<*it2<<endl;
//        if(q[i]<n[j])
//        {
//            count++;
//            i++;
//            j++;
//        }
//        else
//        {
//            j++;
//        }
//    }
//    cout<<count<<endl;
//    return 0;
//}
