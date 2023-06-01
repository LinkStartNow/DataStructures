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

const int N = 2e5 + 7;

int f[N], n, m;
ll ans;
bool flag;

struct zly
{
    int u, v;
    ll w;
    bool operator<(const zly &b) const
    {
        return w < b.w;
    }
} yi[N];

int fa(int x)
{
    return f[x] == x ? x : f[x] = fa(f[x]);
}

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

void solve()
{
    cin >> n >> m;
    run(i, 1, m)
        cin >> yi[i].u >> yi[i].v >> yi[i].w;
    sort(yi + 1, yi + 1 + m);
    run(i, 1, n)
        f[i] = i;
    run(i, 1, m)
    {
        int x = fa(yi[i].u), y = fa(yi[i].v);
        if(x == y) // 同一个祖先说明已经联通了，若再加边会形成环
            continue;
        f[x] = y;
        ans += yi[i].w;
    }
    run(i, 2, n) // 判断是否联通
        if(fa(i) != fa(1))
            flag = 1;
    if(!flag)
        cout << ans << '\n';
    else
        cout << "orz" << '\n';
}
int main() //https://www.luogu.com.cn/problem/P3366
{
    speed
//    t()
    solve();
    return 0;
}
