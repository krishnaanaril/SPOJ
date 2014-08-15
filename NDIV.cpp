/*
	SPOJ: NDIV
	Status: Accepted
	Date: 8/13/2014
*/
#include <bits/stdc++.h>

#define MAX 1000000
#define LIM 40000

using namespace std;

int main()
{
    //cout<<"NDIV"<<endl;
    vector<int> primes;
    bitset<LIM> isPrime;
    long a, b, n, count=0, ans=0, temp, total=1;
    isPrime.flip();

    for(int i=2;i<LIM;i+=2)
    {
        isPrime[i]=0;
    }
    primes.push_back(2);
    for(int i=3;i<(LIM);i+=2)
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
    cin>>a>>b>>n;
    for(int i=a;i<=b;i++)
    {

        temp=i;
        total=1;
        int k=0;
        for(int j=0; primes[j]<=sqrt(temp);j++)
        {
            count=0;
            //cout<<"temp: "<<temp<<endl;
            while(temp%primes[j]==0)
            {
                //cout<<"temp loop: "<<temp<<endl;
                count++;
                temp/=primes[j];
            }
            //cout<<"count: "<<count<<endl;
            total *=count+1;
        }
        //cout<<"i: "<<i<<" total:"<<total<<endl;
        if(temp!=1)
            total*=2;
        if(total==n)
        {
            //cout<<"i: "<<i<<" temp: "<<temp<<endl;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}


