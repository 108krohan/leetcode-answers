/*

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
