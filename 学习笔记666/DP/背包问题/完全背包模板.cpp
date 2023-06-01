#include<bits/stdc++.h>

#define ll long long
//#define lb long double
#define run(i, a, b) for(int i = a; i <= b; i ++)
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

const ll N = 1e3 + 7;
int pri[N], tot;
bool vis[N];
ll dp[N]; // 这里用滚动数组优化掉一层数组，背包嘛懂得都懂
int n;

void init() // 亲切的欧拉筛
{
    run(i, 2, n)
    {
        if(!vis[i])
            pri[++ tot] = i;
        run(j, 1, tot)
        {
            if(i * pri[j] > n) break;
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
}

void DP()
{
    run(i, 1, tot) // 枚举每一个物品
        run(v, pri[i], n) // 由于是无限物品，所以得考虑增加完这个物品的贡献，所以得顺着来，在同一层嘛
            dp[v] += dp[v - pri[i]];
}

void solve()
{
    cin >> n;
    init(); // 先预处理出小于最后加数的所有质数（毕竟大于的数没有意义）
    dp[0] = 1; // 细节！0的组成有一种，也就是什么数都没有。但是1的组成不能是一种，因为1不是质数所以1不可能由质数想加获得
    DP(); // 无限背包dp
    cout << dp[n];
}

int main() // https://www.luogu.com.cn/problem/P1832
{
    speed
//    t()
    solve();
    return 0;
}
