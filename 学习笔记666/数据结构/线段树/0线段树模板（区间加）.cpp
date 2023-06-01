#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
long long a[N];
struct tree
{
    int l, r;
    long long s, add;
} t[4 * N];
void build(int l, int r, int root)
{
    t[root].l = l;
    t[root].r = r;
    t[root].add = 0;
    t[root].s = 0;
    if(l == r)
    {
        t[root].s = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, root << 1);
    build(m + 1, r, root << 1 | 1);
    t[root].s = t[root << 1].s + t[root << 1 | 1].s;
}
void pd(int r)
{
    t[r << 1].s += t[r].add * (t[r << 1].r - t[r << 1].l + 1);
    t[r << 1].add += t[r].add;
    t[r << 1 | 1].s += t[r].add * (t[r << 1 | 1].r - t[r << 1 | 1].l + 1);
    t[r << 1 | 1].add += t[r].add;
    t[r].add = 0;
}
void add(int l, int r, long long v, int root)
{
    if(t[root].l > r || t[root].r < l)
        return;
    if(t[root].l >= l && t[root].r <= r)
    {
        t[root].add += v;
        t[root].s += v * (t[root].r - t[root].l + 1);
        return;
    }
    pd(root);
    int m = (t[root].l + t[root].r) >> 1;
    add(l, r, v, root << 1);
    add(l, r, v, root << 1 | 1);
    t[root].s = t[root << 1].s + t[root << 1 | 1].s;
}
long long q(int l, int r, int root)
{
    if(t[root].l > r || t[root].r < l)
        return 0;
    if(t[root].l >= l && t[root].r <= r)
    {
        return t[root].s;
    }
    pd(root);
    int x = root << 1, y = root << 1 | 1;
    return q(l, r, x) + q(l, r, y);
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        scanf("%lld", &a[i]);
    }
    build(1, n, 1);
    while(m --)
    {
        int k;
        scanf("%d", &k);
        if(k == 1)
        {
            int l, r;
            long long v;
            scanf("%d%d%lld", &l, &r, &v);
            add(l, r, v, 1);
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", q(l, r, 1));
        }
    }
}
