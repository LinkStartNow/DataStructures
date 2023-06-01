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

const ll N = 3e5 + 7;

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

void dfs2(int u, int f)
{
    for(auto v : e[u])
    {
        if(v == f)
            continue;
        dfs2(v, u);
        s[u] += s[v];
    }
}

void solve()
{
    int n;
    cin >> n;
    run(i, 1, n) cin >> a[i];
    run(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v), e[v].push_back(u);
    }
    dep[1] = 1;
    dfs(1, 1);
    int t = a[1];
    run(i, 2, n)
    {
        int ssr = a[i];
        int p = lca(t, ssr);
        if(t != p)
            s[fa[t][0]] ++;
        s[ssr] ++;
        s[p] --;
        if(p != 1 && t != p)
            s[fa[p][0]] --;
        t = ssr;
    }
    dfs2(1, 1); // 用dfs更新差分数组
    run(i, 1, n)
    {
        if(i == a[1])
            cout << s[i] + 1 << '\n';
        else if(i == a[n])
            cout << s[i] - 1 << '\n';
        else
            cout << s[i] << '\n';
    }
}

int main() // https://www.luogu.com.cn/problem/P3258
{
    speed
//    t()
    solve();
    return 0;
}