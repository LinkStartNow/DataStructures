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

void quick(int l, int r)
{
    if(l >= r) return; // l > rʱ��Χ�Ƿ�ֱ�ӽ�����l==rʱֻ��һ���㲻������
    int i = l, j = r, p = a[l + r >> 1]; // ��ѧ�Ż���ȡ�м�,���Ѿ�����������һ�εݹ�������൱��ֱ�Ӷ�����
    // ����һ��Ҫ�ǵ���һ��������¼��׼ֵ����Ȼһ�߻���׼ֵһ�߱�
    // ��ʵ�������̿��Կ���˫���������ԶԷ���صĹ��̣��ȴ��Լ���ش�ͷ����β����ͽ��ͣ�£��ȴ�������������ͽ��������ͽ���߱�׼ֵ����
    // ������û����ͽ�����ٻ�ͣ���м�ֵ��λ�ã��������м�ֵ��Է�������ͽ���������
    // �ڹ����м�ֵ��λ�ú�һֱ������������ ˫����ͷ����һ����չֹͣ����Ϊ˫������ı�����ԭ�ȵ��Լ��˻��ߴӵжԻ���������ͽ
    while(i <= j)
    {
        while(a[i] < p) i ++;
        while(a[j] > p) j --;
        // �����i��jһ���ܵ��Է�������б������ͣ�£�i��j����1�������
        if(i <= j) swap(a[i ++], a[j --]);
    }
    // ��ʱ��i��j���ֱ����˶Է��������i�ǵ�һ��Ԫ�أ�j�����һ��
    // i��jҪô���Ա�ӵ����Ҫô�м���˸�����׼ֵ��ȵ�ֵ�����Ա�ʱ������һ����˵��
    // ��һ����ʱ��i��jҲ���Կ�������Ԫ�غ�ĩԪ�أ�ֻ���������ֳ�������Ӫ���������м�е��Ǹ�ֵ�������ϸ�������ڵ��ڻ�С�ڵ���
    quick(l, j), quick(i, r);
}

void solve()
{
    cin >> n;
    run(i, 1, n) cin >> a[i];
    quick(1, n);
    run(i, 1, n) cout << a[i] << ' ';
}

int main() // https://www.luogu.com.cn/problem/P1177
{
    speed
//    t()
    solve();
    return 0;
}