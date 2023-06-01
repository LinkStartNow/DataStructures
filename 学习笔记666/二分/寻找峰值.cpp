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
        int len = nums.size();
        if(len == 1)
            return 0;
        if(nums[0] > nums[1])
            return 0;
        if(nums[len - 1] > nums[len - 2])
            return len - 1;
        int l = 1, r = len - 2;
        while(l <= r)
        {
            int m = (l + r) >> 1;
            if(nums[m] < nums[m + 1])
                l = m + 1;
            else if(nums[m] < nums[m - 1])
                r = m - 1;
            else
                return m;
        }
        return 0;
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
