#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, p = 255, mod = 1e9 + 9;
long long hush[N], pr[N], husht[N];
char s[N], st[N];
int l, lt;
void HUSH()
{
    l = strlen(s + 1);
    lt = strlen(st + 1);
    for(int i = 1; i <= l; i ++)
    {
        hush[i] = (hush[i - 1] * p + s[i]) % mod;
    }
    for(int i = 1; i <= lt; i ++)
    {
        husht[i] = (husht[i - 1] * p + st[i]) % mod;
    }
}
void pre()
{
    pr[0] = 1;
    for(int i = 1; i <= N; i ++)
        pr[i] = pr[i - 1] * p % mod;
}
long long substring(int l, int r,long long *hush)
{
    return (hush[r] - hush[l - 1] * pr[r - l + 1] % mod + mod) % mod;
}
bool check(int l, int m, int sta)
{
    int le = m - l + 1;
    if(substring(l, m, hush) == substring(sta, sta + le - 1, husht))
        return true;
    return false;
}
int main()
{
    int t;
    scanf("%d", &t);
    pre();
    while(t --)
    {
        int ans = 0;
        scanf("%s%s", s + 1, st + 1);
        HUSH();
        for(int i = 1; i <= l - lt + 1; i ++)
        {
            bool flag = false;
            if(substring(i, i + lt - 1, hush) == husht[lt])
                ans ++;
            else
            {
                int ll = i, rr;
                for(int j = 1; j <= 4; j ++)
                {
                    rr = i + lt;
                    while(ll < rr)
                    {
                        int mid = (ll + rr) >> 1;
                        if(check(ll, mid, ll - i + 1))
                            ll = mid + 1;
                        else
                            rr = mid;
                    }
                    if(ll == i + lt)
                    {
                        flag = true;
                        break;
                    }
                    ll ++;
                }
                if(flag)
                    ans ++;
            }
        }
        printf("%d\n", ans);
    }
}
