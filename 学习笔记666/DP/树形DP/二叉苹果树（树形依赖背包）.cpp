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
int n, q, siz[N], snk[N][N];

struct egde
{
    int to, nx, val;
} e[N << 1];

int head[N], tot;

void add(int u, int v, int val)
{
    e[++ tot] = {v, head[u], val};
    head[u] = tot;
}

void build(int u, int fa)
{
    for(int i = head[u]; i; i = e[i].nx)
    {
        int v = e[i].to;
        if(v == fa)
            continue;
        build(v, u);
        siz[u] += siz[v] + 1;
        rep(j, min(q, siz[u]), 1)
        rep(k, min(j - 1, siz[v]), 0)
        snk[u][j] = max(snk[u][j], snk[u][j - k - 1] + snk[v][k] + e[i].val);
    }
}

void solve()
{
    cin >> n >> q;
    run(i, 1, n - 1)
    {
        int u, v, x;
        cin >> u >> v >> x;
        add(u, v, x), add(v, u, x);
    }
    build(1, 1);
    cout << snk[1][q];
}

int main() // https://www.luogu.com.cn/problem/P2015
{
    speed
//    t()
    solve();
    return 0;
}
