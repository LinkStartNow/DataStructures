#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) mid = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int N = 1e5 + 7;
struct zly
{
    int v, id;
} a[N];
ll s[N];
stack<zly> yi;
int l[N], r[N];

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


void solve()
{
    int n;
    cin >> n;
    run(i, 1, n)
        cin >> a[i].v, a[i].id = i, s[i] += s[i - 1] + a[i].v;
    rep(i, n, 1)
    {
        bool f = 0;
        while(!yi.empty())
        {
            if(a[i].v < yi.top().v)
                yi.pop();
            else
            {
                r[i] = yi.top().id;
                yi.push(a[i]);
                f = 1;
                break;
            }
        }
        if(!f)
        {
            r[i] = 0;
            yi.push(a[i]);
        }
    }
    while(!yi.empty())
        yi.pop();
    run(i, 1, n)
    {
        bool f = 0;
        while(!yi.empty())
        {
            if(a[i].v < yi.top().v)
                yi.pop();
            else
            {
                l[i] = yi.top().id;
                yi.push(a[i]);
                f = 1;
                break;
            }
        }
        if(!f)
        {
            l[i] = 0;
            yi.push(a[i]);
        }
    }
    ll ans = 0;
    run(i, 1, n)
    {
        int lll = l[i] == 0 ? 0 : l[i], rrr = r[i] == 0 ? n + 1 : r[i];
        ans = max(ans, (ll)a[i].v * (s[rrr - 1] - s[lll]));
    }
    printf("%lld\n", ans);
}
int main() //https://www.luogu.com.cn/problem/P2422
{
    speed
//    t()
    solve();
    return 0;
}
