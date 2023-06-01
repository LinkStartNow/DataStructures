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

const ll N = 1e5 + 7, p = 1e9 + 7;
ll dp[207][207][207];
int na, nb;
char s[207];

ll DP()
{
    /* 由已知状态往下推 */
    run(i, 0, nb)
        run(j, 0, i)
            run(k, 0, i)
            {
                if(!dp[i][j][k])
                    continue;
                int ssr = j + (s[j + 1] == '('); // 判断a中下一个是不是左括号
                dp[i + 1][ssr][k + 1] = (dp[i + 1][ssr][k + 1] + dp[i][j][k]) % p; // 推测下一位是左括号的状态
                ssr = j + (s[j + 1] == ')');
                if(k) // 没有多余的左括号了就不用加右括号了，不然就是非法括号序列了
                    dp[i + 1][ssr][k - 1] = (dp[i + 1][ssr][k - 1] + dp[i][j][k]) % p; // 推测下一位是右括号的状态
            }
    return dp[nb][na][0];
}

void solve()
{
    cin >> na >> nb >> s + 1;
    run(i, 0, nb)
    run(j, 0, na)
    run(k, 0, nb)
    dp[i][j][k] = 0; // 手动清零，防止爆时间
    dp[0][0][0] = 1;
    cout << DP() << '\n';
}

int main() // https://ac.nowcoder.com/acm/contest/33187/K
{
    speed
    t()
    solve();
    return 0;
}
