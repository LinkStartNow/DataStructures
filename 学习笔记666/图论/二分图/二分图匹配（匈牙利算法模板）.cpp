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
const int N = 507, E = 5e4 + 7;

bool vis[N];
int n1, n2, m, mat[N];

struct zly
{
    int to, nx;
} e[E];

int tot, head[N];

void add(int u, int v)
{
    e[++ tot] = zly{v, head[u]};
    head[u] = tot;
}

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

bool fff(int x)
{
    for(int i = head[x]; i; i = e[i].nx)
    {
        int to = e[i].to;
        if(vis[to])
            continue;
        vis[to] = 1;
        if(!mat[to] || fff(mat[to]))
        {
            mat[to] = x;
            return 1;
        }
    }
    return 0;
}

void solve()
{
    cin >> n1 >> n2 >> m;
    run(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    int ans = 0;
    run(i, 1, n1)
    {
        ms(vis);
        if(fff(i))
            ans ++;
    }
    cout << ans << '\n';
}
int main() //https://www.luogu.com.cn/problem/P3386
{
    speed
//    t()
    solve();
    return 0;
}
