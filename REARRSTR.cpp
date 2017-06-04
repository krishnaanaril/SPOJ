#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

typedef pair<int, int> pii;
vector<pii> dat;

int main()
{
    int t, pos[MAX], cnt[26], sz, idx;
    char str[MAX], ans[MAX];
    scanf("%d", &t);
    while(t--)
    {
        dat.clear();
        //memset(pos, 0, sizeof(pos));
        memset(cnt, 0, sizeof(cnt));
        scanf("%s", str);
        sz = strlen(str);
        ans[sz]='\0';
        for(int i=0;i<sz;i++)
        {
            cnt[str[i]-'a']++;
        }
        int flag=0;
        int mid=ceil(sz/2.0);
        for(int i=0;i<26;i++)
        {
            if(cnt[i]>mid)
            {
                flag=1;
                break;
            }                
        }
        if(!flag)
        {
            idx=0;
            for(int i=0;i<sz;i+=2)
            {
                pos[idx++]=i;
            }
            for(int i=1;i<sz;i+=2)
            {
                pos[idx++]=i;
            }
            for(int i=0;i<26;i++)
            {
                if(cnt[i])
                    dat.push_back(pii(cnt[i], i));
            }
            sort(dat.begin(), dat.end(), greater<pii>());
            sz=dat.size();
            idx=0;
            for(int i=0;i<sz;i++)
            {
                //printf("%c %d\n", dat[i].second+'a', dat[i].first);
                while(dat[i].first)
                {
                    //printf("%d\n", pos[idx]);
                    ans[pos[idx]]=dat[i].second+'a';
                    idx++;
                    dat[i].first--;
                }
            }
            printf("%s\n", ans);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
