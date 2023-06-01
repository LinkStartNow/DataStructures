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

const ll N = 1e5 + 7;

int f[N], pos = 1, g[N];
int ans[N];

int fa(int x)
{
    return x == f[x] ? x : f[x] = fa(f[x]);
}

struct zly
{
    int a, b, w;
    bool operator<(const zly &b) const
    {
        return w > b.w;
    }
} e[N];

struct query
{
    int k, v, id;
    bool operator<(const query &b) const
    {
        return k > b.k;
    }
} ask[N];

void solve()
{
    int n, q;
    cin >> n >> q;
    run(i, 1, n)
        g[i] = 1, f[i] = i;
    run(i, 1, n - 1)
    cin >> e[i].a >> e[i].b >> e[i].w;
    sort(e + 1, e + n);
    run(i, 1, q)
    cin >> ask[i].k >> ask[i].v, ask[i].id = i;
    sort(ask + 1, ask + 1 + q);
    run(i, 1, q)
    {
        int k = ask[i].k, v = ask[i].v;
        run(j, pos, n - 1)
        {
            if(e[j].w < k)
                break;
            pos = j + 1;
            int x = fa(e[j].a), y = fa(e[j].b);
            if(x != y)
            {
                f[x] = y;
                g[y] += g[x];
                g[x] = 0;
            }
        }
        int x = fa(v);
        ans[ask[i].id] = g[x] - 1;
    }
    run(i, 1, q)
        cout << ans[i] << '\n';
}

int main() // https://www.luogu.com.cn/problem/P4185
{
    speed
//    t()
    solve();
    return 0;
}
