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
const int N = 1e3 + 7;
ll a[N][N];
int n, m;



void solve()
{
    cin >> n >> m;
    run(i, 1, m)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        run(j, x1, x2)
            a[j][y1] ++, a[j][y2 + 1] --;
    }
    run(i, 1, n)
    {
        ll s = 0;
        run(j, 1, n - 1)
            printf("%d ", s + a[i][j]), s += a[i][j];
        printf("%d\n", s + a[i][n]);
    }
}


int main() //https://www.luogu.com.cn/problem/P3397
{
    solve();
    return 0;
}
