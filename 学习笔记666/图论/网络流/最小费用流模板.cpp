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

const int N = 2e5 + 7;
int n, m, s, t;
ll ansa, ansb;
int dis[N], pre[N], flow[N];
bool vis[N];

struct zly
{
    int to, nx, flow, w;
} e[N];

int head[N], tot = 1;

void add(int x, int y, int w, int v)
{
    e[++ tot] = zly{y, head[x], w, v};
    head[x] = tot;
}

bool spfa()
{
    ms(vis);
    fill(dis + 1, dis + 1 + n, 1e9);
    dis[s] = 0;
    vis[s] = 1;
    flow[s] = 1e9;
    queue<int> q;
    q.push(s);
    int u, v;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = head[u]; i; i = e[i].nx)
        {
            v = e[i].to;
            if(dis[v] > dis[u] + e[i].w && e[i].flow)
            {
                pre[v] = i;
                dis[v] = dis[u] + e[i].w;
                flow[v] = min(flow[u], e[i].flow);
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return dis[t] != 1e9;
}

void yyds()
{
    int id = t, i = pre[id];
    while(id != s)
    {
        e[i].flow -= flow[t];
        e[i ^ 1].flow += flow[t];
        id = e[i ^ 1].to;
        i = pre[id];
    }
    ansa += flow[t];
    ansb += flow[t] * dis[t];
}

void Ek()
{
    while(spfa())
        yyds();
}

void solve()
{
    cin >> n >> m >> s >> t;
    run(i, 1, m)
    {
        int u, v, f, w;
        cin >> u >> v >> f >> w;
        add(u, v, f, w);
        add(v, u, 0, -w);
    }
    Ek();
    cout << ansa << ' ' << ansb << '\n';
}

int main() // https://www.luogu.com.cn/problem/P3381
{
    speed
//    t()
    solve();
    return 0;
}
