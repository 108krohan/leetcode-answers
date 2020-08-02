/**

Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

    All letters in this word are capitals, like "USA".
    All letters in this word are not capitals, like "leetcode".
    Only the first letter in this word is capital, like "Google".

Otherwise, we define that this word doesn't use capitals in a right way.

 

Example 1:

Input: "USA"
Output: True

 

Example 2:

Input: "FlaG"
Output: False

 

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.

**/

class Solution {
public:
    bool detectCapitalUse(string word) {
        string upper_case = word, lower_case = word;
        transform(word.begin(), word.end(), upper_case.begin(), 
                 [](unsigned char c){ return std::toupper(c); });
        transform(word.begin(), word.end(), lower_case.begin(), 
                 [](unsigned char c){ return std::tolower(c); });
        // cout << "Lower case: " << lower_case << endl;
        // cout << "Upper case: " << upper_case << endl;
        return word == upper_case 
            || word == lower_case
            || (isupper(word.at(0))
                && (lower_case.substr(1, lower_case.size() - 1) == word.substr(1, word.size() - 1)));
    }
};
