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
int a[N];
int n, m;
struct yyds
{
    int ma, mi;
} t[N << 2];

void build(int l, int r, int i)
{
    t[i].ma = -1e9;
    t[i].mi = 1e9;
    if(l == r)
    {
        t[i].ma = t[i].mi = a[l];
        return;
    }
    int m(l, r), x(i), y(i);
    build(l, m, x), build(m + 1, r, y);
    t[i].ma = max(t[x].ma, t[y].ma);
    t[i].mi = min(t[x].mi, t[y].mi);
}

int querya(int l, int r, int i, int ln, int rn)
{
    if(l > rn || r < ln)
        return -1e9;
    if(l >= ln && r <= rn)
        return t[i].ma;
    int m(l, r), x(i), y(i);
    return max(querya(l, m, x, ln, rn), querya(m + 1, r, y, ln, rn));
}

int queryi(int l, int r, int i, int ln, int rn)
{
    if(l > rn || r < ln)
        return 1e9;
    if(l >= ln && r <= rn)
        return t[i].mi;
    int m(l, r), x(i), y(i);
    return min(queryi(l, m, x, ln, rn), queryi(m + 1, r, y, ln, rn));
}

void solve()
{
    cin >> n >> m;
    run(i, 1, n)
        scanf("%d", &a[i]);
    build(1, n, 1);
    while(m --)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", querya(1, n, 1, l, r) - queryi(1, n, 1, l, r));
    }
}

int main() //https://www.luogu.com.cn/problem/P2880
{
    solve();
    return 0;
}
