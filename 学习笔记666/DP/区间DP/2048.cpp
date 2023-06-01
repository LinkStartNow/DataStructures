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

const ll N = 507;
ll dp[N][N], a[N];

void solve()
{
    ll ans = 0;
    int n;
    cin >> n;
    run(i, 1, n)
        cin >> a[i], dp[i][i] = a[i];
    run(len, 2, n)
    {
        run(l, 1, n)
        {
            int r = l + len - 1;
            run(i, l, r - 1)
                if(dp[l][i] == dp[i + 1][r] && dp[l][i])
                    dp[l][r] = max(dp[l][r], dp[l][i] + 1), ans = max(ans, dp[l][r]);
        }
    }
    cout << ans;
}

int main() // https://www.luogu.com.cn/problem/P3146
{
    speed
//    t()
    solve();
    return 0;
}
