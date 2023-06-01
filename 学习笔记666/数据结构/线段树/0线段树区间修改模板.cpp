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

const int N = 1e5 + 5;

int n, q;
long long a[N];
bool s[N];

struct tree
{
    long long s, add, ssr;
} t[4 * N];

void build(int l, int r, int root)
{
    t[root].add = 0;
    t[root].s = 0;
    if(l == r)
    {
        t[root].s = a[l];
        t[root].ssr = s[l];
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, root << 1);
    build(m + 1, r, root << 1 | 1);
    t[root].s = t[root << 1].s + t[root << 1 | 1].s;
    t[root].ssr = t[root << 1].ssr + t[root << 1 | 1].ssr;
}

void pd(int r)
{
    int x(r), y(r);
    t[x].s += t[r].add * t[x].ssr;
    t[x].add += t[r].add;
    t[y].s += t[r].add * t[y].ssr;
    t[y].add += t[r].add;
    t[r].add = 0;
}

void add(int l, int r, long long v, int ln, int rn, int root)
{
    if(rn < l || ln > r)
        return;
    if(ln <= l && rn >= r)
    {
        t[root].add += v;
        t[root].s += v * t[root].ssr;
        return;
    }
    if(t[root].add)
        pd(root);
    int m(l, r), x(root), y(root);
    add(l, m, v, ln, rn, x), add(m + 1, r, v, ln, rn, y);
    t[root].s = t[x].s + t[y].s;
}

long long query(int l, int r, int ln, int rn, int root)
{
    if(rn < l || ln > r)
        return 0;
    if(ln <= l && rn >= r)
        return t[root].s;
    if(t[root].add)
        pd(root);
    int m(l, r), x(root), y(root);
    return query(l, m, ln, rn, x) + query(m + 1, r, ln, rn, y);
}

void cha(int l, int r, int fx, bool f, int root)
{
    if(l == r)
    {
        t[root].ssr = f;
        return;
    }
    if(t[root].add)
        pd(root);
    int m(l, r), x(root), y(root);
    if(fx <= m)
        cha(l, m, fx, f, x);
    else
        cha(m + 1, r, fx, f, y);
    t[root].ssr = t[x].ssr + t[y].ssr;
}

int main() //https://vjudge.net/contest/497054#problem/L
{
    cin >> n >> q;
    for(int i = 1; i <= n; i ++)
        scanf("%lld", &a[i]);
    run(i, 1, n)
        scanf("%d", &s[i]);
    build(1, n, 1);
    while(q --)
    {
        int k;
        scanf("%d", &k);
        if(k == 1)
        {
            int x;
            scanf("%d", &x);
            cha(1, n, x, 0, 1);
        }
        else if(k == 2)
        {
            int x;
            scanf("%d", &x);
            cha(1, n, x, 1, 1);
        }
        else if(k == 3)
        {
            int l, r;
            ll x;
            scanf("%d%d%lld", &l, &r, &x);
            add(1, n, x, l, r, 1);
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(1, n, l, r, 1));
        }
    }
}
