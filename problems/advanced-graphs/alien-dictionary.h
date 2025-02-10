#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

namespace AdvancedGraphs {
    void update_map(const std::string &s, std::unordered_map<char, std::unordered_set<char>> &map) {
        for (const char ch : s) {
            if (!map.count(ch)) {
                map[ch] = std::unordered_set<char>();
            }
        }
    }

    std::pair<char, char> firstDifferingChar(const std::string &s1, const std::string &s2) {
        int len = std::min(s1.length(), s2.length());

        for (int i = 0; i < len; i++) {
            if (s1[i] != s2[i]) {
                return { s1[i], s2[i] };
            }
        }

        return { '\0', '\0' };
    }

    std::string topologicalSort(const std::unordered_map<char, std::unordered_set<char>> &adjList) {
        std::unordered_map<char, int> inorder;

        for (auto &[ from_char, set ] : adjList) {
            if (!inorder.count(from_char)) {
                inorder[from_char] = 0;
            }

            for (const char &to_char : set) {
                inorder[to_char]++;
            }
        }

        std::queue<char> q;

        for (auto &[ ch, i ] : inorder) {
            if (i == 0) {
                q.push(ch);
            }
        }

        std::string output;

        while (!q.empty()) {
            char front = q.front();
            q.pop();

            output.push_back(front);

            for (const char &ch : adjList.at(front)) {
                inorder[ch]--;

                if (inorder[ch] == 0) {
                    q.push(ch);
                    inorder.erase(ch);
                }
            }
        }

        return output.size() == adjList.size() ? output : "";
    }

    std::string alienDictionary(const std::vector<std::string> &words) {
        if (words.size() == 1) {
            return words[0];
        }

        std::unordered_map<char, std::unordered_set<char>> adjList;

        for (int i = 0; i < words.size() - 1; i++) {
            update_map(words[i], adjList);
            update_map(words[i + 1], adjList);

            auto [ ch1, ch2 ] = firstDifferingChar(words[i], words[i + 1]);

            if (ch1 == '\0' && words[i].length() > words[i + 1].length()) {
                return "";
            }

            if (ch1 != '\0') {
                adjList[ch1].insert(ch2);
            }
        }

        return topologicalSort(adjList);
    }
}