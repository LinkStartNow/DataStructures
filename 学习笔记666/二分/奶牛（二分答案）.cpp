#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>

using namespace std;
const int N = 1e5 + 7;
ll a[N];
int n, c;

bool check(ll x)
{
    ll pos = 1;
    ll s = 1;
    run(i, 1, n)
    {
        if(a[i] - a[pos] >= x)
        {
            pos = i;
            s ++;
        }
        if(s == c)
            return 1;
    }
    if(s == c)
        return 1;
    else
        return 0;
}
void solve()
{
    cin >> n >> c;
    run(i, 1, n)
        scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n);
    ll l = 1, r = a[n] - a[1];
    while(r >= l)
    {
        ll m = (l + r) >> 1;
        if(check(m))
            l = m + 1;
        else
            r = m - 1;
    }
    printf("%lld\n", r);
}
int main()
{
    solve();
    return 0; //https://www.luogu.com.cn/problem/P1824
}
