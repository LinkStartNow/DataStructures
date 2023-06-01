#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) mid = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int N = 5e4 + 7;
ll n, m;
ll a[N], cnt[N], li[N], ri[N];
ll len, id[N];
ll ans[N];
struct zly
{
    int l, r, i;
    bool operator<(const zly &b)const
    {
        if(id[l] == id[b.l])
            return id[r] < id[b.r];
        return id[l] < id[b.l];
    }
} q[N];

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

void init()
{
    len = sqrt(n);
    run(i, 1, n)
    {
        cin >> a[i];
        id[i] = (i - 1) / len + 1;
    }
    run(i, 1, m)
    cin >> q[i].l >> q[i].r, q[i].i = i, li[i] = q[i].l, ri[i] = q[i].r;
    sort(q + 1, q + 1 + m);
}

void mo()
{
    ll l = 0, r = 0, s = 0;
    run(i, 1, m)
    {
        ll lll = q[i].l, rrr = q[i].r;
        while(l < lll)
        {
            int co = a[l];
            if(cnt[co] >= 2)
                s -= cnt[co] * (cnt[co] - 1) >> 1;
            cnt[co] --;
            if(cnt[co] >= 2)
                s += cnt[co] * (cnt[co] - 1) >> 1;
            l ++;
        }
        while(l > lll)
        {
            l --;
            int co = a[l];
            if(cnt[co] >= 2)
                s -= cnt[co] * (cnt[co] - 1) >> 1;
            cnt[co] ++;
            if(cnt[co] >= 2)
                s += cnt[co] * (cnt[co] - 1) >> 1;
        }
        while(r > rrr)
        {
            int co = a[r];
            if(cnt[co] >= 2)
                s -= cnt[co] * (cnt[co] - 1) >> 1;
            cnt[co] --;
            if(cnt[co] >= 2)
                s += cnt[co] * (cnt[co] - 1) >> 1;
            r --;
        }
        while(r < rrr)
        {
            r ++;
            int co = a[r];
            if(cnt[co] >= 2)
                s -= cnt[co] * (cnt[co] - 1) >> 1;
            cnt[co] ++;
            if(cnt[co] >= 2)
                s += cnt[co] * (cnt[co] - 1) >> 1;
        }
        ans[q[i].i] = s;
    }
}

void solve()
{
    cin >> n >> m;
    init();
    mo();
    run(i, 1, m)
    {
        if(li[i] == ri[i] || !ans[i])
        {
            puts("0/1");
            continue;
        }
        ll l = (ri[i] - li[i] + 1);
        ll s = (l - 1) * l >> 1;
        ll x = __gcd(ans[i], s);
        printf("%lld/%lld\n", ans[i] / x, s / x);
    }
}
int main() //https://www.luogu.com.cn/problem/P1494
{
    speed
//    t()
    solve();
    return 0;
}
