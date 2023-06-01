#include<bits/stdc++.h>

#define ll long long
//#define lb long double
#define run(i, a, b) for(ll i = a; i <= b; i ++)
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

const ll N = 1e4 + 7;
int pri[N], tot;
bool vis[N];
char s[23];
int a[N];
ll p[15];

void ola() // 数据最大有1e8所以想直接处理出1e8以内的质数是不可能的，但可以退而求其次求出1e4的质数，判断到根号n还不能整除那便是质数了
{
    run(i, 2, N)
    {
        if(!vis[i])
            pri[++ tot] = i;
        run(j, 1, tot)
        {
            if(pri[j] * i > N)
                break;
            vis[pri[j] * i] = 1;
            if((i % pri[j]) == 0)
                break;
        }
    }
}

bool zhi(int x)
{
    if(x < 2) // 栽坑里了，0和1不是质数
        return 0;
    if(x <= N)
        return !vis[x];
    int t = sqrt(x);
    run(i, 1, tot)
        if(pri[i] > t)
            return 1;
        else if((x % pri[i]) == 0)
            return 0;
}

bool rrr(int x)
{
    return (x % 4 == 0 && x % 100 != 0) || (x % 400 == 0 && x % 3200 != 0);
}

int dfs(int dep, int num, bool r, bool d) // dep表示当前处理的是第dep位，num是处理到dep位前的数字大小，r是标记是否需要闰年，d是是否需要大月
{
    if(!dep) // dep为0了，所有数字都处理完了
    {
        // 处理年份
        if(num / 10000 == 0) // 年份不能为0
            return 0;
        if(r && !rrr(num / 10000)) // 判断闰年
            return 0;
        return zhi(num);
    }
    if(dep == 6)
    {
        // 处理完78位得到了日期，现在处理日期
        if(!zhi(num)) // 素数
            return 0;
        if(num > 31 || !num) // 日期不能为0也不能大于31
            return 0;
        if(num == 31) // 如果为31则必须是大月
            d = 1;
    }
    if(dep == 4)
    {
        // 处理月份
        int m = num / 100; // 先算出月份
        if((m == 2 || m == 4 || m == 6 || m == 9 || m == 11) && d) // 判断大月
            return 0;
        if(num > 1231 || !m || !zhi(num)) // 最大为12月31号
            return 0;
        if(m == 2)
            if(num % 100 > 29) // 二月不能大于29号
                return 0;
            else if(num % 100 == 29) // 标记闰年
                r = 1;
    }
    if(a[dep] != -1) // dep位已经被限定住了，直接处理下一位
        return dfs(dep - 1, p[8 - dep] * a[dep] + num, r, d);
    int res = 0;
    run(i, 0, 9) // 暴力枚举
        res += dfs(dep - 1, p[8 - dep] * i + num, r, d);
    return res;
}

void solve()
{
    ll k = 1;
    run(i, 0, 10)
        p[i] = k, k *= 10; // 预处理10的次方
    ola(); // 预处理素数
    int n;
    cin >> n;
    run(i, 1, n)
    {
        cin >> s + 1;
        run(j, 1, 8)
        if(s[j] == '-')
            a[j] = -1;
        else
            a[j] = s[j] - '0';
        cout << dfs(8, 0, 0, 0) << '\n';
    }
}

int main() // https://www.luogu.com.cn/problem/P5440
{
    speed
//    t()
    solve();
    return 0;
}
