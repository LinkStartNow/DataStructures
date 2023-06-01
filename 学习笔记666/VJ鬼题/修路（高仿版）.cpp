#include<bits/stdc++.h>
using namespace std;
int road[350];
int n,m;
bool check(int length)
{
    int work,p,worker;
    work = worker = 0;
    p = 1;
    while(p <= m)
    {
        if(work + road[p] <= length)
        {
            work += road[p ++];
        }
        else
        {
            if(worker >= n)
                return false;
            worker ++;
            work = 0;
        }
    }
    if(work)
        worker ++;
    return worker <= n;
}
int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        memset(road,0,sizeof(road));
        cin >> m >> n;
        for(int i = 1;i <= m;i ++)
            cin >> road[i];
        int max_road = -666;
        for(int i = 1;i <= m;i ++)
            max_road = max(max_road,road[i]);
        int l = max_road,r = max_road*(m - n + 1);
        while(r > l)
        {
            int mid = (l + r) >> 1;
            if(check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        printf("%d\n",r);
    }
}
