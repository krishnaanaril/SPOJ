#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, tmp;
    vector<double> dist, spd;
    vector<pair<double, int> > time;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &tmp);
        spd.push_back(tmp);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d", &tmp);
        dist.push_back(tmp);
    }
    for(int i=0;i<n;i++)
    {        
        time.push_back(pair<double, int>(dist[i]/spd[i], i));
        //printf("%f, %d\n", dist[i]/spd[i], i+1);
    }
    sort(time.begin(), time.end());
    double f = time[0].first;
    for(int i=0;i<n;i++)
    {
        if(time[i].first==f)
            printf("%d\n", time[i].second+1);
        else
            break;
    }
    return 0;
}
