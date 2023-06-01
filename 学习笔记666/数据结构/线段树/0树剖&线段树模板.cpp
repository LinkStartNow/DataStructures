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
    siz[s] = 1; // 储存下以s为根节点的子树的大小
    for(int i = head[s]; i; i = e[i].nx)
    {
        int to = e[i].to;
        if(to == f) // 经典的遍历，由于无向图存的是两条边，所以不能往回走，会死循环
            continue;
        dfs1(to, s);
        siz[s] += siz[to];
        if(siz[son[s]] < siz[to]) // siz用来存储最大的儿子，也就是以儿子为根节点的最大子树
            son[s] = to;
    }
}

void dfs2(int s, int f)
{
    top[s] = f; // top存储s所在重链的顶部节点
    tid[s] = ++ cnt; // 创建新的编号，树剖的精髓在于重链上的节点序号是连续的，可以用线段树优化
    rid[cnt] = s; // 仅仅用在了建立线段树的时候，查找新编号对应的原节点是什么
    if(!son[s]) // 只有叶子节点才没有重儿子，于是不用再往下遍历了
        return;
    dfs2(son[s], f); // 遍历重儿子，s的重儿子所在重链的顶部也是s节点所在重链的顶部
    for(int i = head[s]; i; i = e[i].nx) // 遍历除了重儿子以外的其他轻儿子
    {
        int to = e[i].to;
        if(to == son[s] || to == fa[s])
            continue;
        dfs2(to, to); // 轻儿子不在重链上，也可以认为轻儿子所在的重链只有自身一个节点，顶部也就是自身了
    }
}

void build(int i, int l, int r) // 线段树的建立，基础中的基础，几乎没变化
{
    t[i].len = r - l + 1; // 为了懒标记下放方便记录一下，不嫌麻烦的可以不存储哈哈哈
    if(l == r)
    {
        t[i].s = a[rid[l]] % p; // 这里是树剖建数中与普通线段树唯一不同的地方，其实也没太大不同，只是绕了个弯子
        // 本质还是找到对应的原数上的点，也是rid数组存在的意义，好卑微啊哈哈哈
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
    // 这个更新和查询也是线段的基本操作，没什么技术含量
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
    // 略
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
    // 树剖的魅力时刻
    // 前面提到了，重链上的节点是连续的，而只有连续的区间才可以用线段树来操作
    // 于是第一部是要先把这两个节点搞到一条重链上去
    while(top[x] != top[y]) 
    {
        if(dep[top[x]] < dep[top[y]]) // 因为每次都是节点重链顶部在下面的节点往上跳，方便起见默认x需要往上跳
            swap(x, y);
        up(1, 1, n, tid[top[x]], tid[x], v); // 学过线段树的都知道区间修改的左区间不能大于右区间，而x节点的top节点肯定比x先被遍历故序号肯定比x小
        // 这里要注意更新完x到top【x】这段的值后x是跳到top【x】的父节点的
        // 你一定有很多疑问
        // 首先为什么跳到top【x】的父节点，因为x可能是个轻儿子，如果一直跳top只会原地踏步死循环，最后喜提一个te或者mle
        // 其次，为什么更新的时候只更新到top【x】而不是它的父亲，这个原因很简单，因为序号不一定连续，线段树没法更新啊哈哈哈，臣妾做不到啊
        x = fa[top[x]];
        // 这里你也许也有这样的疑问：这样瞎跳真的能保证更新的是在两点的最近直线上的点吗
        // 由于树剖独特的建点方式使得树剖存在一条从根节点直通地狱（某个叶子节点）的重链，这条链上的所有节点都是其父亲节点的重儿子
        // 这里的向上跳也就是一步一步回归主线的过程，最差的情况不过是都跳回主线了
    }
    // 最后这俩点在同一重链上了直接对这段重链进行更新即可
    if(dep[x] > dep[y]) // 深的点序号肯定是大的所以为了更新方便默认让x在上面
        swap(x, y);
    up(1, 1, n, tid[x], tid[y], v);
    // 这里聪明的小伙伴已经发现了，其实两个点在同一条重链上时在上面的那个点就是原先两个点的最近公共祖先哈哈哈
    // 又多会了一种求最近公共祖先的方法开不开心！
    // 其实两点的直接路径就是从某个点到他俩的最近公共祖先然后再绕到另一个节点（他俩要相连肯定要有一个点做媒婆的）
}

ll pathqq(int x, int y)
{
    // 无聊的拷贝，参考路径更新
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
    // 输入，并用链式前向星建图，没啥好说的
    run(i, 1, n) cin >> a[i];
    run(i, 1, n - 1)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    // dfs遍历之前存的图来理清树上的父子关系
    dfs1(r, r), dfs2(r, r);
    // 以树上创立的新编号为基础建立线段树，维护连续区间的值
    build(1, 1, n);
    while(q --)
    {
        int k;
        cin >> k;
        if(k == 1)
        {
            ll x, y, z;
            cin >> x >> y >> z;
            pathup(x, y, z); // 直接路径上的更新相对跟节点要难亿点点
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
            // 根节点与以该跟为子树中的所有节点都是连续的，只不过序号是从根节点开始，经过重儿子中的节点然后再遍历轻儿子中的节点
            // 因此以某个节点为根节点能管辖的范围就是自身的编号+自身的大小-1
            up(1, 1, n, tid[x], tid[x] + siz[x] - 1, z);
        }
        else
        {
            ll x;
            cin >> x; // 这里与k=3的情况一毛一样，没啥好说的
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