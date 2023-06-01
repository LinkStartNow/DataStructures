#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
#define ms(i) memset(i, 0, sizeof(i))

using namespace std;
const int N = 25;
int a[N], b[N], c[N], d[N];
int sa, sb, sc, sd;
int ans = 0;
void init()
{
    ms(c), ms(b), ms(a);
}
bool cmp(int a, int b)
{
    return a > b;
}
void dp(int n, int *a, int sum)
{
    int v = sum >> 1;
    int ds[21][1210];
    ms(ds);
    run(i, 1, n)
        run(j, 1, v)
        {
            if(a[i] <= j)
                ds[i][j] = max(ds[i - 1][j], ds[i - 1][j - a[i]] + a[i]);
            else
                ds[i][j] = ds[i - 1][j];
        }
    int t = ds[n][v];
    int ts = sum - t;
    ans += max(t, ts);
}
int main()
{
    int na, nb, nc, nd;
    cin >> na >> nb >> nc >> nd;
    run(i, 1, na)
        scanf("%d", &a[i]), sa += a[i];
    run(i, 1, nb)
        scanf("%d", &b[i]), sb += b[i];
    run(i, 1, nc)
        scanf("%d", &c[i]), sc += c[i];
    run(i, 1, nd)
        scanf("%d", &d[i]), sd += d[i];
    dp(na, a, sa);
    dp(nb, b, sb);
    dp(nc, c, sc);
    dp(nd, d, sd);
    printf("%d\n", ans);
}
