#include<bits/stdc++.h>

#define ll long long
#define lb long double
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
//char buf[100000], *pa = buf, *pd = buf;
//#define gc pa == pd && (pd = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pd) ? EOF: *pa++

using namespace std;

const ll N = 5e5 + 7;

int a[N], s[N];
vector<int> e[N];
int fa[N][30], dep[N];

void dfs(int s, int f)
{
    for(auto v : e[s])
    {
        if(v == f)
            continue;
        dep[v] = dep[s] + 1; // v的深度要在循环处理v的各种祖先之前处理出来
        fa[v][0] = s; // 同上
        run(i, 1, 29)
            fa[v][i] = fa[fa[v][i - 1]][i - 1];
        dfs(v, s);
    }
}

int lca(int a, int b)
{
    if(dep[a] > dep[b])
        swap(a, b);
    rep(i, 29, 0)
        if(dep[fa[b][i]] >= dep[a])
            b = fa[b][i];
    if(a == b)
        return a;
    rep(i, 29, 0)
        if(fa[a][i] != fa[b][i])
            a = fa[a][i], b = fa[b][i];
    return fa[a][0];
}

void solve()
{
    int n, m, s;
    cin >> n >> m >> s;
    run(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v), e[v].push_back(u);
    }
    dep[s] = 1; // 初始化根节点的深度为1
    dfs(s, s);
    while(m --)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}

int main() // https://www.luogu.com.cn/problem/P3379
{
    speed
//    t()
    solve();
    return 0;
}
