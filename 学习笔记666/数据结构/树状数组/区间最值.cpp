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
const int N = 2e5 + 7;
ll a[N], ma[N], mi[N];
ll n, m;

ll spow(ll x, ll y)
{
    ll res = 1;
    while(y)
    {
        if(y & 1)
            res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

ll lowbit(ll x)
{
    return x & -x;
}

void add(ll i, ll x)
{
    while(i <= n)
    {
        ma[i] = max(ma[i], x);
        mi[i] = min(mi[i], x);
        i += lowbit(i);
    }
}

ll finda(ll l, ll r)
{
    if(l == r)
        return a[l];
    if(r - lowbit(r) + 1 > l) // r - lowbit(r) + 1为ma【r】所管理的左边界
        return max(ma[r], finda(l, r - lowbit(r)));
    if(r - lowbit(r) + 1 == l)
        return ma[r];
    return max(a[r], finda(l, r - 1));
}

ll findi(ll l, ll r)
{
    if(l == r)
        return a[l];
    if(r - lowbit(r) + 1 > l)
        return min(mi[r], findi(l, r - lowbit(r)));
    if(r - lowbit(r) + 1 == l)
        return mi[r];
    return min(a[r], findi(l, r - 1));
}

void solve()
{

    cin >> n >> m;
    run(i, 1, n)
    mi[i] = 1e9 + 7;
    run(i, 1, n)
    {
        cin >> a[i];
        add(i, a[i]);
    }
    while(m --)
    {
        ll l, r;
        cin >> l >> r;
        cout << finda(l, r) - findi(l, r) << '\n';
    }
}
int main() //https://www.luogu.com.cn/problem/P2880
{
    speed
//    t()
    solve();
    return 0;
}
