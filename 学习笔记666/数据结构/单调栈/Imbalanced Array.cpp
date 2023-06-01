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

const int N = 1e6 + 7;
struct zly
{
    ll v, id;
} a[N];
ll s[N];
stack<zly> yi;
ll li[N], ri[N], ra[N], la[N];

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
            if(a[i].v <= yi.top().v)
                yi.pop();
            else
            {
                ri[i] = yi.top().id;
                yi.push(a[i]);
                f = 1;
                break;
            }
        }
        if(!f)
        {
            ri[i] = n + 1;
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
                li[i] = yi.top().id;
                yi.push(a[i]);
                f = 1;
                break;
            }
        }
        if(!f)
        {
            li[i] = 0;
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
            if(a[i].v > yi.top().v)
                yi.pop();
            else
            {
                la[i] = yi.top().id;
                yi.push(a[i]);
                f = 1;
                break;
            }
        }
        if(!f)
        {
            la[i] = 0;
            yi.push(a[i]);
        }
    }
    while(!yi.empty())
        yi.pop();
    rep(i, n, 1)
    {
        bool f = 0;
        while(!yi.empty())
        {
            if(a[i].v >= yi.top().v)
                yi.pop();
            else
            {
                ra[i] = yi.top().id;
                yi.push(a[i]);
                f = 1;
                break;
            }
        }
        if(!f)
        {
            ra[i] = n + 1;
            yi.push(a[i]);
        }
    }
    ll ans = 0;
    run(i, 1, n)
    {
        ll aa = i - li[i], b = ri[i] - i;
        ll c = i - la[i], d = ra[i] - i;
        ans += a[i].v * (c * d - aa * b);
    }
    printf("%lld\n", ans);
}
int main() //https://codeforces.com/problemset/problem/817/D
{
    speed
//    t()
    solve();
    return 0;
}
