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

const int N = 1, p = 1e9 + 7;

char s[5050], t[1010];
int dp[1010][5050];
int l, lt;
int main()
{
    while(scanf("%s%s", s + 1, t + 1) != EOF)
    {
        l = strlen(s + 1), lt = strlen(t + 1);
        ms(dp);
        run(i, 1, lt)
            run(j, 1, l)
            {
                if(s[j] == t[i])
                {
                    if(i == 1)
                    {
                        dp[i][j] = (dp[i][j - 1] + 1) % p;
                    }
                    else
                    {
                        dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]) % p;
                    }
                }
                else
                    dp[i][j] = dp[i][j - 1];
            }
        printf("%d\n", dp[lt][l]);
    }
}
