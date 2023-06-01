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

const ll N = 1e6 + 7, ssr = 9187201950435737471;
int a[N];
ll dp[N][3];
int n;

void DP()
{
    dp[1][a[1] + 1] = 0;
    run(i, 2, n)
    {
        int t = a[i];
        if(t == -1)
        {
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
            dp[i][2] = min(dp[i - 1][2] + 2, dp[i][2]);
        }
        else if(!t)
        {
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + 1);
            dp[i][1] = min({dp[i][1], dp[i - 1][0], dp[i - 1][1]});
            dp[i][2] = min(dp[i][2], dp[i - 1][2] + 1);
        }
        else
        {
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + 2);
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
            dp[i][2] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        }
    }
    ll ans = min({dp[n][0], dp[n][1], dp[n][2]});
    if(ans == 1e15)
        puts("BRAK");
    else
        cout << ans;
}

void solve()
{
    cin >> n;
    run(i, 1, n) cin >> a[i];
    run(i, 1, n)
        run(j, 0, 2)
            dp[i][j] = 1e15;
    DP();
}

int main() // https://www.luogu.com.cn/problem/P3558
{
    speed
//    t()
    solve();
    return 0;
}
