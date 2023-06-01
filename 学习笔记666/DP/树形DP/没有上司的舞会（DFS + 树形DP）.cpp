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

const ll N = 1e6 + 7;
ll a[N], f[N], dp[N][2];

struct zly
{
    int to, nx;
} e[N];

int head[N], tot;

void add(int x, int y)
{
    e[++ tot] = {y, head[x]};
    head[x] = tot;
}

void dfs(int u)
{
    if(!head[u])
    {
        dp[u][1] = a[u];
        dp[u][0] = 0;
        return;
    }
    ll s = 0, ssr = 0;
    for(int i = head[u]; i; i = e[i].nx)
    {
        int v = e[i].to;
        dfs(v);
        s += max(dp[v][0], dp[v][1]);
        ssr += dp[v][0];
    }
    dp[u][1] = ssr + a[u], dp[u][0] = s;
}

void solve()
{
    int n;
    cin >> n;
    run(i, 1, n)
    cin >> a[i];
    run(i, 1, n - 1)
    {
        int u, v;
        cin >> v >> u;
        f[v] = u;
        add(u, v);
    }
    int fa;
    run(i, 1, n)
    if(!f[i])
    {
        fa = i;
        break;
    }
    dfs(fa);
    cout << max(dp[fa][0], dp[fa][1]);
}

int main() // https://www.luogu.com.cn/problem/P1352
{
    speed
//    t()
    solve();
    return 0;
}
