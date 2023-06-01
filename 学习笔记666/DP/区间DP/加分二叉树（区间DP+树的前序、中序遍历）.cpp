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

const ll N = 233;
ll a[N], dp[N][N], root[N][N];
int n;

void DP()
{
    run(l, 2, n)
        run(i, 1, n)
            if(i + l - 1 > n)
                break;
            else
            {
                int j = i + l - 1;
                run(k, i, j)
                if((dp[i][k - 1] * dp[k + 1][j]) + dp[k][k] > dp[i][j])
                {
                    root[i][j] = k;
                    dp[i][j] = (dp[i][k - 1] * dp[k + 1][j]) + dp[k][k];
                }
            }
}

void dfs(int l, int r)
{
    if(l > r)
        return;
    int rt = root[l][r];
    printf("%d ", rt);
    if(l == r)
        return;
    dfs(l, rt - 1), dfs(rt + 1, r);
}

void solve()
{
    cin >> n;
    run(i, 1, n)
        cin >> a[i], dp[i][i] = a[i], root[i][i] = i, dp[i][i - 1] = 1;
    DP();
    printf("%lld\n", dp[1][n]);
    dfs(1, n);
}

int main() // https://www.luogu.com.cn/problem/P1040
{
    speed
//    t()
    solve();
    return 0;
}
