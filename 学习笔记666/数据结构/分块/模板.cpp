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
const int N = 1e5 + 7;
ll n, m, len, s[N], a[N], b[N];
ll id[N], st[N], ed[N];
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
    run(i, 1, (n - 1) / len + 1)
    {
        st[i] = (i - 1) * len + 1;
        ed[i] = i * len;
    }
    ed[(n - 1) / len + 1] = n;
    run(i, 1, n)
    {
        id[i] = (i - 1) / len + 1;
        cin >> a[i];
        s[id[i]] += a[i];
    }
}

void add(ll l, ll r, ll x)
{
    int sid = id[l], eid = id[r];
    if(sid == eid)
    {
        run(i, l, r)
        {
            a[i] += x;
            s[sid] += x;
        }
        return;
    }
    run(i, l, ed[sid])
        a[i] += x, s[sid] += x;
    run(i, st[eid], r)
        a[i] += x, s[eid] += x;
    run(i, sid + 1, eid - 1)
        b[i] += x, s[i] += len * x;
}

ll query(ll l, ll r)
{
    int sid = id[l], eid = id[r];
    ll ans = 0;
    if(sid == eid)
    {
        run(i, l, r)
            ans += a[i];
        return ans;
    }
    run(i, l, ed[sid])
        ans += a[i] + b[sid];
    run(i, st[eid], r)
        ans += a[i] + b[eid];
    run(i, sid + 1, eid - 1)
        ans += s[i];
    return ans;
}

void solve()
{
    cin >> n >> m;
    init();
    while(m --)
    {
        int k;
        ll l, r;
        cin >> k;
        if(k == 1)
        {
            ll x;
            cin >> l >> r >> x;
            add(l, r, x);
        }
        else
        {
            cin >> l >> r;
            cout << query(l, r) << '\n';
        }
    }
}
int main() //https://www.luogu.com.cn/problem/P3372
{
    speed
//    t()
    solve();
    return 0;
}
