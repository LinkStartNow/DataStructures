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

const ll N = 1007, p = 1000000007;
char s[N], st[N];
ll dp[2][207][207][2];
int n, nt, t;
ll ans;

ll DP()
{
    bool f = 0;
    run(i, 1, n)
    {
        f ^= 1;
        bool ff = f ^ 1;
        run(j, 1, nt)
        run(k, 1, t)
        {
            dp[f][j][k][0] = (dp[ff][j][k][0] + dp[ff][j][k][1]) % p;
            if(s[i] == st[j])
                dp[f][j][k][1] = (dp[ff][j - 1][k][1] + dp[ff][j - 1][k - 1][1] + dp[ff][j - 1][k - 1][0]) % p;
            else
                dp[f][j][k][1] = 0;
        }
    }
    return (dp[f][nt][t][0] + dp[f][nt][t][1]) % p;
}

void solve()
{
    cin >> n >> nt >> t >> s + 1 >> st + 1;
    dp[0][0][0][0] = dp[1][0][0][0] = 1;
    cout << DP();
}

int main() // https://www.luogu.com.cn/problem/P2679
{
    speed
//    t()
    solve();
    return 0;
}
