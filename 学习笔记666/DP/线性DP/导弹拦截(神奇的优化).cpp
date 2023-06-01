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

const ll N = 1e5 + 7;
int f[N];
int a[N], tot, ans;

void DP(bool fg)
{
    if(fg)
    {
        ans = 0;
        memset(f, 0, sizeof f);
        f[0] = 1e9;
        run(i, 1, tot)
        {
            int l = 0, r = ans;
            while(l <= r)
            {
                int m(l, r);
                if(f[m] >= a[i])
                    l = m + 1;
                else
                    r = m - 1;
            }
            ans = max(ans, r + 1);
            f[r + 1] = max(f[r + 1], a[i]);
        }
    }
    else
    {
        ans = 0;
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        run(i, 1, tot)
        {
            int l = 0, r = ans;
            while(l <= r)
            {
                int m(l, r);
                if(f[m] < a[i])
                    l = m + 1;
                else
                    r = m - 1;
            }
            ans = max(ans, r + 1);
            f[r + 1] =  min(f[r + 1], a[i]);
        }
    }
}

void solve()
{
    while(cin >> a[++ tot]);
    -- tot;
    DP(1);
    cout << ans << '\n';
    DP(0);
    cout << ans;
}

int main() // https://www.luogu.com.cn/problem/P1020
{
    speed
//    t()
    solve();
    return 0;
}