    /*
    	SPOJ : LASTDIG
    	Status: Accepted
	Date: 8/13/2014
    */
    #include <iostream>
    #include <math.h>
    #include <vector>
    #include <bitset>
    #include <string>
     
    typedef unsigned long long ull;
     
    using namespace std;
     
    long gcd(long a, long b)
    {
	    if(b==0)
    		return a;
	    else
    		return gcd(b, a%b);
    }
     
    int main()
    {
	    int t, flag;
	    double dat,temp;
	    string num;
	    long idat, count, q, p;
	    cin>>t;
	    while (t--)
	    {
		    count=0, q=1, p=0, flag=0;
		    cin>>num;
		    for (int i = 0; i < num.length(); i++)
		    {
			    if(num[i]=='.')
			    {
			    	flag=1;
			    	continue;
			    }
			    if (flag==1)
			    {
			    	q=q*10;
			    }
			    p=p*10+(num[i]-'0');
		    }
		    cout<<q/gcd(p,q)<<endl;
	    }
	    return 0;
    } 
