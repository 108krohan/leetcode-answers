/*

Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"

Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

 

Note:

    A word is defined as a sequence of non-space characters.
    Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
    You need to reduce multiple spaces between two words to a single space in the reversed string.

 

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.

*/


class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int start = s.length() - 1;
        int end = s.length();
        while(start >= 0) {
            if (s[start] == ' ') {
                if(start == end - 1) {
                    start -= 1;
                    end -= 1;
                }
                else {
                    int c = start + 1;
                    for(;c < end; c++) {
                        result += s[c];
                    }
                    result += " ";
                    end = start;
                    start -= 1;
                }
            }
            else {
                start -= 1;
            }
        }
        int c = 0;
        for(; c < end; c++) {
            result += s[c];
        }
        if(result.size() > 0 && result[result.size() - 1] == ' ') {
            result.pop_back();
        }
        return result;
    }
};
