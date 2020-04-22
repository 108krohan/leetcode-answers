/*

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2

Note:

    The length of the array is in range [1, 20,000].
    The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

*/

class Solution {
public:
    // The idea behind this approach is as follows: If the cumulative sum(repreesnted by sum[i]sum[i]sum[i] for sum upto ithi^{th}ith index) upto two indices is the same, the sum of the elements lying in between those indices is zero. Extending the same thought further, if the cumulative sum upto two indices, say iii and jjj is at a difference of kkk i.e. if sum[i]−sum[j]=ksum[i] - sum[j] = ksum[i]−sum[j]=k, the sum of elements lying between indices iii and jjj is kkk.
    int subarraySum(vector<int>& nums, int k) {
        // map of <sum at ith position, occurences of the sum>
        unordered_map<int,int> m;
        m[0]=1;
        int sum=0,res=0;
        for(auto& number:nums){
            sum += number;
            // cout << "m[sum - k] " << m[sum - k] << " sum = " << sum << endl;
            res += m[sum-k];
            m[sum]++;
        }
        return res;
    }
};
