#include<bits/stdc++.h>

#define ll long long
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

using namespace std;

const int N = 1e5 + 7;
int a[N], n;

void init()
{
    run(i, 2, n) // ֻ��һ������ʱ������������ֱ������
    {   
        int p = i;// p��������ǰ��λ�ã�����һ��һ��������
        while(p > 1 && a[p] > a[p >> 1]) swap(a[p], a[p >> 1]), p >>= 1; // p <= 1ʱ�Ͳ��ó����������ˣ���Ϊ�Ѿ������,���ܱȸ��״�Ҳ���������ϱ���ֱ���˳�
            // ������Լ��ĸ��׽ڵ����븸�׽�����������
            // ����ĸ��ӹ�ϵ�ܺ�ά��������*2������ӣ�*2+1���Ҷ��ӣ����Ҷ��ӳ���2���ܵõ�����
    }
}

void yyds()
{
    init(); // ��ʼ��������ʵ�ִ�С�������򣬹�ά��һ���󶥶�
    // ����˼����������ߣ�
        // 1.ά��һ���󶥶�
        // 2.���Ѷ���ֵ�����һλֵ����
        // 3.���ڽ�������һ��ֵ��λ�ò�һ������ȷ�ģ�ʣ�µĸ��ӹ�ϵ����û����ģ�������Ҫһ����������Ѱ�����ֵ����ȷλ��
        // ������Ҳ���Ǹ���һ��һ����ά��һ���󶥶ѣ�����������ص��ڶ���ȡ�����ֵ���ɣ�Ȼ��ѭ��������������λ�ö�������
        // �������ȫ���ź�����ˣ��ʵ�����ά����ʱ���ð��ź���ļ������ǽ���
    rep(i, n, 2)
    {
        swap(a[i], a[1]); // �տ�ʼ�ͼ���󶥶��Ѿ�ά�����ˣ�ֱ�Ӱ�����ֵ���ʱƥ���λ�ý���
        int p = 1;
        while(p < i) // ÿһ��ѭ����ʼ�Ͱ����ֵ��i��λ���ˣ�Ҳ����iλ�Ѿ��Ǵ�����ϵ��ˣ�����p������ʱ����i��������
        {
            int l = p << 1, r = p << 1 | 1; // ��������ȴ������Ҷ���
            if(l >= i) break; // ����ӵ�λ���Ѿ��Ǵ�������ˣ��Ҷ��Ӹ����ÿ���ֱ�ӽ���
            if(r >= i) // �Ҷ����Ѿ������ֻ꣬���ж�������ܷ񽻻�����
                if(a[p] < a[l]) swap(a[p], a[l]), p = l;
                else break;
            else // ���Ҷ��Ӷ���ȫ
            {
                if(a[l] < a[r]) l = r; // �жϳ����Ҷ����д�ĸ�ֵ�������
                if(a[p] < a[l]) swap(a[p], a[l]), p = l;
                else break;
            }
        }
    }
}

void solve() 
{
    cin >> n;
    run(i, 1, n) cin >> a[i];
    yyds();
    run(i, 1, n) cout << a[i] << ' ';
}

int main() // // https://www.luogu.com.cn/problem/P1177
{
    speed
//    t()
    solve();
    return 0;
}