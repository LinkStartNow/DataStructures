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

const ll N = 4e6 + 7;
int dis[N], ans[N];
int stk[N], p;

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

void dfs(int s, int f)
{
    stk[++ p] = s; // 手动模拟栈，方便修改栈中的值
    ans[s] ++; // 储存书上差分即答案
    ll fa = max(0, stk[p - dis[s] - 1]); // 由于是顺着遍历下来故在栈中的节点都是当前节点的父亲
    ans[fa] --; // 差分常规操作，尾部-1
    for(int i = head[s]; i; i = e[i].nx)
    {
        int to = e[i].to;
        if(to == f)
            continue;
        dfs(to, s);
        ans[s] += ans[to]; // 访问回来时顺便把差分的值处理了
    }
    p --; // 弹出处理完的数据，这课子树完结了
}

void solve()
{
    int n;
    cin >> n;
    run(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    run(i, 1, n) cin >> dis[i];
    dfs(1, 1);
    run(i, 1, n) cout << ans[i] << " \n"[i == n];
}

int main() // https://ac.nowcoder.com/acm/contest/33191/B
{
    speed
//    t()
    solve();
    return 0;
}
