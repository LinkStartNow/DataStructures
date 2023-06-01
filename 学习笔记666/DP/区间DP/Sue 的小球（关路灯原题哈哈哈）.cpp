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

const ll N = 3007;
ll dp[N][N][2], s, v[N];
int n, p;

struct egg
{
    ll x, y, v;
    bool operator<(const egg &b) const
    {
        return x < b.x;
    }
} e[N];

void DP()
{
    run(l, 2, n + 1)
        run(i, 1, n + 1)
            if(i + l - 1 > n + 1)
                break;
            else
            {
                int j = i + l - 1;
                dp[i][j][0] = min(dp[i + 1][j][0] + (e[i + 1].x - e[i].x) * (v[i] + v[n + 1] - v[j]),
                                  dp[i + 1][j][1] + (e[j].x - e[i].x) * (v[i] + v[n + 1] - v[j]));
                dp[i][j][1] = min(dp[i][j - 1][0] + (e[j].x - e[i].x) * (v[i - 1] + v[n + 1] - v[j - 1]),
                                  dp[i][j - 1][1] + (e[j].x - e[j - 1].x) * (v[i - 1] + v[n + 1] - v[j - 1]));
            }
}

int fff(int x)
{
    int l = 1, r = n + 1;
    while(l <= r)
    {
        int m = (l + r) >> 1;
        if(e[m].x > x)
            r = m - 1;
        else
            l = m + 1;
    }
    return r;
}

void solve()
{
    cin >> n >> p;
    run(i, 1, n)
    cin >> e[i].x;
    run(i, 1, n)
    cin >> e[i].y, s += e[i].y;
    run(i, 1, n)
    cin >> e[i].v;
    run(i, 1, n + 1)
    run(j, 1, n + 1)
    dp[i][j][0] = dp[i][j][1] = 1e16;
    e[n + 1] = {p, 0, 0};
    sort(e + 1, e + 2 + n);
    run(i, 1, n + 1)
        v[i] = v[i - 1] + e[i].v;
    p = fff(p);
    dp[p][p][0] = dp[p][p][1] = 0;
    DP();
    printf("%.3f", ((double)s - min(dp[1][n + 1][0], dp[1][n + 1][1])) / 1000);
}

int main() // https://www.luogu.com.cn/problem/P2466
{
    speed
//    t()
    solve();
    return 0;
}
