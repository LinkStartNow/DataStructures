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
            run(x, 0, min(j, siz[v])) // �����ԭ����Ҫ�ȸ���0���ڵ���������Ϊ0���ڵ�Ҳ����ֵ�ģ�����ֵ��ʱ��ֵΪ��0������Ҫ�ȸ��£���Ȼ�����Ĵ𰸾Ϳ��ܻ���
            {
                if(dp[u][j - x] == -1) // ��ǰ�����������֮ǰ��������С�ͻ�����j-x��x��Сʱ��״̬�ǻ�û�����¹��Ĳ��Ϸ�״̬
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
    memset(dp, -1, sizeof dp); // ��ΪҪ�жϷǷ��������Ҫ��ʼ��Ϊ-1�����
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
