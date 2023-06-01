#include<bits/stdc++.h>
using namespace std;
const int N = 5000;
int n, m, i, j;
long long t[N][N], ti[N][N], tj[N][N], tij[N][N];
inline int lowbit(int x)
{
    return x & (- x);
}
void add(int x, int y, int v)
{
    for(i = x; i <= n; i += lowbit(i))
        for(j = y; j <= m; j += lowbit(j))
        {
            t[i][j] += (long long)v;
            ti[i][j] += (long long)v * x;
            tj[i][j] += (long long)v * y;
            tij[i][j] += (long long)v * x * y;
        }
}
void adds(int x, int y, int xx, int yy, int v)
{
    add(x, y, v);
    add(x, yy + 1, -v);
    add(xx + 1, y, -v);
    add(xx + 1, yy + 1, v);
}


long long getsum(int x, int y)
{
    long long res = 0;
    for(i = x; i; i -= lowbit(i))
        for(j = y; j; j -= lowbit(j))
            res += t[i][j] * (x + 1) * (y + 1) - ti[i][j] * (y + 1) - tj[i][j] * (x + 1) + tij[i][j];
    return res;
}
long long getsums(int x, int y, int xx, int yy)
{
    return getsum(xx, yy) - getsum(x - 1, yy) - getsum(xx, y - 1) + getsum(x - 1, y - 1);
}
int main()
{
    scanf("%d%d", &n, &m);
    int k, a, b, c, d, v;
    while(scanf("%d", &k)!=EOF)
    {
        if(k == 1)
        {
            scanf("%d%d%d%d%d", &a, &b, &c, &d, &v);
            adds(a, b, c, d, v);
        }
        else
        {
            scanf("%d%d", &a, &b);
            printf("%lld\n", getsums(a, b, a, b));
        }
    }
}
