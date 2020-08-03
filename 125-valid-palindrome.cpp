/**

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:

Input: "race a car"
Output: false

Constraints:

    s consists only of printable ASCII characters.

**/


class Solution {
public:
    
    char sanitize(char ch) {
        if ((ch >= '0' && ch <= '9')
           || (ch >= 'a' && ch <= 'z')) {
            return ch;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            return tolower(ch);
        }
        else {
            return '#';
        }
    }
    
    bool isPalindrome(string s) {
        bool result;
        int start = 0;
        int end = s.size() - 1;
        while (start <= end) {
            char left = sanitize(s.at(start));
            char right = sanitize(s.at(end));
            // cout << "comparing: " << left << " | " << right << endl;
            if (left == '#' || right == '#') {
                if (left == '#') {
                    start += 1;
                }
                if (right == '#') {
                    end -= 1;
                }
                continue;
            }
            if (left == right) {
                start += 1;
                end -= 1;
            }
            else {
                return false;
            }
        }
        return true;
    }
    
//     bool checkPalindrome(string s) {
//         if (s.size() <= 1) {
//             return true;
//         }
//         return s.at(0) == s.at(s.size() - 1) 
//                 && checkPalindrome(s.substr(1, s.size() - 2));
//     }
    
//     bool isPalindrome(string s) {
//         bool result;
//         string onlyNumAndWords = "";
//         for (int i = 0; i < s.size(); i++) {
//             if (s.at(i) >= '0' && s.at(i) <= '9') {
//                 // it's a number.
//                 onlyNumAndWords += s.at(i);
//             }
//             else if (s.at(i) >= 'A' && s.at(i) <= 'Z') {
//                 onlyNumAndWords += tolower(s.at(i));
//             }
//             else if (s.at(i) >= 'a' && s.at(i) <= 'z') {
//                 onlyNumAndWords += s.at(i);
//             }
//         }
//         // cout << "only num: " << onlyNumAndWords;
//         return checkPalindrome(onlyNumAndWords);
// }
};
