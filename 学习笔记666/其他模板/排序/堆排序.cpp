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
    run(i, 2, n) // 只有一个数的时候不用排序所以直接跳过
    {   
        int p = i;// p用来代表当前的位置，方便一步一步往上跳
        while(p > 1 && a[p] > a[p >> 1]) swap(a[p], a[p >> 1]), p >>= 1; // p <= 1时就不用尝试往上跳了，因为已经最高了,不能比父亲大也不用再往上比了直接退出
            // 如果比自己的父亲节点大就与父亲交换并往上跳
            // 这里的父子关系很好维护，父亲*2是左儿子，*2+1是右儿子，左右儿子除以2便能得到父亲
    }
}

void yyds()
{
    init(); // 初始化，由于实现从小到大排序，故维护一个大顶堆
    // 总体思想就是三步走：
        // 1.维护一个大顶堆
        // 2.将堆顶的值与最后一位值交换
        // 3.由于交换完后第一个值的位置不一定是正确的（剩下的父子关系都是没问题的），所以要一步步往下跳寻找这个值的正确位置
        // 第三步也就是跟第一步一样的维护一个大顶堆，走完第三步回到第二部取出最大值即可，然后循环往复，把所有位置都安排完
        // 后面的数全是排好序的了，故第三步维护的时候不用把排好序的继续考虑进来
    rep(i, n, 2)
    {
        swap(a[i], a[1]); // 刚开始就假设大顶堆已经维护好了，直接把最大的值与此时匹配的位置交换
        int p = 1;
        while(p < i) // 每一遍循环开始就把最大值和i换位置了，也就是i位已经是处理完毕的了，所有p往下跳时碰到i结束就行
        {
            int l = p << 1, r = p << 1 | 1; // 方便起见先处理处左右儿子
            if(l >= i) break; // 左儿子的位置已经是处理完的了，右儿子更不用考虑直接结束
            if(r >= i) // 右儿子已经处理完，只用判断左儿子能否交换即可
                if(a[p] < a[l]) swap(a[p], a[l]), p = l;
                else break;
            else // 左右儿子都齐全
            {
                if(a[l] < a[r]) l = r; // 判断出左右儿子中大的赋值给左儿子
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