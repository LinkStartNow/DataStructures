#include<bits/stdc++.h>
using namespace std;
const int p = 2147483648;
long long dp[5000], v[1005];
int main()
{
    int T;
    cin >> T;
    while(T --)
    {
        int n, m;
        memset(dp, 0, sizeof(dp));
        cin >> n >> m;
        for(int i = 1; i <= n; i ++)
            cin >> v[i];
        dp[0] = 1;
        for(int i = 1; i <= n; i ++)
        {
            for(int j = m; j >= v[i]; j --)
            {
                dp[j] += dp[j - v[i]];
                dp[j] %= p;
            }
        }
        printf("%lld\n", dp[m]);
    }
}
