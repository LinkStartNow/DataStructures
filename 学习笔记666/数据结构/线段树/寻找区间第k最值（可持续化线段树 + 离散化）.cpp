#include<bits/stdc++.h>
#define run(i, a, b) for(long long i = a; i <= b; i ++)
#define ll long long
#define m(l, r) mid = (l + r) >> 1
using namespace std;
const int N = 2e5 + 5;
struct Tree
{
    int l, r, s;
} t[50 * N];
struct A
{
    int v, id;
} a[N];
int b[N], rt[N], tot, n, m, num;
void discrete()
{
    sort(b + 1, b + 1 + n);
    num = unique(b + 1, b + 1 + n) - b - 1;
    run(i, 1, n)
        a[i].id = lower_bound(b + 1, b + 1 + num, a[i].v) - b;
}
int update(int o, int l, int r, int loc)
{
    int oo = ++ tot;
    t[oo] = t[o];
    if(l == r)
    {
        t[oo].s ++;
        return oo;
    }
    int m(l, r);
    if(loc <= mid)
        t[oo].l = update(t[oo].l, l, mid, loc);
    else
        t[oo].r = update(t[oo].r, mid + 1, r, loc);
    t[oo].s = t[t[oo].l].s + t[t[oo].r].s;
    return oo;
}
void build()
{
    run(i, 1, n)
        rt[i] = update(rt[i - 1], 1, num, a[i].id);
}
int query(int o, int oo, int l, int r, int k)
{
    int tp = t[t[oo].l].s - t[t[o].l].s;
    if(l == r)
        return b[l];
    int m(l, r);
    if(tp >= k)
        return query(t[o].l, t[oo].l, l, mid, k);
    else
        return query(t[o].r, t[oo].r, mid + 1, r, k - tp);
}
int main()
{
    cin >> n >> m;
    run(i, 1, n)
    {
        scanf("%d", &a[i].v);
        b[i] = a[i].v;
    }
    discrete();
    build();
    run(i, 1, m)
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", query(rt[l - 1], rt[r], 1, num, k));
    }
}
