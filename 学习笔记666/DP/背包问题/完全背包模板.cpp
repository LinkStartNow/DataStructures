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
ll dp[N]; // �����ù��������Ż���һ�����飬�����ﶮ�ö���
int n;

void init() // ���е�ŷ��ɸ
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
    run(i, 1, tot) // ö��ÿһ����Ʒ
        run(v, pri[i], n) // ������������Ʒ�����Եÿ��������������Ʒ�Ĺ��ף����Ե�˳��������ͬһ����
            dp[v] += dp[v - pri[i]];
}

void solve()
{
    cin >> n;
    init(); // ��Ԥ�����С���������������������Ͼ����ڵ���û�����壩
    dp[0] = 1; // ϸ�ڣ�0�������һ�֣�Ҳ����ʲô����û�С�����1����ɲ�����һ�֣���Ϊ1������������1��������������ӻ��
    DP(); // ���ޱ���dp
    cout << dp[n];
}

int main() // https://www.luogu.com.cn/problem/P1832
{
    speed
//    t()
    solve();
    return 0;
}
