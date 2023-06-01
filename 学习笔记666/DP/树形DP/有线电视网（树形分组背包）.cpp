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

const ll N = 3007;
int n, m;
int siz[N], dp[N][N], val[N];
int head[N], tot;

struct edge
{
    ll to, nx, w;
} e[N];

void add(int u, int v, int w)
{
    e[++ tot] = {v, head[u], w};
    head[u] = tot;
}

void dfs(int u)
{
    if(u > n - m)
    {
        siz[u] = 1;
        dp[u][1] = val[u];
        return;
    }
    for(int i = head[u]; i; i = e[i].nx)
    {
        int v = e[i].to, w = e[i].w;
        dfs(v);
        siz[u] += siz[v];
        rep(j, siz[u], 1)
        run(k, 1, siz[v])
            if(j >= k)
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k] - w);
    }
}

void solve()
{
    cin >> n >> m;
    run(i, 1, n - m)
    {
        int a, b, c;
        cin >> a;
        run(j, 1, a)
            cin >> b >> c, add(i, b, c);
    }
    run(i, n - m + 1, n)
        cin >> val[i];
    memset(dp, -0x7f, sizeof dp);
    run(i, 1, n)
        dp[i][0] = 0;
    dfs(1);
    rep(i, siz[1], 0)
        if(dp[1][i] >= 0)
        {
            cout << i;
            return;
        }
}

int main() // https://www.luogu.com.cn/problem/P1273
{
    speed
//    t()
    solve();
    return 0;
}
