///*
//    SPOJ: BITMAP
//    Status: Accepted. After a lot of TLE
//    Date: 8/23/2014
//*/
//
//#include <bits/stdc++.h>
//
//#define MAX 200
//#define INF 1e9
//
//using namespace std;
//
//int main()
//{
//    int t, n, m;
//    char dat[MAX][MAX];
//    int ans[MAX][MAX];
//    pair<int, int> temp, next;
//    vector< pair<int, int> > loc;
////    queue<int> q;
//    int it=0;
//
//
//    cin>>t;
//    while(t--)
//    {
//        int visited[MAX][MAX]={0};
//        queue< pair<int, int> > q;
//        cin>>n>>m;
//        loc.clear();
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<m;j++)
//            {
//                ans[i][j]=INF;
//            }
//            //cout<<endl;
//        }
//        //cout<<ans[n-1][m-1]<<endl;
//
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<m;j++)
//            {
//                //scanf("%c", &dat[i][j]);
//                cin>>dat[i][j];
//                if(dat[i][j]=='1')
//                {
//                    temp.first=i;
//                    temp.second=j;
//                    ans[i][j]=0;
//                    //loc.push_back(temp);
//                    q.push(temp);
//                    visited[temp.first][temp.second]=1;
//                }
//            }
//        }
//
//
//        while(!q.empty())
//        {
//            it++;
//            temp=q.front();
//            q.pop();
//            //cout<<temp.first<<" : "<<temp.second<<endl;
//            if(temp.first-1>=0 && dat[temp.first-1][temp.second]!='1' && visited[temp.first-1][temp.second]==0)
//            {
//                if(ans[temp.first-1][temp.second]>ans[temp.first][temp.second]+1)
//                {
//                    ans[temp.first-1][temp.second]=ans[temp.first][temp.second]+1;
//                    next.first=temp.first-1;
//                    next.second=temp.second;
//                    visited[temp.first-1][temp.second]=1;
//                    q.push(next);
//                }
//
//            }
//            if(temp.first+1<n && dat[temp.first+1][temp.second]!='1' && visited[temp.first+1][temp.second]==0)
//            {
//                if(ans[temp.first+1][temp.second]>ans[temp.first][temp.second]+1)
//                {
//                    ans[temp.first+1][temp.second]=ans[temp.first][temp.second]+1;
//                    next.first=temp.first+1;
//                    next.second=temp.second;
//                    visited[temp.first+1][temp.second]=1;
//                    q.push(next);
//                }
//
//            }
//            if(temp.second-1>=0 && dat[temp.first][temp.second-1]!='1' && visited[temp.first][temp.second-1]==0)
//            {
//                if(ans[temp.first][temp.second-1]>ans[temp.first][temp.second]+1)
//                {
//                    ans[temp.first][temp.second-1]=ans[temp.first][temp.second]+1;
//                    next.first=temp.first;
//                    next.second=temp.second-1;
//                    visited[temp.first][temp.second-1]=1;
//                    q.push(next);
//                }
//            }
//            if(temp.second+1<m && dat[temp.first][temp.second+1]!='1' && visited[temp.first][temp.second+1]==0)
//            {
//                if(ans[temp.first][temp.second+1]>ans[temp.first][temp.second]+1)
//                {
//                    ans[temp.first][temp.second+1]=ans[temp.first][temp.second]+1;
//                    next.first=temp.first;
//                    next.second=temp.second+1;
//                    visited[temp.first][temp.second+1]=1;
//                    q.push(next);
//                }
//            }
//        }
//
//        //cout<<"It: "<<it<<endl;
//        //output
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<m;j++)
//            {
//                printf("%d ", ans[i][j]);
//                //cout<<ans[i][j]<<" ";
//            }
//            cout<<endl;
//        }
//    }
//    return 0;
//}
