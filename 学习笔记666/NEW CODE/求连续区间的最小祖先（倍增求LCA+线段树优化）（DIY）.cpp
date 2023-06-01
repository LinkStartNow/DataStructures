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
int key[N]; // �洢��Ŀ�е�key�ڵ�
int ffa[N << 2], ffb[N << 2]; // �����߶���ά������������������
int va[N], vb[N]; // �洢�������ֵ
int da[N], db[N]; // �洢����������
int fa[N][60], fb[N][60]; // �洢��i���ڵ�����ϵ�2^j������
vector<int> ea[N], eb[N]; // �ڽӱ��ͼ

void dfs(vector<int> e[], int u, int d[], int f[][60])
{
    for(auto v : e[u])
    {
        d[v] = d[u] + 1; // ��ʼ��ÿ���ڵ��d����
        f[v][0] = u;
        run(i, 1, 50) // ��ʼ��ÿ���ڵ��f����
        {
            if(d[v] - (1 << i) < 1)
                break;
            f[v][i] = f[f[v][i - 1]][i - 1];
        }
        dfs(e, v, d, f);
    }
}

int lca(int a, int b, int d[], int f[][60]) // ������lca
{
    if(d[b] < d[a])
        swap(a, b);
    int t = d[b];
    rep(i, 30, 0) // ʹa��b��ĳ�����ڴ���ͬһ���
    {
        if(t == d[a])
            break;
        if(t - (1 << i) < d[a])
            continue;
        t -= (1 << i);
        b = f[b][i];
    }

    if(a == b) // a��b������ֱ�ӷ���a
        return a;
    rep(i, 30, 0) // �󹫹����ȵĶ���
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
    if(l > rn || r < ln) // ��Χ��Ч�򷵻�һ�������ܵ�����
        return 0;
    if(l >= ln && r <= rn)
        return ff[i];
    int x(i), y(i), m(l, r);
    int aa = qq(x, l, m, ff, d, f, ln, rn), bb = qq(y, m + 1, r, ff, d, f, ln, rn);
    if(!aa || ! bb)
        return aa == 0 ? bb : aa; // ������һ�ߵķ�Χ����Ч��
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
