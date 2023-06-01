#include<bits/stdc++.h>
#define run(i, a, b) for(long long i = a; i <= b; i ++)
#define ll long long
using namespace std;
const int N = 1e5 + 5;
ll n, m, u, v, w;
ll f[N], d[N], p[N][2];
ll fa(ll x)
{
    if(x == f[x])
        return x;
    ll ff = fa(f[x]);
    f[x] = ff;
    d[x] ^= d[f[x]];
    return f[x];
}
int main()
{
    cin >> n >> m;
    run(i, 1, n)
    f[i] = i;
    bool flag = 1;
    while(m --)
    {
        cin >> u >> v >> w;
        ll x = fa(u), y = fa(v);
        if(x == y && d[u] ^ d[v] != w)
        {
            flag = 0;
            continue;
        }
        f[x] = y;
        d[x] = d[u] ^ d[v] ^ w;
    }
    if(!flag)
        printf("-1\n");
    else
    {
        ll ans = 0;
        run(i, 0, 30)
        {
            run(j, 1, n)
            p[j][0] = p[j][1] = 0;
            run(j, 1, n)
            {
                ll x = fa(j);
                p[x][d[j] >> i & 1] ++;
            }
            run(j, 1, n)
            {
                ans += min(p[j][0], p[j][1]) << i;
            }
        }
        printf("%lld\n", ans);
    }
}
