#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(ll i = a; i <= b; i ++)
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
const int N = 2e5 + 7;
bool dp[57][57][65];
ll dis[57][57];
int n, m;

ll spow(ll x, ll y)
{
    ll res = 1;
    while(y)
    {
        if(y & 1)
            res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

ll lowbit(ll x)
{
    return x & -x;
}

void yyds()
{
    run(s, 1, 64)
    run(k, 1, n)
    run(i, 1, n)
    run(j, 1, n)
    if(dp[i][j][s - 1] && dp[j][k][s - 1])
        dp[i][k][s] = dis[i][k] = 1;
}

void flord()
{
    run(k, 1, n)
        run(i, 1, n)
            run(j, 1, n)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

void solve()
{
    memset(dis, 0x3f, sizeof dis);
    cin >> n >> m;
    while(m --)
    {
        int a, b;
        cin >> a >> b;
        dp[a][b][0] = 1;
        dis[a][b] = 1;
    }
    yyds();
    flord();
    cout << dis[1][n] << '\n';
}
int main() //https://www.luogu.com.cn/problem/P1613
{
    speed
//    t()
    solve();
    return 0;
}
