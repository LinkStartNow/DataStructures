#include<bits/stdc++.h>
using namespace std;
const int p = 2147483648;
long long dp[5000];
int main()
{
    int T;
    cin >> T;
    while(T --)
    {
        int n;
        memset(dp, 0, sizeof(dp));
        scanf("%d", &n);
        dp[0] = 1;
        for(int i = 1; i < n; i ++)
        {
            for(int j = i; j <= n; j ++)
            {
                dp[j] += dp[j - i];
                dp[j] %= p;
            }
        }
        printf("%lld\n", dp[n]);
    }
}
