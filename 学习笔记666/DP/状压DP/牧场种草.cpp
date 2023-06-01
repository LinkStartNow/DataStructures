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

const ll N = 2e3 + 7, p = 100000000;
int n, m;
bool a[15][15], fail[5007];
ll dp[15][5007], b[15], t;

void DP()
{
    dp[0][0] = 1;
    t = (1 << m) - 1;
    run(i, 1, n)
        run(j, 0, t)
            if(!fail[j] && (j | b[i]) <= b[i])
                run(k, 0, t)
                if(!fail[k] && (k | b[i - 1]) <= b[i - 1] && !(k & j))
                    dp[i][j] += dp[i - 1][k], dp[i][j] %= p;
}

void solve()
{
    cin >> n >> m;
    run(i, 1, n)
        run(j, 1, m)
            cin >> a[i][j], b[i] = (b[i] << 1) + a[i][j];
    run(i, 1, 1 << m)
        if((i & (i << 1)) || (i & (i >> 1)))
            fail[i] = 1;
    DP();
    ll ans = 0;
    run(i, 0, t)
        ans += dp[n][i], ans %= p;
    cout << ans;
}

int main() // https://www.luogu.com.cn/problem/P1879
{
    speed
//    t()
    solve();
    return 0;
}
