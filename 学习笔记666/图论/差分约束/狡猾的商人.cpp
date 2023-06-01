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
const int N = 1e5 + 7;
ll n, m, dis[N], cnt[N];
bool vis[N];
struct yyds
{
    int to, nx;
    ll w;
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

void add(int x, int y, int z)
{
    e[++ tot] = yyds{y, head[x], z};
    head[x] = tot;
}

bool spfa()
{
    ms(cnt);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = head[u]; i; i = e[i].nx)
        {
            int to = e[i].to, w = e[i].w;
            if(dis[to] > dis[u] + w)
            {
                dis[to] = dis[u] + w;
                cnt[to] = cnt[u] + 1;
                if(cnt[to] > n)
                    return 0;
                if(!vis[to])
                {
                    vis[to] = 1;
                    q.push(to);
                }
            }
        }
    }
    return 1;
}

void solve()
{
    tot = 0;
    ms(head);
    while(!q.empty())
        q.pop();
    cin >> n >> m;
    run(i, 1, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a - 1, b, c), add(b, a - 1, -c);
    }
    run(i, 0, n)
    {
        dis[i] = 0;
        vis[i] = 1;
        q.push(i);
    }
    if(spfa())
        cout << "true" << '\n';
    else
        cout << "false" << '\n';
}
int main() // https://www.luogu.com.cn/problem/P2294
{
    speed
    t()
    solve();
    return 0;
}
