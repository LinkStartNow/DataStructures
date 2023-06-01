#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(ll i = a; i <= b; i ++)
#define rep(i, a, b) for(ll i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);

using namespace std;
const int N = 5e5 + 7;
int n, m;
ll b[N];
int r[N];

struct yyds
{
    int id, v;
    bool operator<(const yyds &b) const
    {
        if(v == b.v)
            return id < b.id;
        return v < b.v;
    }
} a[N];

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

void add(ll i)
{
    while(i <= n)
    {
        b[i] ++;
        i += lowbit(i);
    }
}

ll query(ll x)
{
    ll res = 0;
    while(x)
    {
        res += b[x];
        x -= lowbit(x);
    }
    return res;
}

void solve()
{
    cin >> n;
    run(i, 1, n)
        cin >> a[i].v, a[i].id = i;
    sort(a + 1, a + 1 + n);
    run(i, 1, n)
        r[a[i].id] = i;
    ll ans = 0;
    run(i, 1, n)
    {
        int p = r[i];
        ans += query(n) - query(p);
        add(p);
    }
    cout << ans << '\n';
}
int main() //https://www.luogu.com.cn/problem/P1908
{
    speed
//    t()
    solve();
    return 0;
}
