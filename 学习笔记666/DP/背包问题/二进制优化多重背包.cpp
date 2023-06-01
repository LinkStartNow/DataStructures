#include<bits/stdc++.h>

#define ll long long
#define lb long double
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);
//char buf[100000], *pa = buf, *pd = buf;
//#define gc pa == pd && (pd = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pd) ? EOF: *pa++

using namespace std;

const ll N = 1e6 + 7;
int n, v;
int a[N], b[N], tot;
ll dp[N];

ll spow(ll x, ll y)
{
    ll res = 1;
    while(y)
    {
        if(y & 1)
            res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

ll lowbit(ll x)
{
    return x & -x;
}

void DP()
{
    run(i, 1, tot)
        rep(j, v, a[i])
            dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
}

void solve()
{
    cin >> n >> v;
    run(i, 1, n)
    {
        int t, w, s;
        cin >> t >> w >> s;
        int k = 1;
        while(s >= k)
        {
            a[++ tot] = k * t;
            b[tot] = k * w;
            s -= k;
            k <<= 1;
        }
        if(s)
            a[++ tot] = s * t, b[tot] = s * w;
    }
    DP();
    cout << dp[v];
}

int main() // https://ac.nowcoder.com/acm/contest/38305/A
{
    speed
//    t()
    solve();
    return 0;
}
