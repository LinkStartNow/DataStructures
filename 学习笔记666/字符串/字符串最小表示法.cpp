#include<bits/stdc++.h>
#define run(i, a, b) for(long long i = a; i <= b; i ++)
#define ll long long
#define m(l, r) mid = (l + r) >> 1
using namespace std;
const int N = 1e7 + 5;
int n;
int s[2 * N];
int main()
{
    scanf("%d", &n);
    run(i, 1, n)
    {
        scanf("%d", &s[i]);
        s[i + n] = s[i];
    }
    int i = 1, j = 2, k = 0, ans = 0;
    while(i <= n && j <= n)
    {
        k = 0;
        while(k < n && s[i + k] == s[j + k])
            k ++;
        if(k == n)
            break;
        if(s[i + k] > s[j + k])
            i += k + 1;
        else
            j += k + 1;
        if(i == j)
            j ++;
    }
    ans = min(i, j);
    run(k, 1, n - 1)
     printf("%d ", s[ans + k - 1]);
    printf("%d", s[ans + n - 1]);
}
