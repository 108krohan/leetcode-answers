/*

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

*/

class Solution {
public:
    int longestPalindrome(string s) {
        int result = 0;
        map<char, int> freq;
        for (int i = 0; i < s.size(); i++) {
            freq[s.at(i)] += 1;
        }
        // for (auto it = freq.begin(); it != freq.end(); it++) {
        //     cout << "key: " << it->first << " value: " << it->second << endl;
        // }
        bool hasOdds = false;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            if (it->second % 2 != 0) {
                hasOdds = true;
            }
            result += ((it->second / 2) * 2);
        }
        if (hasOdds) {
            result += 1;
        }
        return result;
    }
};
