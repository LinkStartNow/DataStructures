#include<bits/stdc++.h>

#define ll long long
//#define lb long double
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

const ll N = 1e8 + 7;
int pri[N], tot;
bool vis[N];
int n, q;

void init()
{
    run(i, 2, n)
    {
        if(!vis[i]) // 经过前面数的筛选还没被处理掉的数就是质数
            pri[++ tot] = i;
        run(j, 1, tot) // 核心是把一个数拆成它的最小质因子与不等于自己的最大因子的乘积进行筛选
        {
            if(i * pri[j] > n) break; // 大于最大数据范围停止
            vis[i * pri[j]] = 1; // 把乘积得出来的数筛掉
            if(i % pri[j] == 0) break; // 精髓部分，因为i的最小质因子是pri【j】，所以在此之后的pri【k】*i的最小质因子都是pri【j】会重复筛选不如直接退出
        }
    }
}

void solve()
{
    cin >> n >> q;
    init();
    while(q --)
    {
        int t;
        cin >> t;
        cout << pri[t] << '\n';
    }
}

int main() // https://www.luogu.com.cn/problem/P3383
{
    speed
//    t()
    solve();
    return 0;
}
