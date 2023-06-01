#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(ll i = a; i <= b; i ++)
#define rep(i, a, b) for(ll i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>

using namespace std;

const int N = 1007;

int n, m;
int dp[N];
struct yyds
{
    int w, v;
};
vector<yyds> v[N];
int k;
void DP()
{
    run(i, 1, k)
    {
        rep(j, m, 0) //先枚举容量后枚举组内物品，避免一组取多个
        {
            for(const auto &it:v[i])
            {
                int wei = it.w, val = it.v;
                if(j >= wei)
                    dp[j] = max(dp[j], dp[j - wei] + val);
            }
        }
    }
}
int main()
{
    int a, b, c;
    cin >> m >> n;
    run(i, 1, n)
    {
        scanf("%d%d%d", &a, &b, &c);
        v[c].push_back(yyds{a, b});
        k = max(k, c);
    }
    DP();
    cout << dp[m] << endl;
}
