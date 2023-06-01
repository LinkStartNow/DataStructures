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

const int N = 1e6 + 7;
ll key;
ll n, q;
ll a[N];

struct tree
{
    int l, r;
    bool zero, one;
    ll siz, cnt;
} t[N << 2];

struct query
{
    bool k;
    int l, r;
} ask[N];

void build(int i, int l, int r, int f)
{
    t[i].l = l, t[i].r = r;
    t[i].cnt = t[i].zero = t[i].one = 0;
    t[i].siz = r - l + 1;
    if(l == r)
    {
        t[i].cnt = a[l] >= f;
        return;
    }
    int x(i), y(i), m(l, r);
    build(x, l, m, f), build(y, m + 1, r, f);
    t[i].cnt = t[x].cnt + t[y].cnt;
}

void pd(int i)
{
    int x(i), y(i);
    if(t[i].zero)
    {
        t[x].one = t[y].one = 0;
        t[x].zero = t[y].zero = 1;
        t[x].cnt = t[y].cnt = 0;
        t[i].zero = 0;
    }
    if(t[i].one)
    {
        t[x].one = t[y].one = 1;
        t[x].zero = t[y].zero = 0;
        t[x].cnt = t[x].siz, t[y].cnt = t[y].siz;
        t[i].one = 0;
    }
}

int qcnt(int i, int l, int r, int ln, int rn)
{
    if(l > rn || r < ln)
        return 0;
    if(l >= ln && r <= rn)
        return t[i].cnt;
    pd(i);
    int x(i), y(i), m(l, r);
    return qcnt(x, l, m, ln, rn) + qcnt(y, m + 1, r, ln, rn);
}

void update(int i, int l, int r, int ln, int rn, bool f)
{
    if(l > rn || r < ln)
        return;
    if(l >= ln && r <= rn)
    {
        if(f)
        {
            t[i].cnt = t[i].siz;
            t[i].zero = 0, t[i].one = 1;
        }
        else
        {
            t[i].cnt = 0;
            t[i].zero = 1, t[i].one = 0;
        }
        return;
    }
    pd(i);
    int x(i), y(i), m(l, r);
    update(x, l, m, ln, rn, f), update(y, m + 1, r, ln, rn, f);
    t[i].cnt = t[x].cnt + t[y].cnt;
}

bool qq(int i, int l, int r, int f)
{
    if(l == r)
        return t[i].cnt;
    int x(i), y(i), m(l, r);
    pd(i);
    if(f <= m)
        return qq(x, l, m, f);
    return qq(y, m + 1, r, f);
}

bool yyds(ll x)
{
    build(1, 1, n, x);
    run(i, 1, q)
    {
        int l = ask[i].l, r = ask[i].r, k = ask[i].k;
        int cnt = qcnt(1, 1, n, l, r);
        if(!k)
        {
            int fff = r - cnt + 1;
            update(1, 1, n, l, fff - 1, 0), update(1, 1, n, fff, r, 1);
        }
        else
        {
            int fff = l + cnt - 1;
            update(1, 1, n, l, fff, 1), update(1, 1, n, fff + 1, r, 0);
        }
    }
    return qq(1, 1, n, key);
}

void solve()
{
    ll l = 1e10, r = -1e10;
    cin >> n >> q;
    run(i, 1, n)
        cin >> a[i], r = max(r, a[i]), l = min(l, a[i]);
    run(i, 1, q)
    {
        ll k, l, r;
        cin >> k >> l >> r;
        if(l > r)
            swap(l, r);
        ask[i].k = k, ask[i].l = l, ask[i].r = r;
    }
    cin >> key;
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        if(yyds(m))
            l = m + 1;
        else
            r = m - 1;
    }
    cout << r << '\n';
}

int main() // https://www.luogu.com.cn/problem/P2824
{
    speed
//    t()
    solve();
    return 0;
}
