#include<bits/stdc++.h>
#define run(i, a, b) for(long long i = a; i <= b; i ++)
#define ll long long
#define m(l, r) mid = (l + r) >> 1
using namespace std;
const int N = 1e6 + 5;
int nxt[N];
char t[N];
int lt;
ll ans;
void getnext()
{
    int j = 0;
    nxt[1] = 0;
    run(i, 2, lt)
    {
        while(j && t[j + 1] != t[i])
            j = nxt[j];
        if(t[j + 1] == t[i])
            j ++;
        nxt[i] = j;
    }
}
void kmp()
{
    run(i, 2, lt)
    {
        int j = i;
        while(nxt[j])
            j = nxt[j];
        if(nxt[i])
            nxt[i] = j;
        ans += i - j;
    }
}
int main()
{
    scanf("%d", &lt);
    scanf("%s", t + 1);
    getnext();
    kmp();
    printf("%lld\n", ans);
}
