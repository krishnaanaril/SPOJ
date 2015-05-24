    /*
	SPOJ: GCJ101BB
	Status: Accepted
	Date:8/14/2014
    */	

    #include <iostream>
    #include <vector>
     
    using namespace std;
     
    int main()
    {
	    int c,i=0;
	    long n, k, b, t, temp, red, blue, ans=0;
	    vector<long> pos, vel;
	    cin>>c;
	    while (c--)
	    {
		    red=blue=ans=0;
		    pos.clear();
		    vel.clear();
		    cin>>n>>k>>b>>t;
		    for (int i = 0; i < n; i++)
		    {
		    	cin>>temp;
		    	pos.push_back(temp);
		    }
		    for (int i = 0; i < n; i++)
		    {
		    	cin>>temp;
		    	vel.push_back(temp);
		    }
		     
		    for (int i = n-1; i >=0 ; i--)
		    {
			    if (red==k)
			    {
			    	break;
			    }
			    if(t*vel[i]+pos[i]<b)
			    {
		    		blue++;
			    }
			    else
			    {
		    		red++;
			    	ans+=blue;
			    }
		    }
		    if (red>=k)
		    {
		    	cout<<"Case #"<<(i+1)<<": "<<ans<<endl;
		    }
		    else
		    {
		    	cout<<"Case #"<<(i+1)<<": "<<"IMPOSSIBLE"<<endl;
		    }
		    i++;
	    }
	    return 0;
    } 


