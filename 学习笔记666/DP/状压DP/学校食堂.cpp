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
#define speed ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

const ll N = 1007;
int n, t[N], b[N];
ll dp[1007][256][23];

void DP()
{
    run(i, 1, n)
    run(j, 0, (1 << 8) - 1)
    run(k, -8, 7)
    if(dp[i][j][k + 8] != 0x7f7f7f) // û�����¹���ֵ�Ͳ���ȥ��������ֵ�ˣ���Լʱ��
    {
        if(j & 1) // ��i�����ȳԿ���ֱ���������µ�i+1����ͬʱҲ��Ψһ;��
            dp[i + 1][j >> 1][k + 7] = min(dp[i + 1][j >> 1][k + 7], dp[i][j][k + 8]);
        else
        {
            ll r = 1e12;
            run(l, 0, 7)
            {
                if(!((j >> l) & 1)) // һ��Ҫ���жϣ�����Թ������ֳ��˷�ʱ��
                {
                    if(i + l > r)
                        break;
                    r = min(r, i + l + b[i + l]);
                    dp[i][j | (1 << l)][l + 8] = min(dp[i][j | (1 << l)][l + 8], dp[i][j][k + 8] + (i + k ? (t[i + l] ^ t[i + k]) : 0)); // ��һ���˲���Ҫʱ��
                }
            }
        }
    }
}

void solve()
{
    cin >> n;
    run(i, 1, n)
    cin >> t[i] >> b[i];
    memset(dp, 0x7f7f7f, sizeof(dp)); // ��ʼ����ֵһ��Ҫ��
    dp[1][0][7] = 0;
    DP();
    ll ans = 1e12;
    run(i, 0, 8)
    ans = min(ans, dp[n + 1][0][i]); // ��n+1��ǰ����Ѱ��˭�����õ�������
    cout << ans << '\n';
}

int main() // https://www.luogu.com.cn/problem/P2157
{
    speed
    t()
    solve();
    return 0;
}
