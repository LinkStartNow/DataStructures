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
char s[N], t[N]; // ��¼���ַ���
int nxt[N]; // ��¼��iλ��ǰ׺�������ǰ��׺

void getnext()
{
    int l = strlen(t + 1), j = 0;
    nxt[1] = 0; // ����nxt�Ķ��岻����ԭ�����ȣ���Ȼ�����壩����һ���ַ�ֻ����0
    run(i, 2, l)
    {
        while(j && t[j + 1] != t[i]) j = nxt[j]; // ��jλ����һ�ε�iλ��ƥ��ģ�����j+1λ�ǳ���ȥ����һ�ε�iȥƥ��
        // ֱ��jƥ�䵽0���߳���ƥ��ɹ�Ϊֹ
        if(t[j + 1] == t[i]) j ++; // ���ڲ�֪�������whileѭ������ʲô��ֹ�������ж�һ�£��������Ϊƥ��ɹ�����ֹ�������ǰ��׺���Լӳ�
        nxt[i] = j;
//        nxt[i] = j += s[j + 1] == s[i];
        // ��Ƥһ�£�������������
    }
}

void kmp() // ������getnext����һģһ��
{
    int l = strlen(s + 1), lt = strlen(t + 1), j = 0;
    run(i, 1, l)
    {
        while(j && t[j + 1] != s[i]) j = nxt[j];
        if(t[j + 1] == s[i]) j ++;
        if(j == lt) // ��ƥ�䴮��ȫƥ�����ˣ����
        {
            cout << i - j + 1 << '\n';
            j = nxt[j]; // ������һ��ƥ�䣬Ҳ��һ���Ż���ֱ�ӻص�ͷҲû�£������е��˷�
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