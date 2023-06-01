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

const ll N = 3e5 + 7;
ll a[N][10], b[N];
bool vis[500];
int n, m;
ll ans0, ans1;

bool yyds(ll x)
{
    ms(vis);
    run(i, 1, n)
    {
        b[i] = 0;
        int k = 1;
        run(j, 1, m)
        {
            if(a[i][j] >= x)
                b[i] += k;
            k <<= 1;
        }
        vis[b[i]] = 1;
    }
    run(i, 1, 255)
    if(vis[i])
        run(j, 1, 255)
        if(vis[j] && ((i | j) == (1 << m) - 1))
        {
            ans0 = ans1 = 0;
            run(k, 1, n)
            {
                if(b[k] == i)
                    ans0 = k;
                if(b[k] == j)
                    ans1 = k;
                if(ans0 && ans1)
                    return 1;
            }
        }
    return 0;
}

void solve()
{
    ll l = 1e9, r = 0;
    cin >> n >> m;
    run(i, 1, n)
    run(j, 1, m)
    cin >> a[i][j], l = min(l, a[i][j]), r = max(r, a[i][j]);
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        if(yyds(m))
            l = m + 1;
        else
            r = m - 1;
    }
    printf("%lld %lld\n", ans0, ans1);
}

int main() // https://codeforces.com/problemset/problem/1288/D
{
    speed
//    t()
    solve();
    return 0;
}
