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

using namespace std;
const int N = 1e5 + 7;
ll a[N], b[N];

int n, m;
ll ans = -1e9;



void solve()
{
    cin >> n >> m;
    int s, e;
    scanf("%d", &s);
    run(i, 1, m - 1)
    {
        scanf("%d", &e);
        if(s > e)
        {
            a[e] ++;
            a[s] --;
        }
        else
        {
            a[s] ++;
            a[e] --;
        }
        s = e;
    }
    run(i, 1, n - 1)
        b[i] = b[i - 1] + a[i];
    ll ans = 0;
    run(i, 1, n - 1)
    {
        ll x, y, z;
        scanf("%lld%lld%lld", &x, &y, &z);
        if((x - y) * b[i] > z)
            ans += z + y * b[i];
        else
            ans += x * b[i];
    }
    cout << ans << endl;
}


int main() //https://www.luogu.com.cn/problem/P3406
{
    solve();
    return 0;
}
