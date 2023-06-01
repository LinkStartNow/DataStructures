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

const ll N = 307;
int n, q;
int g[N], dp[N][N];
int siz[N];

struct egde
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
        siz[u] += siz[v] + 1;
        rep(j, min(q, siz[u]), 1)
        run(k, 0, min(j - 1, siz[v]))
        dp[u][j] = max(dp[u][j], dp[u][j - k - 1] + dp[v][k] + g[v]);
    }
}

void solve()
{
    cin >> n >> q;
    run(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        add(a, i), add(i, a);
        g[i] = b;
    }
    DP(0, 0);
    cout << dp[0][q];
}

int main() // https://www.luogu.com.cn/problem/P2014
{
    speed
//    t()
    solve();
    return 0;
}
