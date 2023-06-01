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
const int N = 127;
int a[N][N];
int b[N];
int n;
ll ans = -1e9;

void zly()
{
    ll s = 0;
    run(i, 1, n)
    {
        s += b[i];
        ans = max(ans, s);
        if(s < 0)
            s = 0;
    }
}

void yyds()
{
    run(i, 1, n)
    {
        ms(b);
        run(j, i, n)
        {
            run(k, 1, n)
            b[k] += a[j][k];
            zly();
        }
    }
}

void solve()
{
    cin >> n;
    run(i, 1, n)
    run(j, 1, n)
    scanf("%d", &a[i][j]);
    yyds();
    cout << ans << endl;
}


int main() //https://www.luogu.com.cn/problem/P1719
{
    solve();
    return 0;
}
