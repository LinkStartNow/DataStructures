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
ll dp[123][123][123], mp[123];
int n, m, a[2333];
char s[N];
int v[123], tot; // 超级牛的优化，也就是离散化啦哈哈哈

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

void init()
{
    run(i, 0, (1 << m) - 1)
    {
        if((i & (i << 1)) || (i & (i << 2)) || (i & (i >> 1)) || (i & (i >> 2)))
            continue;
        v[++ tot] = i, a[i] = yyds(i);
    }
    run(i, 1, tot)
    {
        if((v[i] | mp[1]) > mp[1])
            continue;
        dp[1][i][0] = a[v[i]];
    }
    run(i, 1, tot)
    {
        if((v[i] | mp[2]) > mp[2])
            continue;
        run(j, 1, tot)
        {
            if((v[j] | mp[1]) > mp[1] || (v[i] & v[j]))
                continue;
            dp[2][i][j] = dp[1][j][0] + a[v[i]];
        }
    }
}

void DP()
{
    run(i, 3, n)
    {
        run(j, 1, tot)
        {
            if((v[j] | mp[i]) > mp[i])
                continue;
            run(k, 1, tot)
            {
                if((v[k] | mp[i - 1]) > mp[i - 1] || (v[k] & v[j]))
                    continue;
                run(kk, 1, tot)
                {
                    if((v[kk] | mp[i - 2]) > mp[i - 2] || (v[kk] & v[j]) || (v[kk] & v[k]))
                        continue;
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][k][kk] + a[v[j]]);
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    run(i, 1, n)
    {
        cin >> s + 1;
        run(j, 1, m)
        mp[i] = (mp[i] << 1) + (s[j] == 'P');
    }
    init();
    DP();
    ll ans = 0;
    run(i, 0, tot)
        run(j, 0, tot)
            if(!(v[i] & v[j]))
                ans = max(ans, dp[n][i][j]);
    cout << ans;
}

int main() // https://www.luogu.com.cn/problem/P2704
{
    speed
//    t()
    solve();
    return 0;
}
