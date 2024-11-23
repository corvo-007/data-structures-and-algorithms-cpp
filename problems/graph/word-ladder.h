#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

namespace Graph {
    int editDistance(std::string s1, std::string s2) {
        int d = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                d++;
            }
        }
        return d;
    }

    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList) {
        std::unordered_map<std::string*, std::vector<std::string*>> map;

        for (int i = 0; i < wordList.size(); i++) {
            int d = editDistance(beginWord, wordList[i]);
            if (d == 1) {
                map[&beginWord].push_back(&wordList[i]);
            }
        }

        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                int d = editDistance(wordList[i], wordList[j]);

                if (d == 1) {
                    map[&wordList[i]].push_back(&wordList[j]);
                    map[&wordList[j]].push_back(&wordList[i]);
                }
            }
        }

        int length = 1;

        std::unordered_set<std::string*> visited;
        std::queue<std::string*> queue;
        queue.push(&beginWord);
        queue.push(nullptr);

        while (!queue.empty()) {
            std::string *front = queue.front();
            queue.pop();

            if (front == nullptr) {
                length++;
                if (!queue.empty()) {
                    queue.push(nullptr);
                }
                continue;
            }

            if (*front == endWord) {
                return length;
            }

            visited.insert(front);

            for (auto word : map[front]) {
                if (!visited.count(word)) {
                    queue.push(word);
                }
            }
        }

        return 0;
    }
}
