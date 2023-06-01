#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(ll i = a; i <= b; i ++)
#define rep(i, a, b) for(ll i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int N = 1e6 + 7;
ll a[N], s[N];
int n;
ll x1[N], x2[N];
ll li[N];

ll lowbit(ll x)
{
    return x & -x;
}

void add(int i, int x, ll *c)
{
    while(i)
        c[i] += x, i -= lowbit(i);
}

ll qq(int i, ll *c)
{
    ll res = 0;
    while(i <= n)
        res += c[i], i += lowbit(i);
    return res;
}

void solve()
{
    cin >> n;
    run(i, 1, n)
        cin >> a[i], s[i] = a[i];
    sort(s + 1, s + 1 + n);
    ll ans = 0;
    run(i, 1, n)
        li[i] = lower_bound(s + 1, s + n + 1, a[i]) - s;
    run(i, 1, n)
    {
        int x = li[i];
        ans += qq(x, x2);
        add(x, qq(x, x1), x2);
        add(x, 1, x1);
    }
    cout << ans << '\n';
}

int main() // https://codeforces.com/problemset/problem/61/E
{
    speed
//    t()
    solve();
    return 0;
}
