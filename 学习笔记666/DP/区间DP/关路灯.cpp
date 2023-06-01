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

const ll N = 57;
ll a[N], w[N];
ll dp[N][N][2];

void solve()
{
    int n, c;
    cin >> n >> c;
    run(i, 1, n)
        cin >> a[i] >> w[i], w[i] += w[i - 1];
    memset(dp, 0x7f, sizeof dp);
    dp[c][c][0] = dp[c][c][1] = 0;
    run(l, 2, n)
        run(i, 1, n - l + 1)
        {
            int j = i + l - 1;
            dp[i][j][0] = min(dp[i + 1][j][0] + (a[i + 1] - a[i]) * (w[i] + w[n] - w[j]),
                              dp[i + 1][j][1] + (a[j] - a[i]) * (w[i] + w[n] - w[j]));
            dp[i][j][1] = min(dp[i][j - 1][1] + (a[j] - a[j - 1]) * (w[i - 1] + w[n] - w[j - 1]),
                              dp[i][j - 1][0] + (a[j] - a[i]) * (w[i - 1] + w[n] - w[j - 1]));
        }
    cout << min(dp[1][n][0], dp[1][n][1]);
}

int main() // https://www.luogu.com.cn/problem/P1220
{
    speed
//    t()
    solve();
    return 0;
}
