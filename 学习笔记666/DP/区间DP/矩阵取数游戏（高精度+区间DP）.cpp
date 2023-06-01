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

#define ssr __int128


using namespace std;

const ll N = 107;
ssr dp[N][N], p[N], ans;
ll a[N];
int n, m;

ssr DP()
{
    rep(l, m - 1, 1)
        run(i, 1, m)
            if(i + l - 1 > m)
                break;
            else
            {
                int j = i + l - 1;
                dp[i][j] = max(dp[i - 1][j] + p[m - l] * a[i - 1], dp[i][j + 1] + p[m - l] * a[j + 1]);
            }
    ssr ans = 0;
    run(i, 1, m)
        ans = max(ans, dp[i][i] + a[i] * p[m]);
    return ans;
}

void ww(ssr a)
{
    if(!a)
        return;
    ww(a / 10);
    putchar(a % 10 + '0');
}

void solve()
{
    cin >> n >> m;
    p[0] = 1;
    run(i, 1, m)
        p[i] = p[i - 1] * 2;
    run(i, 1, n)
    {
        ms(dp);
        run(j, 1, m)
            cin >> a[j];
        ans += DP();
    }
    if(!ans)
        puts("0");
    else
        ww(ans);
}

int main() // https://www.luogu.com.cn/problem/P1005
{
    speed
//    t()
    solve();
    return 0;
}
