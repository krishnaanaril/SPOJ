/*
	SPOJ : PRIME1
	Status: Accepted
	Date: 8/12/2014
*/
#include <iostream>
#include <math.h>
#include <vector>
#include <bitset>

#define MAX 1000000001
#define LIM 40000

using namespace std;

int main()
{
	bitset<LIM> isPrime;
	vector<int> primes;
	int t,m,n,flag;

	isPrime.flip();
	isPrime[0]=isPrime[1]=0;
	for(int i=4;i<LIM;i+=2)
	{
		isPrime[i]=0;
	}
	primes.push_back(2);
	for(int i=3;i<LIM;i+=2)
	{
		if(isPrime[i])
		{
			primes.push_back(i);
			for(int j=2*i;j<LIM;j+=i)
			{
				isPrime[j]=0;
			}
		}
	}
	
	cin>>t;
	while (t--)
	{
		cin>>m>>n;
		m==1?m++:m;
		for(int i=m;i<=n;i++)
		{
			flag=0;
			for (int j = 0; primes[j] <= sqrt(i); j++)
			{
				if(i%primes[j]==0)
				{
					flag=1;
					break;
				}
			}
			if (flag==0)
			{
				cout<<i<<endl;
			}
		}
		cout<<endl;
	}

	return 0;
}

