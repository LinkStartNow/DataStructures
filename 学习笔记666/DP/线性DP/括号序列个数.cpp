#include<bits/stdc++.h>

#define ll long long
#define lb long double
#define run(i, a, b) for(int i = a; i <= b; i ++)
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

const ll N = 1e5 + 7, p = 1e9 + 7;
ll dp[207][207][207];
int na, nb;
char s[207];

ll DP()
{
    /* ����֪״̬������ */
    run(i, 0, nb)
        run(j, 0, i)
            run(k, 0, i)
            {
                if(!dp[i][j][k])
                    continue;
                int ssr = j + (s[j + 1] == '('); // �ж�a����һ���ǲ���������
                dp[i + 1][ssr][k + 1] = (dp[i + 1][ssr][k + 1] + dp[i][j][k]) % p; // �Ʋ���һλ�������ŵ�״̬
                ssr = j + (s[j + 1] == ')');
                if(k) // û�ж�����������˾Ͳ��ü��������ˣ���Ȼ���ǷǷ�����������
                    dp[i + 1][ssr][k - 1] = (dp[i + 1][ssr][k - 1] + dp[i][j][k]) % p; // �Ʋ���һλ�������ŵ�״̬
            }
    return dp[nb][na][0];
}

void solve()
{
    cin >> na >> nb >> s + 1;
    run(i, 0, nb)
    run(j, 0, na)
    run(k, 0, nb)
    dp[i][j][k] = 0; // �ֶ����㣬��ֹ��ʱ��
    dp[0][0][0] = 1;
    cout << DP() << '\n';
}

int main() // https://ac.nowcoder.com/acm/contest/33187/K
{
    speed
    t()
    solve();
    return 0;
}
