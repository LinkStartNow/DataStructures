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

bool br[N];
int f[N];
stack<int> b, ans;

int fa(int x)
{
    return x == f[x] ? x : f[x] = fa(f[x]);
}

struct edge
{
    int from, to, nx;
} e[N];
int head[N], tot;

void add(int x, int y)
{
    e[++ tot] = edge{x, y, head[x]};
    head[x] = tot;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    run(i, 0, n - 1)
        f[i] = i, head[i] = -1;
    run(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    int k;
    cin >> k;
    run(i, 1, k)
    {
        int p;
        cin >> p;
        br[p] = 1;
        b.push(p);
    }
    int ssr = n - k;
    run(i, 1, m << 1)
    {
        int u = e[i].from, v = e[i].to;
        if(br[u] || br[v])
            continue;
        int x = fa(u), y = fa(v);
        if(x != y)
            ssr --;
        f[x] = y;
    }
    ans.push(ssr);
    while(!b.empty())
    {
        ssr ++;
        int u = b.top();
        b.pop();
        br[u] = 0;
        int x, y;
        for(int i = head[u]; i != -1; i = e[i].nx)
        {
            int v = e[i].to;
            if(br[v])
                continue;
            y = fa(v);
            x = fa(u);
            if(x != y)
                ssr --;
            f[y] = x;
        }
        ans.push(ssr);
    }
    while(!ans.empty())
    {
        cout << ans.top() << '\n';
        ans.pop();
    }
}

int main() // https://www.luogu.com.cn/problem/P1197
{
    speed
//    t()
    solve();
    return 0;
}
