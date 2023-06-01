#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005]; // a中长度为i，b中长度为j的最长公共子序列
char a[1005], b[1005];
void pri(int i, int j) // 用于打印最长公共子序列
{
    if(!i || !j)
        return;
    if(dp[i][j] == dp[i - 1][j])
        pri(i - 1, j);
    else if(dp[i][j] == dp[i][j - 1])
        pri(i, j - 1);
    else
    {
        pri(i - 1, j - 1);
        printf("%c",a[i - 1]);
    }
}
int main()
{
    scanf("%s%s", a, b);
    int na = strlen(a), nb = strlen(b);
    for(int i = 1; i <= na; i ++)
        for(int j = 1; j <= nb; j ++)
            if(a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    printf("%d\n", dp[na][nb]);
    pri(na, nb);
    puts("");
}