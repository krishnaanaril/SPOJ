///*
//    SPOJ: FEELUCK
//    Status: Accepted
//    Date: 8/17/2014
//*/
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main()
//{
//    list<string>URL[101];
//	list<string>::iterator it;
//
//    int t, v, m;
//    string site;
//    cin>>t;
//    for(int k=0;k<t;k++)
//    {
//        m=0;
//        for(int i=0;i<101;i++)
//        {
//            URL[i].clear();
//        }
//        for(int i=0;i<10;i++)
//        {
//            cin>>site>>v;
//            URL[v].push_back(site);
//            m=max(m,v);
//        }
//        cout<<"Case #"<<(k+1)<<":"<<endl;
//        for(it=URL[m].begin();it!=URL[m].end();it++)
//        {
//            cout<<*it<<endl;
//        }
//    }
//    return 0;
//}
