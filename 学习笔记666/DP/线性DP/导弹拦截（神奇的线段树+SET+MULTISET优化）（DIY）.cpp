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
int dp[N], ma[N << 2];
int a[N], tot;
set<int> s;
multiset<int> ssr;

void build(int i, int l, int r)
{
    ma[i] = 0;
    if(l == r)
        return;
    int x(i), y(i), m(l, r);
    build(x, l, m), build(y, m + 1, r);
}

void ch(int i, int l, int r, int f, int v)
{
    if(l == r)
    {
        ma[i] = max(ma[i], v);
        return;
    }
    int x(i), y(i), m(l, r);
    if(f <= m)
        ch(x, l, m, f, v);
    else
        ch(y, m + 1, r, f, v);
    ma[i] = max(ma[x], ma[y]);
}

int qq(int i, int l, int r, int ln, int rn)
{
    if(l > rn || r < ln)
        return 0;
    if(l >= ln && r <= rn)
        return ma[i];
    int x(i), y(i), m(l, r);
    return max(qq(x, l, m, ln, rn), qq(y, m + 1, r, ln, rn));
}

void DP()
{
    run(i, 2, tot)
    {
        auto it = s.lower_bound(a[i]);
        if(it != s.end())
        {
            int x = *it;
            int mm = qq(1, 1, 5e4, x, 5e4);
            dp[i] = mm + 1;
            s.insert(a[i]), ch(1, 1, 5e4, a[i], dp[i]);
            continue;
        }
        s.insert(a[i]), dp[i] = 1, ch(1, 1, 5e4, a[i], dp[i]);
    }
}

void solve()
{
    while(cin >> a[++ tot])
        continue;
    tot --;
    s.insert(a[1]), ch(1, 1, 5e4, a[1], 1), dp[1] = 1;
    DP();
    int ans = 0;
    run(i, 1, tot)
    ans = max(ans, dp[i]);
    cout << ans << '\n';
    ans = 0;
    run(i, 1, tot)
    {
        auto it = ssr.lower_bound(a[i]);
        if(it == ssr.end())
        {
            ans ++;
            ssr.insert(a[i]);
            continue;
        }
        ssr.erase(ssr.find(*it)), ssr.insert(a[i]);
    }
    cout << ans;
}

int main() // https://www.luogu.com.cn/problem/P1020
{
    speed
//    t()
    solve();
    return 0;
}
