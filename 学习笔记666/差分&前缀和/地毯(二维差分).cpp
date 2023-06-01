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

using namespace std;
const int N = 1e3 + 7;
int a[N][N], b[N][N];
int n, m;

void into(int x1, int y1, int x2, int y2)
{
    a[x1][y1] ++;
    a[x2 + 1][y1] --;
    a[x1][y2 + 1] --;
    a[x2 + 1][y2 + 1] ++;
//    run(i, 1, n)
//    {
//        run(j, 1, n - 1)
//            printf("%d ", a[i][j]);
//        printf("%d\n", a[i][n]);
//    }
//    puts("");
//    puts("");
}

void solve()
{
    cin >> n >> m;
    int x, y, z, w;
    while(m --)
        scanf("%d%d%d%d", &x, &y, &z, &w), into(x, y, z, w);

    run(i, 1, n)
        run(j, 1, n)
            b[i][j] = a[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];

    run(i, 1, n)
    {
        run(j, 1, n - 1)
            printf("%d ", b[i][j]);
        printf("%d\n", b[i][n]);
    }

}
int main() //https://www.luogu.com.cn/problem/P3397
{
    solve();
    return 0;
}
