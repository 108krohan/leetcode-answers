/**

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]

Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.

Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]

**/

class Solution {
public:
    
    vector<string> wordBreak(string s, vector<string>& w2) {
        unordered_map<int, vector<string>> memo {{s.size(), {""}}};
        unordered_set<string> wordDict(w2.begin(), w2.end());
        function<vector<string>(int)> sentences = [&](int i) {
            if (!memo.count(i))
                for (int j=i+1; j<=s.size(); j++)
                    if (wordDict.count(s.substr(i, j-i)))
                        for (string tail : sentences(j))
                            memo[i].push_back(s.substr(i, j-i) + (tail=="" ? "" : ' ' + tail));
            return memo[i];
        };
        return sentences(0);
    }
    
    // // time limit exceeded
    // // test case:
    // // "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    // // ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
    // void wordBreaker(string s, vector<string>& wordDict, 
    //                  string one_result, vector<string> &result) {
    //     if (s.empty()) {
    //         result.push_back(one_result);
    //     }
    //     else {
    //         // cout << "s = " << s << endl;
    //         for (auto word: wordDict) {
    //             if(s.rfind(word, 0) == 0) {
    //                 // s begins with word
    //                 wordBreaker(s.substr(word.size()), wordDict, one_result + " " + word, result);
    //             }
    //         }            
    //     }
    // }
    // vector<string> wordBreak(string s, vector<string>& wordDict) {
    //     // https://stackoverflow.com/questions/1878001/how-do-i-check-if-a-c-stdstring-starts-with-a-certain-string-and-convert-a
    //     vector<string> result;
    //     string one_result;
    //     for (auto word: wordDict) {
    //         if(s.rfind(word, 0) == 0) {
    //             // the word starts the string
    //             one_result = word;
    //             wordBreaker(s.substr(word.size()), wordDict, one_result, result);
    //         }
    //     }
    //     return result;
    // }
};
