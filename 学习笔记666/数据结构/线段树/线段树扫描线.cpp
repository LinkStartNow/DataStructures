#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
using namespace std;
int n, w, h;
const int N = 2e4 + 5;
struct Star
{
    long long l, r, h, b;
    bool operator < (const Star &s) const
    {
        if(h == s.h)
            return b < s.b; // 提早删除避免卡边框上的星星影响答案
        return h < s.h;
    }
} p[N << 1];
long long X[N << 1];
long long ad[N << 2], ma[N << 2];
inline void pd(int i)
{
    int x(i), y(i);
    ad[x] += ad[i], ad[y] += ad[i];
    ma[x] += ad[i], ma[y] += ad[i];
    ad[i] = 0;
}
inline void pu(int i)
{
    int x(i), y(i);
    ma[i] = max(ma[x], ma[y]);
}
void update(int l, int r, int i, int ln, int rn, int v)
{
    if(l >= rn || r <= ln)
        return;
    if(l <= ln && r >= rn)
    {
        ad[i] += v;
        ma[i] += v;
        return;
    }
    pd(i);
    int m(ln, rn), x(i), y(i);
    update(l, r, x, ln, m, v);
    update(l, r, y, m, rn, v);
    pu(i);
}
int main()
{
    while(scanf("%d%d%d", &n, &w, &h)!=EOF)
    {
        int a, b, c;
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d%d%d", &a, &b, &c);
            p[i].l = a;
            p[i].r = (long long)a + w;
            p[i].h = b;
            p[i].b = c;
            p[i + n].l = a;
            p[i + n].r = (long long)a + w;
            p[i + n].h = (long long)b + h;
            p[i + n].b = - c;
            X[i] = a;
            X[i + n] = (long long)a + w;
        }
        sort(p + 1, p + 1 + 2 * n);
        sort(X + 1, X + 1 + 2 * n);
        int m = unique(X + 1, X + 1 + 2 * n) - X; // m为去重后的一个数的下标
        for(int i = 1; i <= 2 * n; i ++)
        {
            p[i].l = lower_bound(X + 1, X + m, p[i].l) - X;
            p[i].r = lower_bound(X + 1, X + m, p[i].r) - X;
        }
        long long ans = 0;
        for(int i = 1; i <= 2 * n; i ++)
        {
            update(p[i].l, p[i].r, 1, 1, m, p[i].b);
            ans = max(ans, ma[1]);
        }
        printf("%lld\n", ans);
    }
}
