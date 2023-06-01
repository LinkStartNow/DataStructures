#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size(), m = nums2.size();
        int a, b;
        if(n > m)
            return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = n;
        int k = (n + m + 1) >> 1;
        int li, ri, lj, rj;
        while(l <= r)
        {
            int i = (l + r) >> 1;
            int j = k - i;
            li = i == 0 ? INT_MIN : nums1[i - 1];
            ri = i == n ? INT_MAX : nums1[i];
            lj = j == 0 ? INT_MIN : nums2[j - 1];
            rj = j == m ? INT_MAX : nums2[j];
            if(li > rj)
                r = i - 1;
            else
            {
                l = i + 1;
                a = max(li, lj), b = min(ri, rj);
            }
        }
        return (n + m) % 2 == 0 ? (a + b) / 2.0 : a;
    }
}; //https://leetcode.cn/problems/median-of-two-sorted-arrays/
int main()
{
    Solution s;
    vector<int>n1, n2;
    n2.push_back(1);
    n2.push_back(3);
    n1.push_back(2);
    cout << s.findMedianSortedArrays(n1, n2);
}
