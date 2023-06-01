#include<bits/stdc++.h>
using namespace std;
int su[1000], shu[1000];
int m;
map<int, int>mp;
void work(int n)
{
    m = 0;
    for(int i = 2; i <= sqrt(n); i ++)
    {
        if(n % i == 0)
        {
            su[++ m] = i;
            shu[m] = 0;
            while(n % i == 0)
            {
                shu[m] ++;
                n /= i;
            }
        }
    }
    if(n > 1)
        su[++ m] = n, shu[m] = 1;
    int res = 1;
    for(int i = 1; i <= m; i ++)
    {
        if(shu[i] & 1)
            res *= su[i];
    }
    mp[res] ++;
}
int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        mp.clear();
        int n;
        cin >> n;
        for(int i = 1; i <= n; i ++)
        {
            int T;
            cin >> T;
            work(T);
        }
        long long ans = 0;
        for(auto it : mp)
        {
            ans += ((long long)it.second * (it.second - 1)) / 2;
        }
        printf("%lld\n",ans);
    }
}
