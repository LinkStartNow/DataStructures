#include<bits/stdc++.h>

#define ll long long
#define lb long double
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(ll i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

const ll N = 2e4 + 7;
const double ssr = 1e-10;
bool vis[N]; // 标记点时候在队列中
int cnt[N]; // 标记每个点被松弛的次数
double dis[N]; // 每个点到万能源点的距离
int n, m;

struct edge
{
    int to, nx;
    double v;
}   e[N << 2];

int head[N], tot;
void add(int u, int v, double w)
{
    e[++ tot] = {v, head[u], w};
    head[u] = tot;
}

bool spfa(double x) // 最长路判正环
{
    queue<int> q;
    run(i, 1, n)
    {
        cnt[i] = dis[i] = 0;
        vis[i] = 1;
        q.push(i); // 把每个点塞入队列进行判断
    }
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        vis[p] = 0;
        for(int i = head[p]; i; i = e[i].nx)
        {
            int to = e[i].to;
            double w = e[i].v + log(x);
            if(dis[to] < dis[p] + w)
            {
                dis[to] = dis[p] + w;
                cnt[to] = cnt[p] + 1; // 非常重要的优化，不这样计算次数可能会误判，而且这种方法能减少时间
                if(cnt[to] > n + 1) // 每个点最多被松弛n次，多开几次保险一点
                    return 1;
                if(!vis[to]) // 被松弛的点不在队列中则加入队列
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
    cin >> n >> m;
    run(i, 1, m)
    {
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        add(b, d, log(c / a));
    }
    double l = 0, r = 1;
    while(r - l >= ssr)
    {
        double mid = (l + r) / 2;
        if(spfa(mid))
            r = mid;
        else
            l = mid;
    }
    printf("%.10f", l);
}

int main() // https://ac.nowcoder.com/acm/contest/33187/D
{
    speed
//    t()
    solve();
    return 0;
}