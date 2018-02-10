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
#define MAX 100
#define INF 1000000007
#define MOD 1000000007

int stoi(string str, int sz)
{
    int ans=0;
    fo(i, sz)
    {
        ans=ans*10+(str[i]-'0');
    }
    return ans;
}



struct div8
{
    int num;
    int len;
    int digCount[10];
};

vector<div8> nums;
int N;

void init()
{
    div8 temp;
    int n;
    
    fo(i, 1000)
    {        
        if(i%8==0)
        {
            n=i;
            temp.num=n;
            temp.len=0;
            ini(temp.digCount,0);
            if(n<10)
            {
                temp.digCount[0]+=2;
                temp.len=2;
                while(n)
                {
                    temp.digCount[n%10]++;
                    temp.len++;
                    n/=10;
                }   
                nums.pb(temp);
            }
            else if(n<100)
            {
                temp.digCount[0]+=1;
                temp.len=1;
                while(n)
                {
                    temp.digCount[n%10]++;
                    temp.len++;
                    n/=10;
                }   
                nums.pb(temp);
            }
            ini(temp.digCount,0);
            if(i==0)
                continue;
            n=i;
            temp.len=0;
            while(n)
            {
                temp.digCount[n%10]++;
                temp.len++;
                n/=10;
            }   
            nums.pb(temp);
        }
    }
    N=nums.size();
    /*fo(i, N)
    {
        cout<<nums[i].num<<" "<<nums[i].len<<" : ";
        fo(j, 10)
        {
            if(nums[i].digCount[j])
                cout<<j<<"->"<<nums[i].digCount[j]<<" ";
        }
        cout<<endl;
    }*/
}

int main()
{
    ios_base::sync_with_stdio(0);
    init();
    string str;
    
    int sz, strDigs[10]={0}, f=0, t, x=1;
    cin>>t;
    //cout<<t<<endl;
    while(t--)
    {
        cin>>str;
        sz=str.size();
        ini(strDigs, 0);
        /*if(sz<2)
            strDigs[0]+=2;
        else if(sz<3)
            strDigs[0]+=1;*/
        fo(i, sz)
        {
            strDigs[str[i]-'0']++;
        }               
        /*fo(i, 10)
            cout<<strDigs[i]<<" _ ";
        cout<<endl;*/
        fo(i, N)
        {
            f=0;
            fo(j, 10)
            {
                if(strDigs[j]<nums[i].digCount[j])
                {
                    f=1; break;   
                }
                //cout<<nums[i].digCount[j]<<" ";
            }
            //cout<<endl;
            /*if(nums[i].num==8)
            {
                cout<<f<<endl;
                cout<<"8-> "<<nums[i].len<<" "<<endl;
                fo(k, 10)
                    cout<<nums[i].digCount[k]<<" ";
                cout<<endl;
            }*/
            /*if(f==0)
                cout<<nums[i].num<<"-> "<<nums[i].len<<" "<<f<<" "<<sz<<endl;*/
            if(f==0 && (sz>=3 || (sz<3 && (sz==nums[i].len))))
            { 
                f=0;   
                //cout<<"num: "<<nums[i].num<<" len: "<<nums[i].len<<endl;
                break;
            }    
        }
        //cout<<f<<" : "<<sz<<endl;
        if(!f && (sz>1 || str=="8"))
        {
            cout<<x<<": YES"<<endl;
        }
        else
            cout<<x<<": NO"<<endl;
        x++;
    }
    return 0;
}
