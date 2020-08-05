/**
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

Note:
You may assume that all words are consist of lowercase letters a-z.

**/

class WordDictionary {
public:
    
    /** Initialize your data structure here. */
    WordDictionary() {
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary* wd = this;
        for (char ch : word) {
            ch -= 'a';
            if (!wd->next[ch]) {
                wd->next[ch] = new WordDictionary();
            }
            wd = wd->next[ch];
        }
        wd->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word.c_str(), this);
    }
    
private:
    WordDictionary* next[26] = {};
    bool isWord = false;
    bool search(const char* word, WordDictionary* node) {
        for (int i = 0; word[i] && node; i++) {
            if (word[i] != '.') {
                node = node -> next[word[i] - 'a'];
            } else {
                WordDictionary* tmp = node;
                for (int j = 0; j < 26; j++) {
                    node = tmp -> next[j];
                    if (search(word + i + 1, node)) {
                        return true;
                    }
                }
            }
        }
        return node && node -> isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
