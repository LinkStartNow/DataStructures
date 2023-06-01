#include<bits/stdc++.h>

#define ll long long
#define lb long double
#define run(i, a, b) for(ll i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);
char buf[100000], *pa = buf, *pd = buf;
#define gc pa == pd && (pd = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pd) ? EOF: *pa++

using namespace std;

const ll N = 1e6 + 7;
int dp[1007][1007];

void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    while(n --)
    {
        int t;
        cin >> t;
        int h = t / 1000, l = t % 1000; // 由于数字大小不超过1e6固可以分成前3位和后三位
        int fh = 999 - h, fl = 999 - l;
        int h1 = fh / 100, h2 = fh / 10 % 10, h3 = fh % 10; // 各位上不会产生进位的最大数
        int l1 = fl / 100, l2 = fl / 10 % 10, l3 = fl % 10;

        run(i, 0, l1)
            run(j, 0, l2)
                run(k, 0, l3)
                    ans += dp[h][i * 100 + j * 10 + k];

        run(i, 0, h1)
            run(j, 0, h2)
                run(k, 0, h3)
                    dp[i * 100 + j * 10 + k][l] ++;
    }
    cout << ans;
}

int main() // https://ac.nowcoder.com/acm/contest/38305/C
{
    speed
//    t()
    solve();
    return 0;
}