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

const int N = 1e6 +7;
ll num[N], ans, n;
vector<ll> li;
//unordered_map<ll, ll> mp;
ll tz[N], tf[N];
ll gz[N], gf[N];

ll lowbit(ll x)
{
    return x & -x;
}

ll qq(int i, ll *a)
{
    ll res = 0;
    while(i)
    {
        res += a[i];
        i -= lowbit(i);
    }
    return res;
}

void add(int i, int x, ll *a)
{
    while(i <= n)
    {
        a[i] += x;
        i += lowbit(i);
    }
}

void solve()
{
    cin >> n;
    run(i, 1, n)
    cin >> num[i], li.push_back(num[i]);
    sort(li.begin(), li.end());
    run(i, 1, n)
        num[i] = lower_bound(li.begin(), li.end(), num[i]) - li.begin() + 1;
    rep(i, n, 1)
    {
        gf[i] = qq(num[i], tf);
        add(num[i], 1, tf);
    }
    run(i, 1, n)
    {
        add(num[i], 1, tz);
        gz[i] = i - qq(num[i], tz);
    }
    run(i, 1, n)
    ans += gz[i] * gf[i];
    cout << ans << '\n';
}

int main() // https://codeforces.com/problemset/problem/61/E
{
    speed
//    t()
    solve();
    return 0;
}
