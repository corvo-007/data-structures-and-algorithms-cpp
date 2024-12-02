#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

namespace PriorityQueue {

    class Twitter {
        std::unordered_map<int, std::deque<std::pair<int, int>>> tweetMap;
        std::unordered_map<int, std::unordered_set<int>> followMap;
        int time;

    public:
        Twitter(): time(0) {

        }

        void postTweet(int userId, int tweetId) {
            tweetMap[userId].push_back({time, tweetId});
            if (tweetMap[userId].size() > 10) {
                tweetMap[userId].pop_front();
            }
            time++;
        }

        std::vector<int> getNewsFeed(int userId) {
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

            for (int i = 0; i < tweetMap[userId].size(); i++) {
                pq.push(tweetMap[userId][i]);
            }

            for (auto it = followMap[userId].begin(); it != followMap[userId].end(); it++) {
                for (int i = 0; i < tweetMap[*it].size(); i++) {
                    pq.push(tweetMap[*it][i]);
                    if (pq.size() > 10) {
                        pq.pop();
                    }
                }
            }

            std::vector<int> tweets(pq.size());
            while (!pq.empty()) {
                tweets[pq.size() - 1] = pq.top().second;
                pq.pop();
            }

            return tweets;
        }

        void follow(int followerId, int followeeId) {
            followMap[followerId].insert(followeeId);
        }

        void unfollow(int followerId, int followeeId) {
            followMap[followerId].erase(followeeId);
        }
    };
}