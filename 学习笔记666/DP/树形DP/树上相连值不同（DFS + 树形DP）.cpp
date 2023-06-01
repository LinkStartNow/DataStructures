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

const ll N = 1e4 + 7;
ll dp[N][50];
bool vis[N];
int mm = 20;

struct zly
{
    int to, nx;
} e[N << 1];

int head[N], tot;

void add(int x, int y)
{
    e[++ tot] = {y, head[x]};
    head[x] = tot;
}

void dfs(int u)
{
    run(i, 1, 20)
        dp[u][i] = i;
    vis[u] = 1;
    for(int i = head[u]; i; i = e[i].nx)
    {
        int v = e[i].to;
        if(vis[v])
            continue;
        dfs(v);
        run(j, 1, mm)
        {
            ll ssr = 1e9;
            run(k, 1, mm)
                if(k != j)
                    ssr = min(ssr, dp[v][k]);
            dp[u][j] += ssr;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    run(i, 1, n - 1)
    {
        int u, v;
        cin >> v >> u;
        add(u, v), add(v, u);
    }
    dfs(1);
    ll ans = 1e9;
    run(i, 1, mm)
        ans = min(ans, dp[1][i]);
    cout << ans;
}

int main() // https://www.luogu.com.cn/problem/P4395
{
    speed
//    t()
    solve();
    return 0;
}
