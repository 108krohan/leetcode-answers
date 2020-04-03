Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 

Note:

    There may be more than one LIS combination, it is only necessary for you to return the length.
    Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        if(nums.size() == 0) return 0;
        vector<int> dp;
        int result = 1;
        for(int i = 0; i < nums.size(); i++) {
            dp.push_back(1);
        }
        for(int i = 1; i < nums.size(); i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    result = max(result, dp[i]); 
                }
            }
        }
        return result;
    }
};
