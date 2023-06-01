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

const ll N = 1e6 + 7;
ll dp[3];
int n;

void DP()
{
    int t;
    cin >> t;
    dp[t + 1] = 0;
    run(i, 2, n)
    {
        cin >> t;
        if(t == -1)
        {
            dp[1] = 1e15;
            dp[2] += 2;
        }
        else if(!t)
        {
            dp[1] = min(dp[0], dp[1]);
            dp[0] ++;
            dp[2] ++;
        }
        else
        {
            dp[2] = min({dp[0], dp[1], dp[2]});
            dp[1] = dp[0] + 1;
            dp[0] += 2;
        }
    }
    ll ans = min({dp[0], dp[1], dp[2]});
    if(ans >= 1e15)
        puts("BRAK");
    else
        cout << ans;
}

void solve()
{
    cin >> n;
    dp[0] = dp[1] = dp[2] = 1e15;
    DP();
}

int main() // https://www.luogu.com.cn/problem/P3558
{
    speed
//    t()
    solve();
    return 0;
}