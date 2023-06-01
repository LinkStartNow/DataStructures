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

const ll N = 107;
int dp[N][N][2];
int n, q, ans;

struct edge
{
    int to, nx;
} e[N << 1];

int head[N], tot;

void add(int u, int v)
{
    e[++ tot] = {v, head[u]};
    head[u] = tot;
}

void DP(int u, int fa)
{
    for(int i = head[u]; i; i = e[i].nx)
    {
        int v = e[i].to;
        if(v == fa)
            continue;
        DP(v, u);
        rep(j, n, 1)
        run(k, 0, j - 1)
        {
            if(k <= j - 2)
            {
                dp[u][j][1] = max(dp[u][j][1], dp[u][j - k - 2][1] + dp[v][k][1] + 1);
                dp[u][j][0] = max(dp[u][j][0], dp[u][j - k - 2][0] + dp[v][k][1] + 1);
            }
            dp[u][j][0] = max(dp[u][j][0], dp[u][j - k - 1][1] + dp[v][k][0] + 1);
        }
    }
}

void solve()
{
    cin >> q >> n;
    run(i, 1, q - 1)
    {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    DP(0, 0);
    run(i, 0, n)
        ans = max({ans, dp[0][i][0], dp[0][i][1]});
    cout << ans + 1;
}

int main() // https://www.luogu.com.cn/problem/P3698
{
    speed
//    t()
    solve();
    return 0;
}
