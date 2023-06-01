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

const ll N = 107;
char s[N];
int dp[N][N], n, m[N];

bool check(int l, int r, int lx)
{
    run(i, l, r)
        if(s[i] != s[l + (i - l) % lx])
            return 0;
    return 1;
}

void DP()
{
    run(len, 2, n)
        run(l, 1, n)
        {
            int r = l + len - 1;
            if(r > n)
                break;
            run(k, l, r - 1) // 整段不折叠的情况下的最优解
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
            run(lx, 1, len >> 1) // 检测是否整段能够折叠，优化答案
            {
                if(len % lx) // 优化时间，整段能折叠的话，总长一定能被折叠长度整除
                    continue;
                if(check(l, r, lx))
                    dp[l][r] = min(dp[l][r], dp[l][l + lx - 1] + 2 + m[len / lx]);
            }
        }
}

void solve()
{
    cin >> s + 1;
    memset(dp, 0x3f, sizeof dp);
    n = strlen(s + 1);
    run(i, 1, n)
        dp[i][i] = 1;
    run(i, 0, 9)
        m[i] = 1;
    run(i, 10, 99)
        m[i] = 2;
    m[100] = 3;
    DP();
    cout << dp[1][n];
}

int main() // https://www.luogu.com.cn/problem/P4302
{
    speed
//    t()
    solve();
    return 0;
}
