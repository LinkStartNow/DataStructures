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
const int N = 1e5 + 7;
ll n, p;
ll tot;
ll t[N << 2];

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

void build(int l, int r, int i)
{
    t[i] = 1;
    if(l == r)
        return;
    int m(l, r), x(i), y(i);
    build(l, m, x), build(m + 1, r, y);
}


void ch(int l, int r, int i, int zly, int v)
{
    if(l == r)
    {
        t[i] = v;
        return;
    }
    int m(l, r), x(i), y(i);
    if(zly <= m)
        ch(l, m, x, zly, v);
    else
        ch(m + 1, r, y, zly, v);
    t[i] = t[x] * t[y] % p;
}


void solve()
{
    tot = 0;
    cin >> n >> p;
    build(1, n, 1);
    int s = n;
    while(s --)
    {
        ll k, x;
        cin >> k >> x;
        tot ++;
        if(k == 1)
            ch(1, n, 1, tot, x), cout << t[1] << '\n';
        else
            ch(1, n, 1, x, 1), cout << t[1] << '\n';
    }
}
int main() //https://www.luogu.com.cn/problem/P4588
{
    speed
    t()
    solve();
    return 0;
}
