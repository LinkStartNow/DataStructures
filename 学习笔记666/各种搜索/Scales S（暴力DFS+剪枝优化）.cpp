#include<bits/stdc++.h>

#define ll long long
//#define lb long double
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
//char buf[100000], *pa = buf, *pd = buf;
//#define gc pa == pd && (pd = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pd) ? EOF: *pa++

using namespace std;

const ll N = 1007;
ll a[N], sum[N]; // a为原数组，sum为前缀和数组方便剪枝
ll n, c;
ll ans, s;

void dfs(ll x)
{
    rep(i, x - 1, 1)
    {
        if(s + sum[i] <= ans)
            break;
        if(s + a[i] > c)
            continue;
        s += a[i];
        ans = max(ans, s);
        dfs(i);
        s -= a[i];
    }
}

void solve()
{
    cin >> n >> c;
    run(i, 1, n) cin >> a[i], sum[i] += sum[i - 1] + a[i];
    rep(i, n, 1)
    {
        if(sum[i] <= ans)
            break;
        if(a[i] > c)
            continue;
        s += a[i], ans = max(ans, s), dfs(i), s -= a[i];
    }
    cout << ans;
}


int main() // https://www.luogu.com.cn/problem/P5194
{
    speed
//    t()
    solve();
    return 0;
}
