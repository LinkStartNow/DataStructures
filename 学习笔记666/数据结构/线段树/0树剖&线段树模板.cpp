#include<bits/stdc++.h>

#define ll long long
#define lb long double
#define run(i, a, b) for(ll i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);
//char buf[100000], *pa = buf, *pd = buf;
//#define gc pa == pd && (pd = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pd) ? EOF: *pa++

using namespace std;

const ll N = 1e5 + 7;
ll n, q, r, p;
ll a[N];

struct edge
{
    int to, nx;
} e[N << 1];

struct tree
{
    ll s, laz, len;
} t[N << 2];

int siz[N], dep[N], fa[N], son[N], tid[N], rid[N], top[N], cnt;

int tot, head[N];

void add(int u, int v)
{
    e[++ tot] = {v, head[u]};
    head[u] = tot;
}

void dfs1(int s, int f)
{
    fa[s] = f;
    dep[s] = dep[f] + 1;
    siz[s] = 1; // ��������sΪ���ڵ�������Ĵ�С
    for(int i = head[s]; i; i = e[i].nx)
    {
        int to = e[i].to;
        if(to == f) // ����ı�������������ͼ����������ߣ����Բ��������ߣ�����ѭ��
            continue;
        dfs1(to, s);
        siz[s] += siz[to];
        if(siz[son[s]] < siz[to]) // siz�����洢���Ķ��ӣ�Ҳ�����Զ���Ϊ���ڵ���������
            son[s] = to;
    }
}

void dfs2(int s, int f)
{
    top[s] = f; // top�洢s���������Ķ����ڵ�
    tid[s] = ++ cnt; // �����µı�ţ����ʵľ������������ϵĽڵ�����������ģ��������߶����Ż�
    rid[cnt] = s; // ���������˽����߶�����ʱ�򣬲����±�Ŷ�Ӧ��ԭ�ڵ���ʲô
    if(!son[s]) // ֻ��Ҷ�ӽڵ��û���ض��ӣ����ǲ��������±�����
        return;
    dfs2(son[s], f); // �����ض��ӣ�s���ض������������Ķ���Ҳ��s�ڵ����������Ķ���
    for(int i = head[s]; i; i = e[i].nx) // ���������ض�����������������
    {
        int to = e[i].to;
        if(to == son[s] || to == fa[s])
            continue;
        dfs2(to, to); // ����Ӳ��������ϣ�Ҳ������Ϊ��������ڵ�����ֻ������һ���ڵ㣬����Ҳ����������
    }
}

void build(int i, int l, int r) // �߶����Ľ����������еĻ���������û�仯
{
    t[i].len = r - l + 1; // Ϊ��������·ŷ����¼һ�£������鷳�Ŀ��Բ��洢������
    if(l == r)
    {
        t[i].s = a[rid[l]] % p; // ���������ʽ���������ͨ�߶���Ψһ��ͬ�ĵط�����ʵҲû̫��ͬ��ֻ�����˸�����
        // ���ʻ����ҵ���Ӧ��ԭ���ϵĵ㣬Ҳ��rid������ڵ����壬�ñ�΢��������
        t[i].laz = 0;
        return;
    }
    int m(l, r), x(i), y(i);
    build(x, l, m), build(y, m + 1, r);
    t[i].s = (t[x].s + t[y].s) % p;
}

void pd(int i)
{
    int x(i), y(i);
    t[x].laz = (t[x].laz + t[i].laz) % p;
    t[y].laz = (t[y].laz + t[i].laz) % p;
    t[x].s = (t[x].s + t[x].len * t[i].laz % p) % p;
    t[y].s = (t[y].s + t[y].len * t[i].laz % p) % p;
    t[i].laz = 0;
}

void up(int i, int l, int r, int ln, int rn, ll v)
{
    // ������ºͲ�ѯҲ���߶εĻ���������ûʲô��������
    if(l > rn || r < ln)
        return;
    if(l >= ln && r <= rn)
    {
        t[i].s = (t[i].s + v * t[i].len % p) % p;
        t[i].laz = (t[i].laz + v) % p;
        return;
    }
    if(t[i].laz)
        pd(i);
    int m(l, r), x(i), y(i);
    up(x, l, m, ln, rn, v), up(y, m + 1, r, ln, rn, v);
    t[i].s = (t[x].s + t[y].s) % p;
}

ll qq(int i, int l, int r, int ln, int rn)
{
    // ��
    if(l > rn || r < ln)
        return 0;
    if(l >= ln && r <= rn)
        return t[i].s;
    if(t[i].laz)
        pd(i);
    int m(l, r), x(i), y(i);
    return (qq(x, l, m, ln, rn) + qq(y, m + 1, r, ln, rn)) % p;
}

void pathup(int x, int y, ll v)
{
    // ���ʵ�����ʱ��
    // ǰ���ᵽ�ˣ������ϵĽڵ��������ģ���ֻ������������ſ������߶���������
    // ���ǵ�һ����Ҫ�Ȱ��������ڵ�㵽һ��������ȥ
    while(top[x] != top[y]) 
    {
        if(dep[top[x]] < dep[top[y]]) // ��Ϊÿ�ζ��ǽڵ���������������Ľڵ����������������Ĭ��x��Ҫ������
            swap(x, y);
        up(1, 1, n, tid[top[x]], tid[x], v); // ѧ���߶����Ķ�֪�������޸ĵ������䲻�ܴ��������䣬��x�ڵ��top�ڵ�϶���x�ȱ���������ſ϶���xС
        // ����Ҫע�������x��top��x����ε�ֵ��x������top��x���ĸ��ڵ��
        // ��һ���кܶ�����
        // ����Ϊʲô����top��x���ĸ��ڵ㣬��Ϊx�����Ǹ�����ӣ����һֱ��topֻ��ԭ��̤����ѭ�������ϲ��һ��te����mle
        // ��Σ�Ϊʲô���µ�ʱ��ֻ���µ�top��x�����������ĸ��ף����ԭ��ܼ򵥣���Ϊ��Ų�һ���������߶���û�����°��������������������
        x = fa[top[x]];
        // ������Ҳ��Ҳ�����������ʣ�����Ϲ������ܱ�֤���µ�������������ֱ���ϵĵ���
        // �������ʶ��صĽ��㷽ʽʹ�����ʴ���һ���Ӹ��ڵ�ֱͨ������ĳ��Ҷ�ӽڵ㣩���������������ϵ����нڵ㶼���丸�׽ڵ���ض���
        // �����������Ҳ����һ��һ���ع����ߵĹ��̣�������������Ƕ�����������
    }
    // �����������ͬһ��������ֱ�Ӷ�����������и��¼���
    if(dep[x] > dep[y]) // ��ĵ���ſ϶��Ǵ������Ϊ�˸��·���Ĭ����x������
        swap(x, y);
    up(1, 1, n, tid[x], tid[y], v);
    // ���������С����Ѿ������ˣ���ʵ��������ͬһ��������ʱ��������Ǹ������ԭ�������������������ȹ�����
    // �ֶ����һ��������������ȵķ����������ģ�
    // ��ʵ�����ֱ��·�����Ǵ�ĳ���㵽�����������������Ȼ�����Ƶ���һ���ڵ㣨����Ҫ�����϶�Ҫ��һ������ý�ŵģ�
}

ll pathqq(int x, int y)
{
    // ���ĵĿ������ο�·������
    ll res = 0;
    while(top[x] != top[y])
    {
        if(dep[top[x]] < dep[top[y]])
            swap(x, y);
        res = (qq(1, 1, n, tid[top[x]], tid[x]) + res) % p;
        x = fa[top[x]];
    }
    if(dep[x] > dep[y])
        swap(x, y);
    return (qq(1, 1, n, tid[x], tid[y]) + res) % p;
}

void solve()
{
    cin >> n >> q >> r >> p;
    // ���룬������ʽǰ���ǽ�ͼ��ûɶ��˵��
    run(i, 1, n) cin >> a[i];
    run(i, 1, n - 1)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    // dfs����֮ǰ���ͼ���������ϵĸ��ӹ�ϵ
    dfs1(r, r), dfs2(r, r);
    // �����ϴ������±��Ϊ���������߶�����ά�����������ֵ
    build(1, 1, n);
    while(q --)
    {
        int k;
        cin >> k;
        if(k == 1)
        {
            ll x, y, z;
            cin >> x >> y >> z;
            pathup(x, y, z); // ֱ��·���ϵĸ�����Ը��ڵ�Ҫ���ڵ��
        }
        else if(k == 2)
        {
            ll x, y;
            cin >> x >> y;
            cout << pathqq(x, y) << '\n';
        }
        else if(k == 3)
        {
            ll x, z;
            cin >> x >> z;
            // ���ڵ����Ըø�Ϊ�����е����нڵ㶼�������ģ�ֻ��������ǴӸ��ڵ㿪ʼ�������ض����еĽڵ�Ȼ���ٱ���������еĽڵ�
            // �����ĳ���ڵ�Ϊ���ڵ��ܹ�Ͻ�ķ�Χ��������ı��+����Ĵ�С-1
            up(1, 1, n, tid[x], tid[x] + siz[x] - 1, z);
        }
        else
        {
            ll x;
            cin >> x; // ������k=3�����һëһ����ûɶ��˵��
            cout << qq(1, 1, n, tid[x], tid[x] + siz[x] - 1) << '\n';
        }
    }
}

int main() // https://www.luogu.com.cn/problem/P3384
{
    speed
//    t()
    solve();
    return 0;
}