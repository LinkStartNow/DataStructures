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
int n, c;
int f[N];

struct zly
{
    int x, y;
    ll w;
} p[N];

int fa(int x)
{
    return x == f[x] ? x : f[x] = fa(f[x]);
}

bool yyds(ll x)
{
    run(i, 1, n << 1)
        f[i] = i;
    run(i, 1, c)
    {
        if(p[i].w > x)
        {
            int a = p[i].x, b = p[i].y;
            int A = fa(a), B = fa(b);
            if(A == B)
                return 0;
            f[fa(a + n)] = B;
            f[fa(a)] = fa(b + n);
        }
    }
    return 1;
}

void solve()
{
    cin >> n >> c;
    run(i, 1, c)
        cin >> p[i].x >> p[i].y >> p[i].w;
    ll l = 0, r = 1e9;
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        if(yyds(m))
            r = m - 1;
        else
            l = m + 1;
    }
    cout << l << '\n';
}

int main() // https://www.luogu.com.cn/problem/P1525
{
    speed
//    t()
    solve();
    return 0;
}
