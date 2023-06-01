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
const int N = 1e4 + 7;
int n, s, t;
double dis[N], ssr = 1e-6, ex[N];
int cnt[N];
bool vis[N];
struct zly
{
    int o, u, v, k;
}   a[N];
struct yyy
{
    int c, x;
}   c[N];
struct yyds
{
    int to, nx;
    double w;
}   e[N << 1];
int tot, head[N];
queue<int> q;
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

void add(int x, int y, double z)
{
    e[++ tot] = yyds{y, head[x], z};
    head[x] = tot;
}

bool spfa(double x)
{
    while(!q.empty())
        q.pop();
    ms(head);
    tot = 0;
    run(i, 1, s)
    {
        if(a[i].o == 1)
            add(a[i].u, a[i].v, -log(a[i].k - x));
        else
            add(a[i].u, a[i].v, log(a[i].k + x));
    }
    run(i, 1, t)
    add(0, c[i].c, log(c[i].x)), add(c[i].c, 0, -log(c[i].x));
    run(i, 0, n)
    {
        vis[i] = 1;
        cnt[i] = 0;
        dis[i] = 1e9;
        q.push(i);
    }
    dis[0] = 0;
    while(!q.empty())
    {
        int u = q.front();
        vis[u] = 0;
        q.pop();
        for(int i = head[u]; i; i = e[i].nx)
        {
            int to = e[i].to;
            double w = e[i].w;
            if(dis[to] > dis[u] + w)
            {
                dis[to] = dis[u] + w;
                cnt[to] = cnt[u] + 1;
                if(cnt[to] > n)
                    return 1;
                if(!vis[to])
                {
                    vis[to] = 1;
                    q.push(to);
                }
            }
        }
    }
    return 0;
}

void solve()
{
    double l = 0, r = 1e9;
    cin >> n >> s >> t;
    run(i, 1, s)
    {
        cin >> a[i].o >> a[i].u >> a[i].v >> a[i].k;
        if(a[i].o == 1)
            r = min(r, a[i].k - ssr);
    }

    run(i, 1, t)
    cin >> c[i].c >> c[i].x;
    bool f = 0;
    while(r - l >= ssr)
    {
        double m = (l + r) / 2.0;
        if(spfa(m))
            l = m, f = 1;
        else
            r = m;
    }
    if(!f)
        puts("-1");
    else
        printf("%.5f\n", l);
}
int main() // https://www.luogu.com.cn/problem/P4926
{
    speed
//    t()
    solve();
    return 0;
}
