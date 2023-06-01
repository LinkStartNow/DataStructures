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
#define speed ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

const ll N = 1e5 + 7;
int n, k;
int key[N]; // 存储题目中的key节点
int ffa[N << 2], ffb[N << 2]; // 建立线段树维护连续区间的最近祖宗
int va[N], vb[N]; // 存储各个点的值
int da[N], db[N]; // 存储各个点的深度
int fa[N][60], fb[N][60]; // 存储第i个节点的向上第2^j个父亲
vector<int> ea[N], eb[N]; // 邻接表存图

void dfs(vector<int> e[], int u, int d[], int f[][60])
{
    for(auto v : e[u])
    {
        d[v] = d[u] + 1; // 初始化每个节点的d数组
        f[v][0] = u;
        run(i, 1, 50) // 初始化每个节点的f数组
        {
            if(d[v] - (1 << i) < 1)
                break;
            f[v][i] = f[f[v][i - 1]][i - 1];
        }
        dfs(e, v, d, f);
    }
}

int lca(int a, int b, int d[], int f[][60]) // 倍增求lca
{
    if(d[b] < d[a])
        swap(a, b);
    int t = d[b];
    rep(i, 30, 0) // 使a与b的某个祖宗处于同一深度
    {
        if(t == d[a])
            break;
        if(t - (1 << i) < d[a])
            continue;
        t -= (1 << i);
        b = f[b][i];
    }

    if(a == b) // a是b的祖宗直接返回a
        return a;
    rep(i, 30, 0) // 求公共祖先的儿子
    {
        if(t - (1 << i) < 1)
            continue;
        if(f[a][i] == f[b][i])
            continue;
        a = f[a][i], b = f[b][i];
        t -= (1 << i);
    }
    return f[a][0];
}

void build(int i, int l, int r, int ff[], int d[], int f[][60])
{
    if(l == r)
    {
        ff[i] = key[l];
        return;
    }
    int x(i), y(i), m(l, r);
    build(x, l, m, ff, d, f), build(y, m + 1, r, ff, d, f);
    ff[i] = lca(ff[x], ff[y], d, f);
}

int qq(int i, int l, int r, int ff[], int d[], int f[][60], int ln, int rn)
{
    if(l > rn || r < ln) // 范围无效则返回一个不可能的祖先
        return 0;
    if(l >= ln && r <= rn)
        return ff[i];
    int x(i), y(i), m(l, r);
    int aa = qq(x, l, m, ff, d, f, ln, rn), bb = qq(y, m + 1, r, ff, d, f, ln, rn);
    if(!aa || ! bb)
        return aa == 0 ? bb : aa; // 至少有一边的范围是有效的
    return lca(aa, bb, d, f);
}

int qs(int l, int r, bool f)
{
    if(l > r)
        return 0;
    if(!f)
        return qq(1, 1, k, ffa, da, fa, l, r);
    return qq(1, 1, k, ffb, db, fb, l, r);
}

void solve()
{
    cin >> n >> k;
    run(i, 1, k) cin >> key[i];
    run(i, 1, n) cin >> va[i];
    run(i, 2, n)
    {
        int u;
        cin >> u;
        ea[u].push_back(i);
    }
    run(i, 1, n) cin >> vb[i];
    run(i, 2, n)
    {
        int u;
        cin >> u;
        eb[u].push_back(i);
    }
    da[1] = db[1] = 1;
    run(i, 1, 50)
        fa[1][i] = fb[1][i] = 1;
    dfs(ea, 1, da, fa), dfs(eb, 1, db, fb);
    build(1, 1, k, ffa, da, fa), build(1, 1, k, ffb, db, fb);
    int ans = 0;
    run(i, 1, k)
    {
        int a = qs(1, i - 1, 0), b = qs(i + 1, k, 0);
        int aa;
        if(!a || !b)
            aa = a == 0 ? b : a;
        else
            aa = lca(a, b, da, fa);
        a = qs(1, i - 1, 1), b = qs(i + 1, k, 1);
        int bb;
        if(!a || !b)
            bb = a == 0 ? b : a;
        else
            bb = lca(a, b, db, fb);
        if(va[aa] > vb[bb])
            ans ++;
    }
    cout << ans;
}

int main() // https://ac.nowcoder.com/acm/contest/33188/A
{
    speed
//    t()
    solve();
    return 0;
}
