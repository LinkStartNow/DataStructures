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

const ll N = 2e4 + 7;
ll a[107][107], dp[N];

void solve()
{
    int n, s, q;
    cin >> s >> n >> q;
    run(i, 1, s)
        run(j, 1, n)
            cin >> a[j][i];
    run(i, 1, n)
        sort(a[i] + 1, a[i] + 1 + s);
    run(i, 1, n)
        rep(j, q, 0)
            run(k, 1, s)
                if(j < a[i][k] * 2 + 1)
                    break;
                else
                    dp[j] = max(dp[j], dp[j - a[i][k] * 2 - 1] + i * k);
    ll ans = 0;
    run(i, 1, q)
        ans = max(ans, dp[i]);
    cout << ans;
}

int main() // https://www.luogu.com.cn/problem/P5322
{
    speed
//    t()
    solve();
    return 0;
}
