/*
	SPOJ : LASTDIG
	Status: Accepted
	Date: 8/13/2014
*/
#include <iostream>
#include <math.h>
#include <vector>
#include <bitset>

using namespace std;

int main()
{
	int t;
	int a,b, ans;
	cin>>t;
	while (t--)
	{
		cin>>a>>b;
		ans = (b==0)? 1: pow((double)a,(b%4==0?4:b%4));
		cout<<ans%10<<endl;
	}
	return 0;
}

