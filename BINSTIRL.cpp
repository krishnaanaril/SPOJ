    /*
	    SPOJ : BINSTIRL
	    Status: Accepted     
	    Source: Wikipedia : Stirling number of Second kind parity
	    Date: 8/12/2014	
    */
    #include <iostream>
    #include <math.h>
    #include <vector>
    #include <bitset>
     
    using namespace std;
     
    int main()
    {
	    int t,m,n;
	    cin>>t;
	    while (t--)
	    {
		    cin>>m>>n;
		    if (( (m-n)&((n-1)/2) ))
		    {
		    	cout<<0<<endl;
		    }
		    else
		    {
		    	cout<<1<<endl;
		    }
	    }
	    return 0;
    } 


