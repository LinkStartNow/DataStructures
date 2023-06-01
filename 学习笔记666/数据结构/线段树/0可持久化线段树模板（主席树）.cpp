#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct Tree
{
    int l, r, v;
} t[N * 50];
int rt[N], tot;
int update(int o, int l, int r, int loc, int v)
{
    int oo = ++ tot;
    t[oo] = t[o];
    if(l == r)
    {
        t[oo].v = v;
        return oo;
    }
    int m = (l + r) >> 1;
    if(loc <= m)
        t[oo].l = update(t[oo].l, l, m, loc, v);
    else
        t[oo].r = update(t[oo].r, m + 1, r, loc, v);
    t[oo].v = t[t[oo].l].v + t[t[oo].r].v;
    return oo;
}
int Q(int o, int l, int r, int loc)
{
    if(l == r)
        return t[o].v;
    int m = (l + r) >> 1;
    if(loc <= m)
        return Q(t[o].l, l, m, loc);
    else
        return Q(t[o].r, m + 1, r, loc);
}
int main()
{
    int n, m, p;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        scanf("%d", &p);
        rt[0] = update(rt[0], 1, n, i, p);
    }
    for(int i = 1; i <= m; i ++)
    {
        int o, k, loc;
        scanf("%d%d%d", &o, &k, &loc);
        if(k == 1)
        {
            int v;
            scanf("%d", &v);
            rt[i] = update(rt[o], 1, n, loc, v);
        }
        else
        {
            rt[i] = rt[o];
            printf("%d\n", Q(rt[i], 1, n, loc));
        }
    }
}
