/**

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

 

Constraints:

    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lower-case English letters.


**/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = -1; 
        bool end = false;
        while (!end) {
            index++;
            for(auto str: strs) {
                if (index >= str.length()) {
                    end = true;
                    break;
                }
                if (strs[0][index] != str[index]) {
                    return strs[0].substr(0, index);
                }
            }
        }
        // https://www.cplusplus.com/reference/string/string/substr/
        return strs[0].substr(0, index);
    }
};
