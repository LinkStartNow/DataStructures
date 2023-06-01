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
const int N = 5e4 + 7;
int a[N], t[N][50], ts[N][50];
int n, m;

void pre()
{
    int s = log(n) / log(2) + 1;
    run(i, 1, n)
        t[i][0] = ts[i][0] = a[i];
    int k = 2;
    run(i, 1, s)
    {
        int e = n - k + 1;
        if(e < 1)
            return;
        run(j, 1, e)
        {
            t[j][i] = max(t[j][i - 1], t[j + k / 2][i - 1]);
            ts[j][i] = min(ts[j][i - 1], ts[j + k / 2][i - 1]);
        }
        k <<= 1;
    }
}

int gt(int l, int r)
{
    int s = log(r - l + 1) / log(2);
    int ssr = 1 << s;
    int ma = max(t[l][s], t[r - ssr + 1][s]);
    int mi = min(ts[l][s], ts[r - ssr + 1][s]);
    return ma - mi;
}

void solve()
{
    cin >> n >> m;
    run(i, 1, n)
        scanf("%d", &a[i]);
    pre();
    while(m --)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", gt(l, r));
    }
}

int main() //https://www.luogu.com.cn/problem/P2880
{
    solve();
    return 0;
}
