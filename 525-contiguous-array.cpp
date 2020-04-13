Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:

Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:

Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Note: The length of the given binary array will not exceed 50,000. 

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        // Use Map, int O(n) time and space
        // Idea is to check run_sum in map (where run_sum first reached that value)
        //      this means at that index, the run_sum reached that value
        //      so remove until that index to get the length of intermediate
        //      which sums to zero
        int max_len = 0; 
        map<int, int> m_score_index; 
        int run_sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums.at(i) == 1) {
                run_sum += 1;
            }
            else if(nums.at(i) == 0) {
                run_sum -= 1;
            }
            if(m_score_index.find(run_sum) != m_score_index.end()) {
                max_len = max(max_len, i - m_score_index[run_sum]);
            }
            else if(run_sum == 0) {
                max_len = max(max_len, i + 1);
            }
            else {
                m_score_index[run_sum] = i;
            }
        }
        return max_len;
        
        
//         TLE
//         int max_len = 0;
//         for(int i = 0; i < nums.size() - max_len; i++) {
//             int number = nums.at(i); 
//             int run_sum = 0;
//             for(int j = i; j < nums.size(); j++) {
//                 if(nums.at(j) == 0) {
//                     run_sum -= 1;
//                 }
//                 else {
//                     run_sum += 1; 
//                 }
//                 if(run_sum == 0 && max_len < j - i) {
//                     max_len = j - i + 1;
//                 }
//             }
//         }
//         return max_len;
    }
};
