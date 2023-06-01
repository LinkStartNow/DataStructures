#include<bits/stdc++.h>

#define ll long long
#define lb long double
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);
//char buf[100000], *pa = buf, *pd = buf;
//#define gc pa == pd && (pd = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pd) ? EOF: *pa++

using namespace std;

const ll N = 1e6 + 7;
char s[N], t[N]; // 记录俩字符串
int nxt[N]; // 记录到i位的前缀的最长公共前后缀

void getnext()
{
    int l = strlen(t + 1), j = 0;
    nxt[1] = 0; // 由于nxt的定义不能是原创长度（不然无意义）于是一个字符只能是0
    run(i, 2, l)
    {
        while(j && t[j + 1] != t[i]) j = nxt[j]; // 第j位与上一次的i位是匹配的，所以j+1位是尝试去与这一次的i去匹配
        // 直到j匹配到0或者尝试匹配成功为止
        if(t[j + 1] == t[i]) j ++; // 由于不知道上面的while循环由于什么终止，所以判断一下，如果是因为匹配成功而终止则最长公共前后缀可以加长
        nxt[i] = j;
//        nxt[i] = j += s[j + 1] == s[i];
        // 调皮一下，可以缩减代码
    }
}

void kmp() // 几乎和getnext函数一模一样
{
    int l = strlen(s + 1), lt = strlen(t + 1), j = 0;
    run(i, 1, l)
    {
        while(j && t[j + 1] != s[i]) j = nxt[j];
        if(t[j + 1] == s[i]) j ++;
        if(j == lt) // 跟匹配串完全匹配上了，输出
        {
            cout << i - j + 1 << '\n';
            j = nxt[j]; // 尝试下一次匹配，也算一个优化，直接回到头也没事，就是有点浪费
        }
    }
}

void solve()
{
    cin >> s + 1 >> t + 1;
    getnext();
    kmp();
    run(i, 1, strlen(t + 1)) cout << nxt[i] << " \n"[i == strlen(t + 1)];
}


int main() // https://www.luogu.com.cn/problem/P3375
{
    speed
//    t()
    solve();
    return 0;
}