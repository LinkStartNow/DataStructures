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

struct op
{
    bool k;
    ll x;
} o[N];

set<ll> a;
multiset<ll> s;
ll sum, ac;

void add(ll x)
{
    a.insert(x);
    auto it = a.find(x);
    if(next(it) != a.end())
        s.insert(*next(it) - x);
    if(it != a.begin())
    {
        s.insert(x - *prev(it));
        if(next(it) != a.end())
            s.erase(s.find(*next(it) - *prev(it)));
    }
}

void rem(ll x)
{
    auto it = a.find(x);
    if(next(it) != a.end())
        s.erase(s.find(*next(it) - x));
    if(it != a.begin())
    {
        s.erase(s.find(x - *prev(it)));
        if(next(it) != a.end())
            s.insert(*next(it) - *prev(it));
    }
    a.erase(x);
}

void ww()
{
    if(a.size() <= 2)
        cout << 0 << '\n';
    else
        cout << *a.rbegin() - *a.begin() - *s.rbegin() << '\n';
}

void solve()
{
    int n, q;
    cin >> n >> q;
    run(i, 1, n)
    {
        ll t;
        cin >> t;
        a.insert(t);
    }
    ll ssr = 0;
    for(auto x : a)
    {
        if(!ssr)
        {
            ssr = x;
            continue;
        }
        ll t = x - ssr;
        s.insert(t);
        ssr = x;
    }
    ww();
    run(i, 1, q)
    {
        bool k;
        ll x;
        cin >> k >> x;
        if(k)
            add(x);
        else
            rem(x);
        ww();
    }
}

int main() // https://codeforces.com/problemset/problem/1418/D
{
    speed
//    t()
    solve();
    return 0;
}
