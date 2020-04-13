Given an array A of non-negative integers, return the maximum sum of elements in two non-overlapping (contiguous) subarrays, which have lengths L and M.  (For clarification, the L-length subarray could occur before or after the M-length subarray.)

Formally, return the largest V for which V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) and either:

    0 <= i < i + L - 1 < j < j + M - 1 < A.length, or
    0 <= j < j + M - 1 < i < i + L - 1 < A.length.

 

Example 1:

Input: A = [0,6,5,2,2,5,1,9,4], L = 1, M = 2
Output: 20
Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.

Example 2:

Input: A = [3,8,1,3,2,1,8,9,0], L = 3, M = 2
Output: 29
Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.

Example 3:

Input: A = [2,1,5,6,0,9,5,0,3,8], L = 4, M = 3
Output: 31
Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [3,8] with length 3.

 

Note:

    L >= 1
    M >= 1
    L + M <= A.length <= 1000
    0 <= A[i] <= 1000

class Solution {
public:
    int calc_sum(vector<int> values, int K) {
        // cout << endl << "K = " << K << ": ";
        // for(int value: values) {
        //     cout << " " << value;
        // }
        // cout << endl;
        if(K > values.size()) {
            // cout << "K = " << K << ": returns: " << 0 << endl;
            return 0;
        }
        int result = 0;
        for(int i = 0; i < K; i++) {
            result += values.at(i);
        }
        int ans = result;
        for(int i = K; i < values.size(); i++) {
            // either keep 1st, or discard 1st
            // either keep K, or don't keep K
            result = result 
                            - values.at(i - K) 
                            + values.at(i);
            ans = max(ans, result);
        }
        // cout << "K = " << K << ": returns: " << result << endl;
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int max_sum = INT_MIN; 
        for(int i = min(L, M); i < A.size() - min(L, M); i++) {
            int curr_sum_L_M = calc_sum(vector<int>(A.begin(), A.begin() + i), L)
                + calc_sum(vector<int>(A.begin() + i, A.end()), M);
            int curr_sum_M_L = calc_sum(vector<int>(A.begin(), A.begin() + i), M) 
                + calc_sum(vector<int>(A.begin() + i, A.end()), L);
            // cout << "curr_sum_L_M, i = " << i << " | " << curr_sum_L_M << endl;
            // cout << "curr_sum_M_L, i = " << i << " | " << curr_sum_M_L << endl;
            int curr_max = max(curr_sum_L_M, curr_sum_M_L); 
            max_sum = max(max_sum, curr_max);             
        }
        return max_sum;
    }
};
