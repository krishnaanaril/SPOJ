/*
	SPOJ: GCJ1C09A
	Status: Accepted
	Date: 8/15/2014
*/

#include  <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

int main()
{
	int t,k=0;
	string str;
	ull ans, base;
	map<char, int> dat;
	char first, second;
	cin>>t;
	while (t--)
	{
		ans=0;
		dat.clear();
		cin>>str;
		for (int i = 0, j=0; i < str.size(); i++)
		{
			if (dat.find(str[i])==dat.end())
			{
				if (j==0)
				{
					first=str[i];
				}
				else if (j==1)
				{
					second=str[i];
				}
				dat[str[i]]=j++;
			}
		}
		dat[first]=1;
		dat[second]=0;
		base=dat.size();
		for (int i = 0, j=str.size()-1; i < str.size(); i++,j--)
		{
			//ans+=dat[str[i]]*pow(base, j);
			ans=ans*base+dat[str[i]];
		}
		cout<<"Case #"<<(++k)<<": "<<ans<<endl;
	}
	return 0;
}




