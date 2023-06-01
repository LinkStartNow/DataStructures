#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define run(i, a, b) for(int i = a; i <= b; i ++)
const int N = 307;
int s[N], a[N];
int dp[N][N];
int main()
{
    memset(dp, 0x3f, sizeof dp);
    int n;
    cin >> n;
    run(i, 1, n)
    {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    run(i, 1, n)
        dp[i][i] = 0;
    run(len, 2, n)
    {
        run(l, 1, n - len + 1)
        {
            int r = l + len - 1;
            run(k, l, r - 1)
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
            dp[l][r] += s[r] - s[l - 1];
        }
    }
    cout << dp[1][n] << endl;
}
