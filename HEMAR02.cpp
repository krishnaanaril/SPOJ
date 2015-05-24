/*
    Name: Krishna Mohan
    Date: //2015
    Algorithm:
    Site:
    Contest:
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;
typedef vector<pi> vpi;

// Basic macros
#define fi          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fo(i,n)     re(i,0,n)
#define rev(i,n,s)  for(int i=(n)-1;i>=s;--i)
#define repv(i,n,s) for(int i=(n);i>=s;--i)
#define fov(i,n)    rev(i,n,0)
#define pb          push_back
#define mp          make_pair
#define si(x)       (int)(x.size())
#define MAX 100001
#define INF 1000000007
#define MOD 1000000007

int fi(int n) 
 { 
   int result = n; 
   for(int i=2;i*i <= n;i++) 
   { 
     if (n % i == 0) result -= result / i; 
     while (n % i == 0) n /= i; 
   } 
   if (n > 1) result -= result / n; 
   return result; 
 } 

bitset<MAX> isPrime;

void init()
{
    isPrime.set();
    isPrime[0]=isPrime[1]=0;
    for(int i=4;i<MAX;i+=2)
        isPrime[i]=0;
    for(int i=3;i<MAX;i++)
    {
        if(isPrime[i])
        {
            for(int j=2*i;j<MAX;j+=i)
            {
                isPrime[j]=0;                
            }
        }
    }    
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, t;
    init();
    cin>>t;
    while(t--)
    {
        cin>>n;
        //cout<<fi(n)<<endl;
        if(isPrime[fi(n)])
        {
            cout<<"TRUE"<<endl;
        }
        else
        {
            cout<<"FALSE"<<endl;
        }
    }
    return 0;
}
