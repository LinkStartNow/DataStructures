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

const ll N = 2e3 + 7;
ll dp[N][N];
int n, k, siz[N];

struct edge
{
    int to, nx;
    ll v;
} e[N << 1];

int head[N], tot;
void add(int u, int v, ll w)
{
    e[++ tot] = {v, head[u], w};
    head[u] = tot;
}

void DP(int u, int fa)
{
    siz[u] = 1, dp[u][1] = dp[u][0] = 0;
    for(int i = head[u]; i; i = e[i].nx)
    {
        int v = e[i].to;
        ll w = e[i].v;
        if(v == fa)
            continue;
        DP(v, u);
        siz[u] += siz[v];
        rep(j, min(siz[u], k), 0)
        {
            run(x, 0, min(j, siz[v])) // 正序的原因是要先更新0个黑点的情况，因为0个黑点也是有值的，而赋值的时候赋值为了0，所以要先更新，不然其他的答案就可能会少
            {
                if(dp[u][j - x] == -1) // 当前的子树过大比之前的子树大小和还大导致j-x在x过小时的状态是还没被更新过的不合法状态
                    continue;
                ll tt = w * (x * (k - x) + (siz[v] - x) * (n - k - siz[v] + x));
                dp[u][j] = max(dp[u][j], dp[u][j - x] + dp[v][x] + tt);
            }
        }
    }
}

void solve()
{
    cin >> n >> k;
    run(i, 1, n - 1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }
    memset(dp, -1, sizeof dp); // 因为要判断非法情况所以要初始化为-1做标记
    DP(1, 1);
    cout << dp[1][k];
}



int main() // https://www.luogu.com.cn/problem/P3177
{
    speed
//    t()
    solve();
    return 0;
}
