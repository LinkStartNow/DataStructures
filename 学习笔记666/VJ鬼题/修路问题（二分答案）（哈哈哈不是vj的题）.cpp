#include<bits/stdc++.h>

using namespace std;

int roads[300];

int m, n;

bool is_valid(int length);

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &m, &n);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &roads[j]);
        }
        int max_road = -1;
        for (int j = 0; j < m; j++)
        {
            max_road = max(max_road, roads[j]);
        }
        int l = max_road - 1, r = max_road * (m - n + 1);
        while (r - l > 1)
        {
            int mid = (l + r) / 2;
            if (is_valid(mid))
                r = mid;
            else
                l = mid;
        }
        printf("%d\n", r);
    }
}

bool is_valid(int length)
{
    int count = 0;
    int work = 0;
    int curr = 0;
    while (curr < m)
    {
        if (work + roads[curr] <= length)
        {
            work += roads[curr++];
        }
        else
        {
            if (++count > n)
                return false;
            work = 0;
        }
    }
    if (work > 0)
        ++count;
    return count <= n;
}
