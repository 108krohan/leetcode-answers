/*

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

    For example, "ace" is a subsequence of "abcde".

A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

 

Constraints:

    1 <= text1.length, text2.length <= 1000
    text1 and text2 consist of only lowercase English characters.


*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> sequences(
            text1.length() + 1, 
            vector<int>(text2.length() + 1, 0)
        );
        // we maintain a dp table such that column headers represent text1
        for (int indexText1 = 1; indexText1 <= text1.length(); indexText1++) {            
            // and row headers represent text2
            for (int indexText2 = 1; indexText2 <= text2.length(); indexText2++) {
                char t1 = text1[indexText1 - 1];
                char t2 = text2[indexText2 - 1];
                sequences[indexText1][indexText2]
                    = t1 == t2 ? 
                        1 + sequences[indexText1 - 1][indexText2 - 1]
                        : max(sequences[indexText1 - 1][indexText2],
                              sequences[indexText1][indexText2 - 1]);
                // cout << "sequences " << indexText1 << " " << indexText2 << " " << sequences[indexText1][indexText2] << endl;
            }
        }
        return sequences[text1.length()][text2.length()];
    }
};
