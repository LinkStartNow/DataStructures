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

const ll N = 2e3 + 7;
// 每个状态由一串二进制数表示，第i位为1表示第i头奶牛在电梯中，为0则表示不在
int dp[1 << 18]; // i状态时最少的电梯次数
int g[1 << 18]; // i状态时最后一辆电梯的剩余空间
int a[20]; // 存奶牛的体积
int n, w;

void DP()
{
    run(i, 0, (1 << n) - 1) // 枚举状态
        run(j, 1, n) // 枚举牛
            {
                int t = 1 << (j - 1);
                if(i & t) // 牛上已经电梯了
                    continue;
                if(g[i] >= a[j] && dp[i | t] >= dp[i]) // 牛能放进剩余空间
                {
                    dp[i | t] = dp[i];
                    g[i | t] = max(g[i | t], g[i] - a[j]); // 跟原先比较是为了进一步优化电梯空间
                }
                else if(g[i] < a[j] && dp[i | t] >= dp[i] + 1) // 牛放不进
                {
                    dp[i | t] = dp[i] + 1;
                    g[i | t] = max(g[i | t], w - a[j]);
                }
            }
}

void solve()
{
    cin >> n >> w;
    run(i, 1, n)
        cin >> a[i];
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 1, g[0] = w;
    DP();
    cout << dp[(1 << n) - 1];
}

int main() // https://www.luogu.com.cn/problem/P3052
{
    speed
//    t()
    solve();
    return 0;
}
