#include <bits/stdc++.h>

#define MAX 100005
#define X first
#define Y second
#define INF INT_MAX

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

vpii poly;
vector<vpii> dat;
pii point;

int t, n, m, x, y;
int ans[MAX], sz[MAX];

bool onSegment(pii p, pii q, pii r)
{
    if (q.X <= max(p.X, r.X) && q.X >= min(p.X, r.X) &&
            q.Y <= max(p.Y, r.Y) && q.Y >= min(p.Y, r.Y))
        return true;
    return false;
}

int orientation(pii p, pii q, pii r)
{
    int val = (q.Y - p.Y) * (r.X - q.X) -
              (q.X - p.X) * (r.Y - q.Y);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool doIntersect(pii p1, pii q1, pii p2, pii q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
 
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false; // Doesn't fall in any of the above cases
}

bool isInside(int a, int b, int n)
{
    //printf("In isInside a:%d b:%d n:%d dtsz:%d\n", a, b, n, dat[b].size());
    // There must be at least 3 vertices in polygon[]
    if (n < 3)  return false;
 
    // Create a point for line segment from p to infinite
    pii extreme = pii(INF, dat[b][0].Y);
 
    // Count intersections of the above line with sides of polygon
    int count = 0, i = 0;
    
    do
    {
        int next = (i+1)%n;
        //printf("i: %d next:%d\n", i, next);
        // Check if the line segment from 'p' to 'extreme' intersects
        // with the line segment from 'polygon[i]' to 'polygon[next]'
        if (doIntersect(dat[a][i], dat[a][next], dat[b][0], extreme))
        {
            // If the point 'p' is colinear with line segment 'i-next',
            // then check if it lies on segment. If it lies, return true,
            // otherwise false
            if (orientation(dat[a][i], dat[b][0], dat[a][next]) == 0)
               return onSegment(dat[a][i], dat[b][0], dat[a][next]);
 
            count++;
        }
        i = next;
    } while (i != 0);
 
    printf("i:%d j:%d ans:%d\n", a, b, count&1);
    // Return true if count is odd, false otherwise
    return count&1;  // Same as (count%2 == 1)
}

void solve()
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            printf("Checking %d and %d\n", i, j);
            if(isInside(i, j, sz[i]))
                ans[i]++, printf("%d is inside %d\n", i, j);
            printf("Checking %d and %d\n", j, i);
            if(isInside(j, i, sz[j]))
                ans[j]++, printf("%d is inside %d\n", i, j);
        }
    }    
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        poly.clear();
        dat.clear();
        memset(ans, 0, sizeof(ans));
        scanf("%d", &n);
        for(int i=0;i<n;i++)
        {
            scanf("%d", &m);
            sz[i]=m;
            poly.clear();
            for(int j=0;j<m;j++)
            {
                scanf("%d%d", &x, &y);
                poly.push_back(pii(x, y));
            }
            dat.push_back(poly);
        }
        /*for(int i=0;i<n;i++)
        {
            for(int j=0;j<sz[i];j++)
            {
                printf("%d %d ", dat[i][j].X, dat[i][j].Y);
            }
            printf("\n");
        }*/
        solve();
        for(int i=0;i<n;i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}
