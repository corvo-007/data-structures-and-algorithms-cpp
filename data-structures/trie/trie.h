#include <string>
#include "../../common/trieNode.h"

class Trie {
    TrieNode *root;

public:
    Trie() {
        root = new TrieNode('\0');
    }

private:
    void insertWordRecursive(TrieNode *root, const std::string word) {
        if (word.length() == 0) {
            root -> isTerminal = true;
            return ;
        }

        int index = word[0] - 'a';

        if (!root -> children[index]) {
            root -> children[index] = new TrieNode(word[0]);
        }

        insertWordRecursive(root -> children[index], word.substr(1));
    }

    void insertWordRecursive_optimised(TrieNode *root, const std::string &word, int index) {
        if (index == word.length()) {
            root -> isTerminal = true;
            return ;
        }

        int i = word[index] - 'a';

        if (!root -> children[i]) {
            root -> children[i] = new TrieNode(word[index]);
        }
        
        insertWordRecursive_optimised(root -> children[i], word, index + 1);
    }

    bool searchWordRecursive(TrieNode *root, const std::string word) {
        if (word.length() == 0) {
            return root -> isTerminal;
        }

        int index = word[0] - 'a';

        return root -> children[index] && searchWordRecursive(root -> children[index], word.substr(1));
    }

    bool searchWordRecursive_optimised(TrieNode *root, const std::string &word, int index) {
        if (index == word.length()) {
            return root -> isTerminal;
        }

        int i = word[index] - 'a';

        return root -> children[i] && searchWordRecursive_optimised(root -> children[i], word, index + 1);
    }

    void removeWordRecursive(TrieNode *root, const std::string word) {
        if (word.length() == 0) {
            root -> isTerminal = false;
            return ;
        }

        int index = word[0] - 'a';

        if (!root -> children[index]) {
            return ;
        }

        removeWordRecursive(root -> children[index], word.substr(1));

        if (root -> children[index] -> isTerminal) {
            return ;
        }

        for (int i = 0; i < 26; i++) {
            if (root -> children[index] -> children[i]) {
                return ;
            }
        }

        delete root -> children[index];
        root -> children[index] = nullptr;
    }

    void removeWordRecursive_optimised(TrieNode *root, const std::string &word, int index) {

    }

public:
    void insertWordRecursive(const std::string word) {
        insertWordRecursive(root, word);
    }

    void insertWordRecursive_optimised(const std::string word) {
        insertWordRecursive_optimised(root, word, 0);
    }

    void insertWord(const std::string word) {
        TrieNode *curr = root;

        for (char c: word) {
            if (!curr -> children[c - 'a']) {
                curr -> children[c - 'a'] = new TrieNode(c);
            }
            curr = curr -> children[c - 'a'];
        }

        curr -> isTerminal = true;
    }

    bool searchWordRecursive(const std::string word) {
        return searchWordRecursive(root, word);
    }

    bool searchWordRecursive_optimised(const std::string word) {
        return searchWordRecursive_optimised(root, word, 0);
    }

    bool searchWord(const std::string word) {
        TrieNode *curr = root;

        for (char c: word) {
            if (!curr -> children[c - 'a']) {
                return false;
            }
            curr = curr -> children[c - 'a'];
        }

        return curr -> isTerminal;
    }

    void removeWordRecursive(const std::string word) {
        removeWordRecursive(root, word);
    }

    void removeWordRecursive_optimised(const std::string word) {
        removeWordRecursive_optimised(root, word, 0);
    }

    void removeWord(const std::string word) {

    }
};
