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

int n, m;
int co[N];

struct zly
{
    int to, nx, v;
} e[N << 1];

int tot, head[N];

void add(int u, int v, int w)
{
    e[++ tot] = zly{v, head[u], w};
    head[u] = tot;
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

bool dfs(int x, int c, int k)
{
    co[x] = c;
    for(int i = head[x]; i; i = e[i].nx)
    {
        int to = e[i].to, w = e[i].v;
        if(w <= k)
            continue;
        if(!co[to])
        {
            if(!dfs(to, 3 - c, k))
                return 0;
        }
        else if(co[to] == c)
            return 0;
    }
    return 1;
}

bool okk(int x)
{
    ms(co);
    run(i, 1, n)
    if(!co[i])
        if(!dfs(i, 1, x))
            return 0;
    return 1;
}

void solve()
{
    cin >> n >> m;
    run(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }
    int l = 0, r = 1e9;
    while(l <= r)
    {
        int m(l, r);
        if(okk(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << l << '\n';
}
int main() //https://ac.nowcoder.com/acm/contest/1062/A
{
    speed
//    t()
    solve();
    return 0;
}
