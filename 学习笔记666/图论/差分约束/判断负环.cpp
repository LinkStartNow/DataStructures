#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) mid = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);

using namespace std;
const int N = 3e3 + 7;
int n, m, dis[N];
bool vis[N];
struct yyds
{
    int to, nx;
    ll w;
} e[N << 1];
int tot, head[N], cnt[N];

ll spow(ll x, ll y)
{
    ll res = 1;
    while(y)
    {
        if(y & 1)
            res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

ll lowbit(ll x)
{
    return x & -x;
}

void add(int u, int v, ll w)
{
    e[++ tot] = yyds{v, head[u], w};
    head[u] = tot;
}

bool spfa(int x)
{
    queue<int> q;
    fill(dis, dis + n + 1, 1e9);
    ms(cnt);
    ms(vis);
    dis[x] = 0;
    vis[x] = 1;
    q.push(x);
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        vis[p] = 0;
        for(int i = head[p]; i; i = e[i].nx)
        {
            int to = e[i].to;
            if(dis[to] > dis[p] + e[i].w)
            {
                dis[to] = dis[p] + e[i].w;
                cnt[to] = cnt[p] + 1;
                if(cnt[to] > n)
                    return 1;
                if(!vis[to])
                {
                    q.push(to);
                    vis[to] = 1;
                }
            }
        }
    }
    return 0;
}

void solve()
{
    tot = 0;
    ms(head);
    cin >> n >> m;
    run(i, 1, m)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        add(u, v, w);
        if(w >= 0)
            add(v, u, w);
    }
    if(spfa(1))
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}
int main() // https://www.luogu.com.cn/problem/P3385
{
    speed
    t()
    solve();
    return 0;
}