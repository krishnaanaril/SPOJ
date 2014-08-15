    /*
	SPOJ : FCTRL
	Status: Accepted
	Date: 8/12/2014
    */
    #include <iostream>
    #include <math.h>
    #include <vector>
    #include <bitset>
     
    #define MAX 1000000001
    #define LIM 40000
     
    typedef unsigned long long ull;
     
    using namespace std;
     
    int main()
    {
	    int count=0,t;
	    ull temp, n;
	    cin>>t;
	    while(t--)
	    {
		    cin>>n;
		    temp=count=n/5;
		    while(temp)
		    {
			    count=count+(temp/5);
			    temp/=5;
		    }
		    cout<<count<<endl;
	    }
	    return 0;
     
    } 
