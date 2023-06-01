#include<bits/stdc++.h>

#define ll long long
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

using namespace std;

const ll N = 5e5 + 7;
ll c[N];
int n, q;

struct zly
{
    ll s, ml, mr, ans;
} e[N << 2];

void pd(int i)
{
    int x(i), y(i);
    e[i].s = e[x].s + e[y].s;
    e[i].ml = max(e[x].ml, e[x].s + e[y].ml);
    e[i].mr = max(e[y].mr, e[y].s + e[x].mr);
    e[i].ans = max({e[x].ans, e[y].ans, e[x].mr + e[y].ml});
}

void ch(int i, int l, int r, int p, int k)
{
    if(l == r)
    {
        e[i].ans = e[i].mr = e[i].ml = e[i].s = k;
        return;
    }
    int x(i), y(i), m(l, r);
    if(p <= m)
        ch(x, l, m, p, k);
    else
        ch(y, m + 1, r, p, k);
    pd(i);
}

zly ask(int i, int l, int r, int ln, int rn)
{
    zly ssr;
    ssr.s = 0;
    ssr.ml = ssr.mr = ssr.ans = -1e9;
    if(l > rn || r < ln)
        return ssr;
    if(ln <= l && rn >= r)
        return e[i];
    int x(i), y(i), m(l, r);
    zly a = ask(x, l, m, ln, rn), b = ask(y, m + 1, r, ln, rn);
    ssr.s = a.s + b.s;
    ssr.ml = max(a.ml, a.s + b.ml);
    ssr.mr = max(b.mr, b.s + a.mr);
    ssr.ans = max({a.ans, b.ans, a.mr + b.ml});
    return ssr;
}

void build(int i, int l, int r)
{
    if(l == r)
    {
        e[i].ans = e[i].mr = e[i].ml = e[i].s = c[l];
        return;
    }
    int x(i), y(i), m(l, r);
    build(x, l, m), build(y, m + 1, r);
    pd(i);
}

void solve()
{
    cin >> n >> q;
    run(i, 1, n)
        cin >> c[i];
    build(1, 1, n);
    run(i, 1, q)
    {
        int k, a, b;
        cin >> k >> a >> b;
        if(k == 1)
        {
            if(a > b)
                swap(a, b);
            cout << ask(1, 1, n, a, b).ans << '\n';
        }
        else
            ch(1, 1, n, a, b);
    }
}

int main() // https://www.luogu.com.cn/problem/P4513
{
    speed
//    t()
    solve();
    return 0;
}
