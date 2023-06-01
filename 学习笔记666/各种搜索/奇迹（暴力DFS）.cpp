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

void ola() // ���������1e8������ֱ�Ӵ����1e8���ڵ������ǲ����ܵģ��������˶���������1e4���������жϵ�����n�����������Ǳ���������
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
    if(x < 2) // �Կ����ˣ�0��1��������
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

int dfs(int dep, int num, bool r, bool d) // dep��ʾ��ǰ������ǵ�depλ��num�Ǵ���depλǰ�����ִ�С��r�Ǳ���Ƿ���Ҫ���꣬d���Ƿ���Ҫ����
{
    if(!dep) // depΪ0�ˣ��������ֶ���������
    {
        // �������
        if(num / 10000 == 0) // ��ݲ���Ϊ0
            return 0;
        if(r && !rrr(num / 10000)) // �ж�����
            return 0;
        return zhi(num);
    }
    if(dep == 6)
    {
        // ������78λ�õ������ڣ����ڴ�������
        if(!zhi(num)) // ����
            return 0;
        if(num > 31 || !num) // ���ڲ���Ϊ0Ҳ���ܴ���31
            return 0;
        if(num == 31) // ���Ϊ31������Ǵ���
            d = 1;
    }
    if(dep == 4)
    {
        // �����·�
        int m = num / 100; // ������·�
        if((m == 2 || m == 4 || m == 6 || m == 9 || m == 11) && d) // �жϴ���
            return 0;
        if(num > 1231 || !m || !zhi(num)) // ���Ϊ12��31��
            return 0;
        if(m == 2)
            if(num % 100 > 29) // ���²��ܴ���29��
                return 0;
            else if(num % 100 == 29) // �������
                r = 1;
    }
    if(a[dep] != -1) // depλ�Ѿ����޶�ס�ˣ�ֱ�Ӵ�����һλ
        return dfs(dep - 1, p[8 - dep] * a[dep] + num, r, d);
    int res = 0;
    run(i, 0, 9) // ����ö��
        res += dfs(dep - 1, p[8 - dep] * i + num, r, d);
    return res;
}

void solve()
{
    ll k = 1;
    run(i, 0, 10)
        p[i] = k, k *= 10; // Ԥ����10�Ĵη�
    ola(); // Ԥ��������
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
