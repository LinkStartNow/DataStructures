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

const ll N = 2e5 + 7;
ll dp[15][107][1007]; // 枚举到第i层时国王个数和为j并且状态为k
bool fail[1007];
int n, k;
vector<int> v[15];

int yyds(int x)
{
    int cnt = 0;
    while(x)
    {
        if(x & 1)
            cnt ++;
        x >>= 1;
    }
    return cnt;
}

void DP()
{
    run(i, 1, n)
    run(g, 0, min(n * i, k)) // 由于多开了一层记录状态所以正序倒序都不影响
    {
        run(j, 0, g)
        {
            for(auto x : v[j])
            {
                int k = g - j; // 根据dp的定义这个k必须是剩余要补的空间，使得总共的国王和刚好是g
                run(y, 0, (1 << n) - 1) // 要把上一个状态的所有情况枚举，不然会漏
                {
                    if(((x << 1) & y) || ((x >> 1) & y) || fail[y] || (x & y)) // 这里考虑的时候一定要思路清晰啊，不然少排除了会错的
                        continue;
                    dp[i][g][x] += dp[i - 1][k][y];
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> k;
    dp[0][0][0] = 1;
    run(i, 0, (1 << n) - 1)
    {
        fail[i] = (i & (i << 1)) | (i & (i >> 1));
        if(!fail[i])
            v[yyds(i)].push_back(i);
    }
    DP();
    ll ans = 0;
    run(i, 0, (1 << n) - 1)
    ans += dp[n][k][i];
    cout << ans;
}

int main() // https://www.luogu.com.cn/problem/P1896
{
    speed
//    t()
    solve();
    return 0;
}
