/**

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1

Example 2:

Input: [2,2,2,0,1]
Output: 0

Note:

    This is a follow up problem to Find Minimum in Rotated Sorted Array.
    Would allow duplicates affect the run-time complexity? How and why?



*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        int elem_mid;
        while (low <= high) {
            int elem_low = nums.at(low);
            int elem_high = nums.at(high);
            mid = (low + high) / 2;
            elem_mid = nums.at(mid);
            // cout << "elem low = " << elem_low << endl;
            // cout << "elem high = " << elem_high << endl;
            // cout << "elem mid = " << elem_mid << endl;
            if (elem_mid < elem_high) {
                high = mid;
            }
            else if (elem_mid > elem_high) {
                low = mid + 1;
            }
            else {
                high -= 1;
            }
        }
        return elem_mid;
    }
};
