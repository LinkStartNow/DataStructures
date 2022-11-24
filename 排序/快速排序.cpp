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
    if(l >= r) return; // l > r时范围非法直接结束，l==r时只有一个点不用排序
    int i = l, j = r, p = a[l + r >> 1]; // 玄学优化，取中间,若已经排完序则下一次递归的区间相当于直接二分了
    // 这里一定要记得用一个变量记录标准值，不然一边换标准值一边变
    // 其实整个过程可以看做双方互相侵略对方领地的过程，先从自己领地从头看到尾有叛徒则停下，等待交出己方的叛徒与对面的叛徒或者标准值交换
    // 若己方没有叛徒则至少会停在中间值的位置，尝试用中间值与对方交换叛徒来扩充领地
    // 在过了中间值的位置后都一直在扩充领土， 双方碰头的那一刻扩展停止，因为双方领袖的背后都是原先的自己人或者从敌对换过来的叛徒
    while(i <= j)
    {
        while(a[i] < p) i ++;
        while(a[j] > p) j --;
        // 这里的i和j一旦跑到对方的领地中便会马上停下，i和j最多差1擦肩而过
        if(i <= j) swap(a[i ++], a[j --]);
    }
    // 此时的i和j都分别闯入了对方的领地且i是第一个元素，j是最后一个
    // i和j要么背对背拥抱，要么中间夹了个跟标准值相等的值，背对背时满足上一行所说的
    // 夹一个数时，i和j也可以看做是首元素和末元素，只不过两个分出来的阵营都不包括中间夹的那个值，但都严格满足大于等于或小于等于
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