/*
    Name: Krishna Mohan
    Date: 3//2015
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
#define MAX 100
#define INF 1000000007
#define MOD 1000000007
#define INPUTFILE 1

const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;

int main()
{
    #ifndef INPUTFILE
        freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int t, arra[26], arrb[26], sza, szb, f;
    string a, b;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        ini(arra, 0);
        ini(arrb, 0);        
        getline(cin, a);
        getline(cin, b);
        cout<<a<<endl<<b<<endl;
        /*if(a.size()<b.size())
            swap(a, b);*/
        sza=a.size();
        szb=b.size();
        //cout<<sza<<", szb: "<<szb<<endl;
        fo(i, sza)
        {
            if(a[i]==' ')
                continue;
            arra[a[i]-'a']++;
            //cout<<(a[i]-'a')<<" -> "<<arra[a[i]-'a']<<endl;
        }
        /*fo(i, 26)
        {
            cout<<(char)(i+'a')<<" -> "<<arra[i]<<endl;
        }*/
        fo(i, szb)
        {
            if(a[i]==' ')
                continue;
            arrb[b[i]-'a']++;
        }
        /*fo(i, 26)
        {
            int temp=min(arra[i], arrb[i]);
            arra[i]-=temp;
            arrb[i]-=temp;
        }*/
        if(szb<sza)
        {
            fo(i, szb)
            {
                if(arra[b[i]-'a']!=0)
                {
                    arra[b[i]-'a']--;
                    arrb[b[i]-'a']--;
                }                
            }
        }
        else
        {
            fo(i, sza)
            {
                if(arrb[a[i]-'a']!=0)
                {
                    arrb[a[i]-'a']--;
                    arra[a[i]-'a']--;
                }  
            }
        }
        /*cout<<"After:\n";
        fo(i, 26)
        {
            cout<<(char)(i+'a')<<" -> "<<arra[i]<<endl;
        }*/
        int isAZ=0, isBZ=0;
        fo(i, sza)
        {
            if(arra[i]>0)
            {
                isAZ=1;
                break;
            }
        }
        fo(i, szb)
        {
            if(arrb[i]>0)
            {
                isBZ=1;
                break;
            }
        }
        //cout<<isAZ<<" : "<<isBZ<<endl;
        if(isAZ && !isBZ)
        {
            cout<<"You win some."<<endl;    
        }
        else if(!isAZ && isBZ)
        {
            cout<<"You lose some."<<endl;    
        }
        else
        {
            cout<<"You draw some."<<endl;    
        }
    }
    return 0;
}
