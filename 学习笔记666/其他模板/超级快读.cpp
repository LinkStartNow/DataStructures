#include<bits/stdc++.h>

#define ll long long
#define lb long double
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
char buf[100000], *pa = buf, *pd = buf;
#define gc pa == pd && (pd = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pd) ? EOF: *pa++

using namespace std;

const ll N = 1e5 + 7, p = 1e15;
vector<ll> v;

ll lowbit(ll x)
{
    return x & -x;
}

ll spow(ll x, ll y)
{
    ll res = 1;
    while(y)
    {
        if(y & 1)
            res = (res * x) % p;
        x = (x * x) % p;
        y >>= 1;
    }
    return res;
}

ll read()
{
    int f = 1; ll res = 0; char c = gc;
    for(; c > '9' || c < '0'; c = gc) if(c == '-') f = -1;
    for(; c >= '0' && c <= '9'; c = gc) res = res * 10 + c - '0';
    return res * f;
}


void solve()
{
    int n;
    scanf("%d", &n);
    ll ans = 0;
    run(i, 1, n) ans += read();
    printf("%lld", ans);
}

int main()
{
    speed
//    t()
    solve();
    return 0;
}