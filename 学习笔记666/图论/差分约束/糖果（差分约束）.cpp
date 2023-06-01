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
    int to, nx, w;
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
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = head[u]; i; i = e[i].nx)
        {
            int to = e[i].to, w = e[i].w;
            if(dis[to] < dis[u] + w)
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
    cin >> n >> m;
    bool f = 1;
    run(i, 1, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1)
            add(b, c, 0), add(c, b, 0);
        else if(a == 2)
        {
            if(b == c)
            {
                puts("-1");
                f = 0;
            }
            add(b, c, 1);
        }
        else if(a == 3)
            add(c, b, 0);
        else if(a == 4)
        {
            if(b == c)
            {
                puts("-1");
                f = 0;
            }
            add(c, b, 1);
        }
        else
            add(b, c, 0);
    }
    if(!f)
        return;
    run(i, 1, n)
    {
        dis[i] = 1;
        vis[i] = 1;
        q.push(i);
    }
    if(spfa())
    {
        ll ans = 0;
        run(i, 1, n)
            ans += dis[i];
        printf("%lld\n", ans);
    }
    else
        puts("-1");
}
int main() // https://www.luogu.com.cn/problem/P3275
{
    speed
//    t()
    solve();
    return 0;
}
