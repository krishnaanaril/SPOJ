    /*
	SPOJ: ABCDEF
	Status: Accepted
	Date: 9/11/2013
    */
    #include <vector>
    #include <list>
    #include <map>
    #include <set>
    #include <queue>
    #include <deque>
    #include <stack>
    #include <bitset>
    #include <algorithm>
    #include <functional>
    #include <numeric>
    #include <utility>
    #include <sstream>
    #include <iostream>
    #include <iomanip>
    #include <cstdio>
    #include <cmath>
    #include <cstdlib>
    #include <ctime>
     
    using namespace std;
     
    #define SIZE 101
    #define MAX 2000
     
    int arr1[2000000];
     
    int main()
    {
	    int n, tmp, ans,t;
	    /*vector<int> dat,arr1;*/
	    /*map<int, int> m1, m2;*/
	    int dat[SIZE];
	    cin>>n;
	    for(int i=0;i<n;i++)
	    {
	    	cin>>dat[i];
	    }
	    tmp=ans=0;
	    for(int i=0;i<n;i++)
	    {
		    if(dat[i])
		    {
			    for(int j=0;j<n;j++)
			    {
				    for(int k=0;k<n;k++)
				    {
				    arr1[tmp++]=dat[i]*(dat[j]+dat[k]);
				    }
			    }
		    }
	    }
	     
	    sort(arr1,arr1+tmp);
	     
	    for(int i=0;i<n;i++)
	    {
		    for(int j=0;j<n;j++)
		    {
			    for(int k=0;k<n;k++)
			    {
				    t=dat[i]*dat[j]+dat[k];
				    ans+= upper_bound(arr1,arr1+tmp,t)-lower_bound(arr1,arr1+tmp,t);
			    }
		    }
	    }
	    cout<<ans<<endl;
	    return 0;
    } 
