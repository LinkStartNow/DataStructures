#include<bits/stdc++.h>

//#define int __int128
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
#define ms(i) memset(i, 0, sizeof(i))
#define ll long long

using namespace std;

const int N = 55;
const double jin = 1e-2;
double a[N][N];
int yyds(int n, int m)
{
    int r, c;
    for(r = 1, c = 1; r <= n && c <= m; c ++)
    {
        int p = r;
        run(i, r + 1, n)
            if(fabs(a[i][c]) > fabs(a[p][c]))
                p = i;
        run(i, c, m + 1)
            swap(a[p][i], a[r][i]);
        if(fabs(a[r][c]) < jin)
            continue;
        rep(i, m + 1, c)
            a[r][i] /= a[r][c];
        run(i, 1, n)
        {
            if(i == r)
                continue;
            rep(j, m + 1, c)
                a[i][j] -= a[r][j] * a[i][c];
        }
        r ++;
    }
    r --;
    if(r < m)
    {
        run(i, r + 1, n)
            if(fabs(a[i][m + 1]) > jin)
                return -1;
        return m - r;
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    run(i, 1, n)
        run(j, 1, n + 1)
            scanf("%lf", &a[i][j]);
    int flag = yyds(n, n);
    if(flag == -1)
        puts("-1");
    else if(flag)
        puts("0");
    else
        run(i, 1, n)
            printf("x%d=%.2f\n", i, a[i][n + 1]);
}
