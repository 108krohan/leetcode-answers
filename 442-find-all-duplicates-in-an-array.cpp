/**

Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]

**/

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        fastIO
        vector<int> result;
        for(int i = 0 ; i < nums.size();i++)
        {
            int orig = nums[i] < 0 ? -1 * nums[i] : nums[i];
            if(nums[orig - 1] < 0) //seen before
            {
                result.push_back(orig);
            }
            else
            {
                nums[orig - 1] = -nums[orig - 1];
            }
        }
        return result;
    }
};
