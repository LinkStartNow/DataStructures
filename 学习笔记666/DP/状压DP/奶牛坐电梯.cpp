#include<bits/stdc++.h>

#define ll long long
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

using namespace std;

const ll N = 2e3 + 7;
// ÿ��״̬��һ������������ʾ����iλΪ1��ʾ��iͷ��ţ�ڵ����У�Ϊ0���ʾ����
int dp[1 << 18]; // i״̬ʱ���ٵĵ��ݴ���
int g[1 << 18]; // i״̬ʱ���һ�����ݵ�ʣ��ռ�
int a[20]; // ����ţ�����
int n, w;

void DP()
{
    run(i, 0, (1 << n) - 1) // ö��״̬
        run(j, 1, n) // ö��ţ
            {
                int t = 1 << (j - 1);
                if(i & t) // ţ���Ѿ�������
                    continue;
                if(g[i] >= a[j] && dp[i | t] >= dp[i]) // ţ�ܷŽ�ʣ��ռ�
                {
                    dp[i | t] = dp[i];
                    g[i | t] = max(g[i | t], g[i] - a[j]); // ��ԭ�ȱȽ���Ϊ�˽�һ���Ż����ݿռ�
                }
                else if(g[i] < a[j] && dp[i | t] >= dp[i] + 1) // ţ�Ų���
                {
                    dp[i | t] = dp[i] + 1;
                    g[i | t] = max(g[i | t], w - a[j]);
                }
            }
}

void solve()
{
    cin >> n >> w;
    run(i, 1, n)
        cin >> a[i];
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 1, g[0] = w;
    DP();
    cout << dp[(1 << n) - 1];
}

int main() // https://www.luogu.com.cn/problem/P3052
{
    speed
//    t()
    solve();
    return 0;
}
