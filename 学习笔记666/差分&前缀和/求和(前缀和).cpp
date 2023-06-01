#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(ll i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>

using namespace std;
const int N = 1e5 + 7, p = 10007;
struct yyds
{
    ll id, val;
} a[N];
vector<yyds> c[N << 1];
void solve()
{
    int n, m;
    cin >> n >> m;
    run(i, 1, n)
        scanf("%lld", &a[i].val), a[i].id = i;
    run(i, 1, n)
        {
            int t;
            scanf("%d", &t);
            if(i & 1)
                c[(t << 1) - 1].push_back(a[i]);
            else
                c[t << 1].push_back(a[i]);
        }
    ll ans = 0;
    run(i, 1, n)
    {
        int l = c[i].size();
        if(l > 1)
        {
            ll sx = 0, sy = 0, sz = 0;
            for(auto &v: c[i])
            {
                sx = (sx + v.id) % p;
                sy = (sy + v.val) % p;
                sz = (sz + v.id * v.val % p) % p;
            }
            ans = (ans + sx * sy % p + sz * (l - 2) % p) % p;
        }
    }
    cout << ans << endl;
}
int main() //https://www.luogu.com.cn/problem/P2671
{
    solve();
    return 0;
}
