Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    All inputs will be in lowercase.
    The order of your output does not matter.


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m; 
        vector<vector<string>> result;
        for(int i = 0; i < strs.size(); i++) {
            string s = strs.at(i); 
            sort(s.begin(), s.end());
            if(m.find(s) == m.end()) {
                m[s] = {strs.at(i)};
            }
            else {
                m[s].push_back(strs.at(i));            
            }
        }
        for(map<string, vector<string>>::iterator itr = m.begin(); itr != m.end();itr++) {
            result.push_back(itr->second);
        }
        return result;
    }
};
