/*
    Name: Krishna Mohan
    Date: 3/5/2015
    Algorithm: MO's algorithm
    Site: SPOJ
    Contest: DQUERY   
*/
#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

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

#define N 200005
#define A 1000007
#define BLOCK 447 // sqrt of N

class FastInput 
{
    public:
    FastInput() 
    {
        m_dataOffset = 0;
        m_dataSize = 0;
        m_v = 0x80000000;
    }
    uint32_t ReadNext() {
        if (m_dataOffset == m_dataSize) 
        {
            int r = read(0, m_buffer, sizeof(m_buffer));
            if (r <= 0) return m_v;
            m_dataOffset = 0;
            m_dataSize = 0;
            int i = 0;
            if (m_buffer[0] < '0') {
                if (m_v != 0x80000000) {
                    m_data[m_dataSize++] = m_v;
                    m_v = 0x80000000;
                }
                for (; (i < r) && (m_buffer[i] < '0'); ++i);
            }
            for (; i < r;) {
                if (m_buffer[i] >= '0') {
                    m_v = m_v * 10 + m_buffer[i] - 48;
                    ++i;
                } 
                else {
                    m_data[m_dataSize++] = m_v;
                    m_v = 0x80000000;
                    for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
                }
            }   
        }
        return m_data[m_dataOffset++];
    }
    public:
        uint8_t m_buffer[32768];
        uint32_t m_data[16384];
        size_t m_dataOffset, m_dataSize;
        uint32_t m_v;
};

class FastOutput {
    public:
    FastOutput() {
        m_dataOffset = 0;
    }
    ~FastOutput() {
    }
    void Flush() {
        if (m_dataOffset) {
        if (write(1, m_data, m_dataOffset));
            m_dataOffset = 0;
        }
    }
void PrintUint(uint32_t v, char d) {
    if (m_dataOffset + 11 > sizeof(m_data)) Flush();
    if (v < 100000) {
        if (v < 1000) {
            if (v < 10) {
                m_data[m_dataOffset + 0] = v + 48;
                m_dataOffset += 1;
            } 
            else if (v < 100) {
                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 0] = v + 48;
                m_dataOffset += 2;
            } 
            else {
                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 0] = v + 48;
                m_dataOffset += 3;
            }
        } 
        else {
            if (v < 10000) {
                m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 0] = v + 48;
                m_dataOffset += 4;
            } 
            else {
                m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 0] = v + 48;
                m_dataOffset += 5;
               }
            }
        } 
        else {
        if (v < 100000000) {
            if (v < 1000000) {
                m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 0] = v + 48;
                m_dataOffset += 6;
            } 
            else if (v < 10000000) {
                m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 0] = v + 48;
                m_dataOffset += 7;
            } 
            else {
                m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 0] = v + 48;
                m_dataOffset += 8;
            }
        } 
        else {
            if (v < 1000000000) {
                m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 0] = v + 48;
                m_dataOffset += 9;
            } 
            else {
                m_data[m_dataOffset + 9] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                m_data[m_dataOffset + 0] = v + 48;
                m_dataOffset += 10;
                }
            }
        }
        m_data[m_dataOffset++] = d;
    }
    void PrintChar(char d) {
        if (m_dataOffset + 1 > sizeof(m_data)) Flush();
        m_data[m_dataOffset++] = d;
    }
    void ReplaceChar(int offset, char d) {
        m_data[m_dataOffset + offset] = d;
    }
    public:
        uint8_t m_data[32768];
        size_t m_dataOffset;
};
 
 
 
FastInput g_fi;
 
FastOutput g_fo;


int cnt[A], dat[N], ans[N], answer=0;

struct node
{
    int l,r,i;
};

void add(int pos)
{   
    cnt[dat[pos]]++;
    if(cnt[dat[pos]]==1)
        answer++;
}

void remove(int pos)
{
    cnt[dat[pos]]--;
    if(cnt[dat[pos]]==0)
        answer--;
}

bool cmp(node a, node b)
{
    if(a.l/BLOCK!=b.l/BLOCK)
        return a.l<b.l;
    return a.r<b.r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, currL, currR;
    node q[N];
    //cin>>n;
    n=g_fi.ReadNext();
    fo(i, n)
    {
        //cin>>dat[i];
        dat[i]=g_fi.ReadNext();
    }
    //cin>>m;
    m=g_fi.ReadNext();
    fo(i, m)
    {
        //cin>>q[i].l>>q[i].r;
        q[i].l=g_fi.ReadNext();
        q[i].r=g_fi.ReadNext();
        q[i].l--, q[i].r--;
        q[i].i=i;
    }
    sort(q, q+m, cmp);
    currL=0, currR=0;
    fo(i, m)
    {
        while(currL<q[i].l)
        {
            remove(currL);
            currL++;
        }
        while(currL>q[i].l)
        {
            add(currL-1);
            currL--;
        }
        while(currR<=q[i].r)
        {
            add(currR);
            currR++;
        }
        while(currR>q[i].r+1)
        {
            remove(currR-1);
            currR--;
        }
        ans[q[i].i]=answer;
    }
    fo(i, m)
    {
        //cout<<ans[i]<<endl;
        g_fo.PrintUint(ans[i], '\n');        
    }
    g_fo.Flush();
    return 0;
}
