#include <bits/stdc++.h>

using namespace std;

#define MAX 100005

typedef pair<int, int> pii;
typedef vector<int> vi;

int t, n, m, x, y, curr, v, cnt, sz, ans;
int sems[MAX];
bitset<MAX> isVisited, isPushed;
map<int, vi> graph, parent;
stack<int> stk;
bool isCycle;

inline bool solve(int v, int cnt)
{    
    if(isVisited[v] == false)
    {
        sems[v]=max(sems[v],cnt);
        // Mark the current node as visited and part of recursion stack
        isVisited[v] = true;
        isPushed[v] = true;
 
        // Recur for all the vertices adjacent to this vertex
        vector<int>::iterator i;
        for(i = graph[v].begin(); i != graph[v].end(); ++i)
        {
            /*if(v==5)
                cout<<"i:"<<*i<<": "<<sems[*i]<<":"<<sems[v]<<endl;*/
            if ( (!isVisited[*i]) && solve(*i, sems[v]+1) )
                return true;
            else if (isPushed[*i])
                return true;
        } 
    }
    isPushed[v] = false;  // remove the vertex from recursion stack
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>t;
    for(int it=1;it<=t;it++)
    {
        parent.clear();
        memset(sems, -1, sizeof(sems));
        graph.clear();            
        curr=-1;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            parent[y].push_back(x);
            graph[x].push_back(y);
        }
        isCycle=false;
        for(int i = 0; i < n; i++)
        {
            if (solve(i, 1))
            {    
                isCycle = true;
                break;
            }
            cout<<"sems: ";
            for(int i=0;i<n;i++)
            {   
                cout<<sems[i]<<" ";
            }
            cout<<endl;
        }
        /*if(isCycle)
            cout << "Graph contains cycle\n";
        else
            cout << "Graph doesn't contain cycle\n";*/
        cnt=0, ans=-1;
        for(int i=0;i<n;i++)
        {
            int sz=parent[i].size(); curr=0;
            for(int j=0;j<sz;j++)
            {
                curr = max(curr, sems[parent[i][j]]);
            }
            cout<<"curr: "<<curr<<endl;
            ans=max(curr+1, ans);
        }
        //cout<<cnt<<" : "<<ans<<endl;
        if(!isCycle)
        {
            cout<<"Case "<<it<<": "<<ans<<" semester(s)\n";
        }
        else
        {
            cout<<"Case "<<it<<": Never Ends\n";
        }
    }
    return 0;
}
