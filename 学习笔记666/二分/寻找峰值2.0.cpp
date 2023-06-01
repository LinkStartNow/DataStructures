#include<bits/stdc++.h>

//#define int __int128
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
//#define t() int t; cin >> t; while(t --)
#define ms(i) memset(i, 0, sizeof(i))
#define ll long long

using namespace std;
const int N = 3e3 + 7;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r)
        {
            int m = (l + r) >> 1;
            if(nums[m] > nums[m + 1])
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
}; //https://leetcode.cn/leetbook/read/binary-search/xem7js/
void solve()
{

}
int main()
{
    solve();
    return 0;
}