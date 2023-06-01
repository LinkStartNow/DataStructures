#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 水平翻转
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        // 主对角线翻转
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
int main()
{
    Solution s;
    vector<vector<int>>q;
    for(int i = 0; i <3; i ++)
    {
        vector<int>t;
        for(int j = 0; j < 3; j ++)
        {
            int n;
            cin >> n;
            t.push_back(n);
        }
        q.push_back(t);
    }
    s.rotate(q);
}
