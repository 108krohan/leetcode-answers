Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.



class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        // cout << "Input: " << endl;
        // for(int i = 0; i < grid.size(); i++) {
        //     for(int j = 0; j < grid.size(); j++) {
        //         cout << " " << grid.at(i).at(j);
        //     }
        //     cout << endl;
        // }
        vector<vector<int>> dp(grid.size(), vector<int>(grid.at(0).size(), 0));
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid.at(0).size(); j++) {
                if(i == 0 && j == 0) {
                    dp.at(i).at(j) = grid.at(0).at(0);
                }
                else if(i == 0) {
                    // j != 0
                    // first row, without first guy
                    dp.at(0).at(j) += dp.at(0).at(j - 1);
                    dp.at(0).at(j) += grid.at(0).at(j);
                }
                else if(j == 0) {
                    dp.at(i).at(0) += dp.at(i - 1).at(0);
                    dp.at(i).at(0) += grid.at(i).at(0);
                }
                else {
                    dp.at(i).at(j) = grid.at(i).at(j) 
                        + min(dp.at(i - 1).at(j), dp.at(i).at(j - 1));
                }
            }
        }
        // cout << "Memory " << endl;
        // for(int i = 0; i < dp.size(); i++) {
        //     for(int j = 0; j < dp.size(); j++) {
        //         cout << " " << dp.at(i).at(j);
        //     }
        //     cout << endl;
        // }
        // cout << "last " << dp.back().back();
        return dp.back().back();
        
    }
};
